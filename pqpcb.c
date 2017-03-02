#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "pqpcb_fileread.h" //header file for file reading 

clock_t start, end; //clock variables

//random integer generator
int identifier()
{
	int id;
	id = rand();
	return id;
}




#define size 6

int queue[6][2] = {0};

int top = -1;

int bottom;

// function for adding element into the priority queue
void push(int value, int pr)
{
	int i,j,k;

	if(top < size-1)

		{

			if(queue[top][1] < pr)

			{

				for(i=0;i<top;i++)

				{

					if(queue[i][1] < pr)

					{

						break;

					}

				}

			for(j=top;j>=i;j--)

			{

				queue[j+1][0] = queue[j][0];

				queue[j+1][1] = queue[j][1];

			}

			top++;

			queue[i][0] = value;

			queue[i][1] = pr;

			}

			else

			{

			top++;

			queue[top][0] = value;

			queue[top][1] = pr;

		}

	}

	else

	{

	printf("\nqueue overflow \n");

	}

}

//function for deleteing element from the priority queue
int pop()

{

	int i;
	int temp;

	if(queue[0][0] == 0)

	{

		printf("\n The queue is empty  \n");

	}

	else

	{

		temp = queue[0][0];
		
		for(i=0;i<top;i++)

		{

			queue[i][0] = queue[i+1][0];

			queue[i][1] = queue[i+1][1];

		}

		queue[top][0] = 0;

		queue[top][1] = 0;

		top--;

	}

	return temp;
}

//function to display elements in the queue
void display()

{ 
	int i,j;

	printf("Element\t\t\tPriority \n");

	for(i=size - 1;i>=0;i--)

	{

		for(j=0;j<2;j++)

		{

			printf(" %d\t",queue[i][j]);

		}

		printf("\n");

	}

}




void main()
{

	//assigning the process id through random integer generator
	process1.pid = identifier();
	process2.pid = identifier();
	process3.pid = identifier();
	process4.pid = identifier();
	process5.pid = identifier();
	process6.pid = identifier();

	//giving priority to the processes
	process1.priority = 20;  //system level process
	process2.priority = 15;
	process3.priority = 15;
	process4.priority = 14;
	process5.priority = 14;
	process6.priority = 13;

	strcpy(process1.priviledge, "System level");
	strcpy(process2.priviledge, "User level");
	strcpy(process3.priviledge, "User level");
	strcpy(process4.priviledge, "User level");
	strcpy(process5.priviledge, "User level");
	strcpy(process6.priviledge, "User level");

	//adding elements in the queue
	push(process1.pid,process1.priority);
	sleep(0.02);
	push(process2.pid,process2.priority);
	sleep(0.01);
	push(process3.pid,process3.priority);
	sleep(0.03);
	push(process4.pid,process4.priority);
	sleep(0.01);
	push(process5.pid,process5.priority);
	sleep(0.02);
	push(process6.pid,process6.priority);

	display();
/*	
	1804289383
	846930886
	1681692777
	1714636915
	1957747793
	424238335

*/

	start = clock();
	double cpu_time_used;
	int delp;
	//printf("%d\n%d\n%d\n%d\n%d\n%d\n",process1.pid,process2.pid,process3.pid,process4.pid,process5.pid,process6.pid);
	while(1)
	{
		if((process1.pc==1000000) & (process2.pc==1000000) & (process3.pc==1000000) & (process4.pc==1000000) & (process5.pc==1000000) & (process6.pc==1000000))
			break;
		
		fileread(queue[0][0]);
		delp = pop();
		
		if(delp==1804289383)
			push(delp,process1.priority);	
		if(delp==846930886)
			push(delp,process2.priority);
		if(delp==1681692777)
			push(delp,process3.priority);
		if(delp==1714636915)
			push(delp,process4.priority);		
		if(delp==1957747793)
			push(delp,process5.priority);
		if(delp==424238335)
			push(delp,process6.priority);

	}

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	process1.arrivalTime = 0.00;
	process2.arrivalTime = 0.02;
	process3.arrivalTime = 0.03;
	process4.arrivalTime = 0.06;
	process5.arrivalTime = 0.07;
	process6.arrivalTime = 0.09;

	process1.taTime = process1.finishTime - process1.arrivalTime;
	process1.waitTime = process1.finishTime - process1.execTime;

	process2.taTime = process2.finishTime - process2.arrivalTime;
	process2.waitTime = process2.finishTime - process2.execTime;

	process3.taTime = process3.finishTime - process3.arrivalTime;
	process3.waitTime = process3.finishTime - process3.execTime;

	process4.taTime = process4.finishTime - process4.arrivalTime;
	process4.waitTime = process4.finishTime - process4.execTime;

	process5.taTime = process5.finishTime - process5.arrivalTime;
	process5.waitTime = process5.finishTime - process5.execTime;

	process6.taTime = process6.finishTime - process6.arrivalTime;
	process6.waitTime = process6.finishTime - process6.execTime;

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

	printf("\nProcess 4\n");
	printf("------------------------------------------------------------------------");
	
	printf("\nProcess 4 arrival Time = %f\n",process4.arrivalTime);
	printf("\nProcess 4 total execution Time = %f\n",process4.execTime);
	printf("\nProcess 4 finish Time = %f\n",process4.finishTime);
	printf("\nProcess 4 turn around Time = %f\n",process4.taTime);
	printf("\nProcess 4 wait Time = %f\n",process4.waitTime);
	
	printf("\nProcess 5\n");
	printf("------------------------------------------------------------------------");
		
	printf("\nProcess 5 arrival Time = %f\n",process5.arrivalTime);
	printf("\nProcess 5 total execution Time = %f\n",process5.execTime);
	printf("\nProcess 5 finish Time = %f\n",process5.finishTime);
	printf("\nProcess 5 turn around Time = %f\n",process5.taTime);
	printf("\nProcess 5 wait Time = %f\n",process5.waitTime);

	printf("\nProcess 6\n");
	printf("------------------------------------------------------------------------");		
	
	printf("\nProcess 6 arrival Time = %f\n",process6.arrivalTime);
	printf("\nProcess 6 total execution Time = %f\n",process6.execTime);
	printf("\nProcess 6 finish Time = %f\n",process6.finishTime);
	printf("\nProcess 6 turn around Time = %f\n",process6.taTime);
	printf("\nProcess 6 wait Time = %f\n",process6.waitTime);



}


