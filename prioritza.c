#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<sys/types.h>
#include<unistd.h>

void green(){
  printf("\033[1;32m");
}

void blue(){
  printf("\033[1;34m");
}

int main(int argc, char *argv[]){
	struct sched_param scheduling_parameters;
	pid_t pid = atoi(argv[1]); //First argument PID
	//Priorities assignation
	blue();
	printf("Assign to himself an execution priority of 20 \n");
	int priority;
	scheduling_parameters.sched_priority = 20; //Priority assignation
	/*sched_setscheduler(pid_t pid, int policy, const struct sched_param *param);*/
	priority = sched_setscheduler(getpid(), SCHED_RR, &scheduling_parameters); //Policy assignation
	green();
	printf("OK 1, pid %d\n", getpid());

	blue();
	printf("Assign to his father (shell) an execution priority of 30 \n");
	int shell;
	scheduling_parameters.sched_priority = 30; //Priority assignation
	shell = sched_setscheduler(getppid(), SCHED_RR, &scheduling_parameters); //Policy assignation
	green();
	printf("OK 2, pid = %d\n", getppid());

	blue();
	printf("Assign to the parameter process an execution priority of 10 \n");
	int process_param;
	scheduling_parameters.sched_priority = 10; //Priority assignation
	process_param = sched_setscheduler(pid, SCHED_RR, &scheduling_parameters); //Policy assignation
	green();
	printf("OK 3, pid = %d\n", pid);

	exit (0);
}

