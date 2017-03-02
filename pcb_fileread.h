#include "PCB_structure.h"
#include <math.h>
//clock variables
clock_t start, end;
double cpu_time_used;
double clk_time1=0;
double clk_time2=0;
double clk_time3=0;

//making a logfile
void logfile()
{
	FILE *fptr;
	fptr=fopen("log.txt","a");
	fprintf(fptr,"\nProcess 1\n\npid = %d\nState = %s\nPriviledge = %s\n",process1.pid,process1.state,process1.priviledge);
	fprintf(fptr,"\nProcess 2\n\npid = %d\nState = %s\nPriviledge = %s\n",process2.pid,process2.state,process2.priviledge);
	fprintf(fptr,"\nProcess 3\n\npid = %d\nState = %s\nPriviledge = %s\n",process3.pid,process3.state,process3.priviledge);

	fclose(fptr);

}

//function to read the file tmp.txt
void file_read1()
{

	start = clock();
	int temp;
	process1.stat_info=fopen("tmp.txt","r"); //opening the file pointer for reading
	strcpy(process1.state,"Running");
	strcpy(process2.state, "Ready to run");
	strcpy(process3.state, "Ready to run");
	
	printf("\nProcess 1 is %s\n",process1.state);
	int last_seek = SEEK_CUR; //last accessed location is saved 
	fseek(process1.stat_info,0,last_seek); // finding the last accessed location in a file

	int tmp = process1.pc+100000;
	//printf("\n tmp = %d",tmp);

	for(int j=last_seek; j<tmp;j++)
	{
		fscanf(process1.stat_info,"%d",&temp); //reading from a file
	}
	process1.pc=temp;

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cpu_time_used = cpu_time_used - clk_time1;
	clk_time1 = fabs(cpu_time_used);
	printf("\nExecution time for this cycle = %f\n",clk_time1);
	process1.finishTime = process1.finishTime + clk_time1;

	if(process2.pc!=1000000)	
		process2.finishTime = process2.finishTime + clk_time1;	
	if(process3.pc!=1000000)
		process3.finishTime = process3.finishTime + clk_time1;	

	process2.waitTime = process2.waitTime + clk_time1;
	process3.waitTime = process3.waitTime + clk_time1;

	process1.execTime = process1.execTime + clk_time1;
	fclose(process1.stat_info); //closing of file pointer

	printf("\nPCB of process 1");
	printf("\n-----------------------------------------------------------");
	printf("\npid = %d",process1.pid);
	printf("\nState = %s",process1.state);
	printf("\nPriviledge = %s",process1.priviledge);
	//printf("\nPriority = %d",process1.priority);


	logfile();
}

void file_read2()
{
	start=clock();
	int temp;
	process2.stat_info=fopen("tmp.txt","r");//opening the file pointer for reading
	strcpy(process2.state,"Running");
	strcpy(process1.state, "Ready to run");
	strcpy(process3.state, "Ready to run");
	
	printf("\nProcess 2 is %s\n",process2.state);
	int last_seek = SEEK_CUR;//last accessed location is saved
	fseek(process2.stat_info,0,last_seek);// finding the last accessed location in a file

	int tmp = process2.pc+100000;
	//printf("\n tmp = %d",tmp);

	for(int j=last_seek; j<tmp;j++)
	{
		fscanf(process2.stat_info,"%d",&temp);
	}
	process2.pc=temp;
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cpu_time_used = cpu_time_used - clk_time2;
	clk_time2 =fabs(cpu_time_used);

	printf("\nExecution time for this cycle = %f\n",clk_time2);
        process2.finishTime = process1.finishTime + clk_time2;	
	if(process1.pc!=1000000)	
		process1.finishTime = process1.finishTime + clk_time1;	
	if(process3.pc!=1000000)
		process3.finishTime = process3.finishTime + clk_time1;	

	process1.waitTime = process1.waitTime + clk_time2;
	process3.waitTime = process3.waitTime + clk_time2;

	process2.execTime = process2.execTime + clk_time2;	

	printf("\nPCB of process 2");
	printf("\n-----------------------------------------------------------");
	printf("\npid = %d",process2.pid);
	printf("\nState = %s",process2.state);
	printf("\nPriviledge = %s",process2.priviledge);
	//printf("\nPriority = %d",process2.priority);

	fclose(process2.stat_info); //closing the file pointer
	logfile();
}

void file_read3()
{
	start=clock();
	int temp;
	process3.stat_info=fopen("tmp.txt","r"); //opening the file pointer for reading
	strcpy(process3.state,"Running");
	strcpy(process2.state, "Ready to run");
	strcpy(process1.state, "Ready to run");
	
	printf("\nProcess 3 is %s\n",process3.state);
	int last_seek = SEEK_CUR;//last accessed location is saved
	fseek(process3.stat_info,0,last_seek);// finding the last accessed location in a file
	int tmp = process3.pc+100000;
	//printf("\n tmp = %d",tmp);

	for(int j=last_seek; j<tmp;j++)
	{
		fscanf(process3.stat_info,"%d",&temp);
	}
	process3.pc=temp;
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cpu_time_used = cpu_time_used - clk_time3;
	clk_time3 =fabs(cpu_time_used);
	printf("\nExecution time for this cycle = %f\n",clk_time3);
        process3.finishTime = process1.finishTime + clk_time3;	
	if(process2.pc!=1000000)	
		process2.finishTime = process2.finishTime + clk_time1;	
	if(process1.pc!=1000000)
		process1.finishTime = process1.finishTime + clk_time1;	

	process1.waitTime = process1.waitTime + clk_time3;
	process2.waitTime = process2.waitTime + clk_time3;

	process3.execTime = process3.execTime + clk_time3;
	fclose(process3.stat_info); //closing the file pointer

	printf("\nPCB of process 3");
	printf("\n-----------------------------------------------------------");
	printf("\npid = %d",process3.pid);
	printf("\nState = %s",process3.state);
	printf("\nPriviledge = %s",process3.priviledge);
	//printf("\nPriority = %d",process3.priority);
			
	logfile();
}


void file_read(int val)
{

	if(val==1)
		file_read1();
	else if(val==2)
		file_read2();
	else if(val==3)
		file_read3();
	else{}

}



