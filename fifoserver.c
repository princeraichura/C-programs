#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define size 256

void toggleCase(char* buf,int cnt);

void main(){
	int srvFd;
	int cliFd;
	char buf[size];
	int cnt;

	while(1){
		prinf("waiting for client...\n");
		srvFd=open("srvfifo",O_RDONLY);

		if(srvFd<0){
			if(mkfifo("srvfifo",0600)<0){
				printf("error in creating fifo\n");
				return;
			}
		else{
				prinf("fifo is created\n");
				srvFd=open("srvfifo",O_RDONLY);
			}
		}
		printf("connected to client through fifo\n");
		while(1){
			cnt=read(srvFd,buf,size);
			if(cnt==0) break;
			printf("recieve message: %s",buf);
			toggleCase(buf,cnt);
			cliFd = open("clififo",O_WRONLY);

			if(cliFd){
				printf("send response message\n\n");
				write(cliFd,buf,cnt);
				close(cliFd);
			}
			else{
	        	printf("could nt connected to client fifo\n");
	    	}		
        }
		close(srvFd);
	}}
//to toggle captial to small and vice-versa
void toggleCase(char* buf,int cnt){
	for(int i=0;i<cnt;i++){
		if(buf[i]>='A' && buf[i]<='Z') 
            buf[i]+=0x20; //here A has ascii value 65 so it will increase it by 32 and make it 97 which is ascii value of a
		else if(buf[i]>='a' && buf[i]<='z')
            buf[i]-=0x20; // same but ooposite of above logic to decres it by 32
	}}