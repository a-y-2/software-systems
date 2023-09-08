/*
29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).

AYUSHI PRASAD
MT2023145
*/

#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<unistd.h>

int main(){
	pid_t pid = getpid();
	int policy;
	struct sched_param param;
	param.sched_priority=17;
	policy = sched_getscheduler(pid);
	printf("\n current policy : %d",policy);
	sched_setscheduler(pid,SCHED_FIFO,&param);
	policy = sched_getscheduler(pid);
	printf("\n after changing : %d",policy);
	return 0;
}
