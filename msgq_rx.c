#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

struct msgbuf{ 
	long mtype;
	char data[512];
};

void main(int argc, char** argv){
	int id;
	struct msgbuf v;

	if(argc!=2){
		printf("usage: ./mq_rx type \n");
		printf("example: mq_rx 5\n");
		return;
	}

	id=msgget(55,IPC_CREAT | 644);
	if(id < 0){
		perror("msgget");
		return;
	}
	msgrcv(id, &v, sizeof(v), atoi(argv[1]), 0);
	printf("data %s\n", v.data);
}