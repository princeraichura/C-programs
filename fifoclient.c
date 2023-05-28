#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define buff 256

void main(){
	int srvFd;
	int cliFd;
	char txmsg[buff];
	char rxmsg[buff];
	int count;
	
	while(1){
		srvFd=open("srvfifo",O_WRONLY);
		if(!srvFd){
			printf("error in opening server fifo\n");
			return(1);
		}	
		printf("connected to server...\n");
		printf("enter some message to sent to the server : ");
		fgets(txmsg,buff,stdin);

		write(srvFd,txmsg,strlen(txmsg)+1);
		printf("message sent to the server\n");
	
		cliFd=open("clififo",O_RDONLY);

		if(cliFd<0){
			if(mkfifo("clififo",0600)){
				printf("error in creating client fifo\n");
				return(1);
			}

			else{
				cliFd=open("clififo",O_RDONLY);
				printf("created client fifo\n");
			}
		}

		printf("waiting for response message from server\n");
		count = read(cliFd,rxmsg,buff);
		puts(rxmsg);
		close(srvFd);
		close(cliFd);
	}
}