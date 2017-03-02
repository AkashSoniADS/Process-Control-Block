#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "pcb_fileread.h"   //header file to read the file


clock_t start, end; //clock variable
 double cpu_time_used; //variable to store the difference between start and stop time
     
 //320512820 = 2 seconds    

//Random integer generator
int identifier()
{
	int id;
	id = rand();
	return id;
}

#define MAX 3
int queue_array[MAX]; //declaring an array for 3 processes
int rear = 0; //initializing variables
int front = 0; //initializing variables

//function to insert the value in the queue
void insert(int add_item)
{

	if(rear==(MAX))
		printf("\nQueue full\n");

	else
	{

		queue_array[rear]=add_item;
		rear++;
	}

}

//function to delete the element from the queue
int delete()
{
	int temp;
	if(front>rear)
		printf("\nQueue empty\n");

	temp=queue_array[front];
	rear--;
	for(int i=0;i<rear;i++)
	{
		queue_array[i]=queue_array[i+1];
	}

	//printf("\nDeleted %d",temp);
	return temp;
}
//displaying the queue
void display()
{
    int i;
    if (front > rear)
        printf("\nQueue is empty \n");
    else
    {
        printf("\nQueue is : \n");
        for (i = front; i < rear; i++)
	        printf("%d ", queue_array[i]);
        printf("\n");
    }
}


//child process creation
void fork_func()
{

	int cpid;

	child1 = process1;
	child1.pid = identifier();
	child1.ppid = process1.pid;
	printf("\nHello I am the child process.");
	printf("\nMy id is %d and my parent id is %d",child1.pid,child1.ppid);
	printf("\n Program Counter of child is %d",child1.pc);

	FILE *fptr;
	fptr=fopen("log.txt","a");
	fprintf(fptr,"\nChild id : %d \t Parent id of child : %d\n",child1.pid,child1.ppid);
	fclose(fptr);
}

//catching the signal interrupt ctrl+C 
void catchint(int signo)
{
	int del_temp=delete();
	insert(del_temp);
	if(del_temp==1)
	{
		strcpy(process1.state,"Blocked");
		printf("\nProcess 1 is blocked.\n");
	}

	else if(del_temp==2)
	{
		strcpy(process2.state,"Blocked");
		printf("\nProcess 2 is blocked.\n");
	}
	else if(del_temp==3)
	{
		strcpy(process3.state,"Blocked");
		printf("\nProcess 3 is blocked.\n");
	}

	else
	{
		printf("\nInterrupt found.\n");
	}
	logfile();

}

//main function
void main(){
	start=clock();
	// intializing the process id through random int generator without using the seed
	process1.pid = identifier();
	process1.ppid=0;
	process2.pid = identifier();
	process2.ppid=0;
	process3.pid = identifier();
	process3.ppid = 0;

	strcpy(process3.priviledge, "User level");
	strcpy(process2.priviledge, "User level");
	strcpy(process1.priviledge, "User level");

	printf("\nProcess 1 id : %d", process1.pid);
	printf("\nProcess 2 id : %d", process2.pid);
	printf("\nProcess 3 id : %d", process3.pid);

	//adding the three processes to the queue initially
	insert(1);
	
	sleep(0.02);
	insert(2);
	
	sleep(0.015);
	insert(3);
	
	display();

	int delp=0;


	int signo;

	static struct sigaction act;

	/* declare catchint, later to be used as the handler */
	void catchint(int);

	/* set up the action to be taken on receipt of SIGNINT */
	act.sa_handler = catchint;

	/*create a full mask */
	sigfillset(&(act.sa_mask));


	sigaction(SIGINT, &act, NULL);

	//Process runs until the file reading is not completed
	while(1)
	{

		if((process1.pc==1000000) & (process2.pc==1000000) & (process3.pc==1000000))
			break;
	
			file_read(queue_array[0]);
			delp =delete();
			insert(delp);
	}



	
	//printf("Process id = %d ", processid);
	//logfile();
	
	//creating a child
	fork_func();
	end = clock();
	cpu_time_used = 0;
	//Total time used
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	process1.arrivalTime = 0.00;
	process2.arrivalTime =  0.02;
	process3.arrivalTime = 0.035;

	process1.taTime = process1.finishTime - process1.arrivalTime;
	process1.waitTime = process1.finishTime - process1.execTime;

	process2.taTime = process2.finishTime - process2.arrivalTime;
	process2.waitTime = process2.finishTime - process2.execTime;

	process3.taTime = process3.finishTime - process3.execTime;
	process3.waitTime = process3.finishTime - process3.execTime;
	

	printf("\nProcess 1\n");
	printf("------------------------------------------------------------------------");
	
	printf("\nProcess 1 arrival Time = %f\n",process1.arrivalTime);
	printf("\nProcess 1 total execution Time = %f\n",process1.execTime);
	printf("\nProcess 1 finish Time = %f\n",process1.finishTime);
	printf("\nProcess 1 turn around Time = %f\n",process1.taTime);
	printf("\nProcess 1 wait Time = %f\n",process1.waitTime);
	
	printf("\nProcess 2\n");
	printf("------------------------------------------------------------------------");
		
	printf("\nProcess 2 arrival Time = %f\n",process2.arrivalTime);
	printf("\nProcess 2 total execution Time = %f\n",process2.execTime);
	printf("\nProcess 2 finish Time = %f\n",process2.finishTime);
	printf("\nProcess 2 turn around Time = %f\n",process2.taTime);
	printf("\nProcess 2 wait Time = %f\n",process2.waitTime);

	printf("\nProcess 3\n");
	printf("------------------------------------------------------------------------");		
	
	printf("\nProcess 3 arrival Time = %f\n",process3.arrivalTime);
	printf("\nProcess 3 total execution Time = %f\n",process3.execTime);
	printf("\nProcess 3 finish Time = %f\n",process3.finishTime);
	printf("\nProcess 3 turn around Time = %f\n",process3.taTime);
	printf("\nProcess 3 wait Time = %f\n",process3.waitTime);
}
