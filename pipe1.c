#include <stdio.h>

void main(){
	int pipe_fd[2];
	char rd_buf[100];
	char wr_buf[100];

	if(pipe(pipe_fd) < 0){
		perror("pipe is not created!\n");
		exit(1);
	}

	if(fork()==0){
		close(pipe_fd[1]);
		while(1){
			int n=read(pipe_fd[0],rd_buf,100);
			printf("read from pipe[0] and output to screen : \n");
			for(int i=0;i<n;i++)
					rd_buf[i] = toupper(rd_buf[i]);
			puts(rd_buf);
		}
	}
	close(pipe_fd[0]);
	while(1){
		printf("enter a string : \n");
		fgets(wr_buf,100,stdin);
		write(pipe_fd[1],wr_buf,strlen(wr_buf)+1);
		printf("data wrote to pipe[1]\n");
	}
}