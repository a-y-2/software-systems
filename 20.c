/*
20. Find out the priority of your running program. Modify the priority with nice command.

AYUSHI PRASAD
MT2023145
*/
#include<sys/types.h>
#include<fcntl.h>
#include<sys/resource.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(int argc,char* argv[]){
        int val;
        int pid = getpid();
        val = getpriority(PRIO_PROCESS,0);
        printf("\npid : %d , nice : %d\n",pid,val);
        getchar();
        nice(5);
        val = getpriority(PRIO_PROCESS,0);
        printf("\npid : %d , nice : %d\n",pid,val);
        while(1);
return 0;
}







