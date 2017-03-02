#include "PCB_structure.h"
clock_t start,end;


//generating the log file
void logfile()
{
	FILE *fptr;
	fptr=fopen("log2.txt","a");
	fprintf(fptr,"\nProcess 1\n\npid = %d\nState = %s\nPriviledge = %s\nPriority = %d\n",process1.pid,process1.state,process1.priviledge,process1.priority);
	fprintf(fptr,"\nProcess 2\n\npid = %d\nState = %s\nPriviledge = %s\nPriority = %d\n",process2.pid,process2.state,process2.priviledge,process2.priority);
	fprintf(fptr,"\nProcess 3\n\npid = %d\nState = %s\nPriviledge = %s\nPriority = %d\n",process3.pid,process3.state,process3.priviledge,process3.priority);
	fprintf(fptr,"\nProcess 4\n\npid = %d\nState = %s\nPriviledge = %s\nPriority = %d\n",process4.pid,process4.state,process4.priviledge,process4.priority);
	fprintf(fptr,"\nProcess 5\n\npid = %d\nState = %s\nPriviledge = %s\nPriority = %d\n",process5.pid,process5.state,process5.priviledge,process5.priority);
	fprintf(fptr,"\nProcess 6\n\npid = %d\nState = %s\nPriviledge = %s\nPriority = %d\n",process6.pid,process6.state,process6.priviledge,process6.priority);


	fclose(fptr);
}


//functions to read the test data file

void fileread1()
{	
	printf("\nReading file 1");
	double cpu_time_used;
	start = clock();
	int temp;
	process1.stat_info=fopen("tmp.txt","r"); //opening the file for reading
	strcpy(process1.state,"Running");
	strcpy(process2.state, "Ready to run");
	strcpy(process3.state, "Ready to run");
	strcpy(process4.state, "Ready to run");
	strcpy(process5.state, "Ready to run");
	strcpy(process6.state, "Ready to run");
	strcpy(process1.priviledge, "User level");
	printf("\nProcess 1 is %s",process1.state);		

	int last_seek = SEEK_CUR; //last accessed location is saved
	fseek(process1.stat_info,0,last_seek);//finding the last accessed location in a file

	int tmp = process1.pc+100000;
	//printf("\n tmp = %d",tmp);

	for(int j=last_seek; j<tmp;j++)
	{
		fscanf(process1.stat_info,"%d",&temp);
	}
	process1.pc=temp;

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nExecution time for this cycle = %f\n",cpu_time_used);
	
	process1.finishTime = process1.finishTime + cpu_time_used;

	if(process2.pc!=1000000)	
		process2.finishTime = process2.finishTime + cpu_time_used;
	if(process3.pc!=1000000)
		process3.finishTime = process3.finishTime + cpu_time_used;
	if(process4.pc!=1000000)
		process4.finishTime = process4.finishTime + cpu_time_used;	
	if(process5.pc!=1000000)
		process5.finishTime = process5.finishTime + cpu_time_used;	
	if(process6.pc!=1000000)
		process6.finishTime = process6.finishTime + cpu_time_used;	
/*
	process2.waitTime = process2.waitTime + cpu_time_used;
	process3.waitTime = process3.waitTime + cpu_time_used;
	process4.waitTime = process4.waitTime + cpu_time_used;
	process5.waitTime = process5.waitTime + cpu_time_used;
	process6.waitTime = process6.waitTime + cpu_time_used;
*/	
	process1.execTime = process1.execTime + cpu_time_used;

	printf("\nPCB of process 1");
	printf("\n-----------------------------------------------------------");
	printf("\npid = %d",process1.pid);
	printf("\nState = %s",process1.state);
	printf("\nPriviledge = %s",process1.priviledge);
	printf("\nPriority = %d",process1.priority);	
	
	fclose(process1.stat_info); //closing the file pointer
	logfile();

}

void fileread2()
{
	printf("\nReading file 2");
	double cpu_time_used;
	start = clock();
	int temp;
	process2.stat_info=fopen("tmp.txt","r");
	strcpy(process1.state, "Ready to run");
	strcpy(process2.state, "Running");
	strcpy(process3.state, "Ready to run");
	strcpy(process4.state, "Ready to run");
	strcpy(process5.state, "Ready to run");
	strcpy(process6.state, "Ready to run");
	strcpy(process2.priviledge, "User level");

	printf("\nProcess 2 is %s",process2.state);		

	int last_seek = SEEK_CUR;
	fseek(process2.stat_info,0,last_seek);

	int tmp = process2.pc+100000;
	//printf("\n tmp = %d",tmp);

	for(int j=last_seek; j<tmp;j++)
	{
		fscanf(process2.stat_info,"%d",&temp);
	}
	process2.pc=temp;

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	process2.finishTime = process2.finishTime + cpu_time_used;

	if(process1.pc!=1000000)	
		process1.finishTime = process1.finishTime + cpu_time_used;
	if(process3.pc!=1000000)
		process3.finishTime = process3.finishTime + cpu_time_used;
	if(process4.pc!=1000000)
		process4.finishTime = process4.finishTime + cpu_time_used;	
	if(process5.pc!=1000000)
		process5.finishTime = process5.finishTime + cpu_time_used;	
	if(process6.pc!=1000000)
		process6.finishTime = process6.finishTime + cpu_time_used;	

/*
	process1.waitTime = process1.waitTime + cpu_time_used;
	process3.waitTime = process3.waitTime + cpu_time_used;
	process4.waitTime = process4.waitTime + cpu_time_used;
	process5.waitTime = process5.waitTime + cpu_time_used;
	process6.waitTime = process6.waitTime + cpu_time_used;
*/	
	process2.execTime = process2.execTime + cpu_time_used;
	
	printf("\nExecution time for this cycle = %f\n",cpu_time_used);

	printf("\nPCB of process 2");
	printf("\n-----------------------------------------------------------");
	printf("\npid = %d",process2.pid);
	printf("\nState = %s",process2.state);
	printf("\nPriviledge = %s",process2.priviledge);
	printf("\nPriority = %d",process2.priority);

	fclose(process2.stat_info);		
	logfile();

}


void fileread3()
{
	printf("\nReading file 3");
	double cpu_time_used;
	start = clock();
	int temp;
	process3.stat_info=fopen("tmp.txt","r");
	strcpy(process1.state, "Ready to run");
	strcpy(process2.state, "Ready to run");
	strcpy(process3.state, "Running");
	strcpy(process4.state, "Ready to run");
	strcpy(process5.state, "Ready to run");
	strcpy(process6.state, "Ready to run");
	strcpy(process3.priviledge, "User level");

	printf("\nProcess 3 is %s",process3.state);		
	
	int last_seek = SEEK_CUR;
	fseek(process3.stat_info,0,last_seek);

	int tmp = process3.pc+100000;
	//printf("\n tmp = %d",tmp);

	for(int j=last_seek; j<tmp;j++)
	{
		fscanf(process3.stat_info,"%d",&temp);
	}
	process3.pc=temp;

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	process3.finishTime = process3.finishTime + cpu_time_used;

	if(process2.pc!=1000000)	
		process2.finishTime = process2.finishTime + cpu_time_used;
	if(process1.pc!=1000000)
		process1.finishTime = process1.finishTime + cpu_time_used;
	if(process4.pc!=1000000)
		process4.finishTime = process4.finishTime + cpu_time_used;	
	if(process5.pc!=1000000)
		process5.finishTime = process5.finishTime + cpu_time_used;	
	if(process6.pc!=1000000)
		process6.finishTime = process6.finishTime + cpu_time_used;	
	
/*
	process2.waitTime = process2.waitTime + cpu_time_used;
	process1.waitTime = process1.waitTime + cpu_time_used;
	process4.waitTime = process4.waitTime + cpu_time_used;
	process5.waitTime = process5.waitTime + cpu_time_used;
	process6.waitTime = process6.waitTime + cpu_time_used;
*/	
	process3.execTime = process3.execTime + cpu_time_used;
	
	printf("\nExecution time for this cycle = %f\n",cpu_time_used);
	printf("\nPCB of process 3");
	printf("\n-----------------------------------------------------------");
	printf("\npid = %d",process3.pid);
	printf("\nState = %s",process3.state);
	printf("\nPriviledge = %s",process3.priviledge);
	printf("\nPriority = %d",process3.priority);

	fclose(process3.stat_info);
	//logfile();

}


void fileread4()
{
	printf("\nReading file 4");
	double cpu_time_used;
	start = clock();
	int temp;
	process4.stat_info=fopen("tmp.txt","r");
	strcpy(process1.state, "Ready to run");
	strcpy(process2.state, "Ready to run");
	strcpy(process3.state, "Ready to run");
	strcpy(process4.state, "Running");
	strcpy(process5.state, "Ready to run");
	strcpy(process6.state, "Ready to run");
	strcpy(process4.priviledge, "User level");

	printf("\nProcess 4 is %s",process4.state);
		
	int last_seek = SEEK_CUR;
	fseek(process4.stat_info,0,last_seek);

	int tmp = process4.pc+100000;
	//printf("\n tmp = %d",tmp);

	for(int j=last_seek; j<tmp;j++)
	{
		fscanf(process4.stat_info,"%d",&temp);
	}
	process4.pc=temp;

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	process4.finishTime = process4.finishTime + cpu_time_used;

	if(process2.pc!=1000000)	
		process2.finishTime = process2.finishTime + cpu_time_used;
	if(process3.pc!=1000000)
		process3.finishTime = process3.finishTime + cpu_time_used;
	if(process1.pc!=1000000)
		process1.finishTime = process1.finishTime + cpu_time_used;	
	if(process5.pc!=1000000)
		process5.finishTime = process5.finishTime + cpu_time_used;	
	if(process6.pc!=1000000)
		process6.finishTime = process6.finishTime + cpu_time_used;	
/*
	process2.waitTime = process2.waitTime + cpu_time_used;
	process3.waitTime = process3.waitTime + cpu_time_used;
	process1.waitTime = process1.waitTime + cpu_time_used;
	process5.waitTime = process5.waitTime + cpu_time_used;
	process6.waitTime = process6.waitTime + cpu_time_used;
*/	
	process4.execTime = process4.execTime + cpu_time_used;	

	printf("\nExecution time for this cycle = %f\n",cpu_time_used);
	printf("\nPCB of process 4");
	printf("\n-----------------------------------------------------------");
	printf("\npid = %d",process4.pid);
	printf("\nState = %s",process4.state);
	printf("\nPriviledge = %s",process4.priviledge);
	printf("\nPriority = %d",process4.priority);	
	
	fclose(process4.stat_info);
	logfile();

}


void fileread5()
{
	printf("\nReading file 5");
	double cpu_time_used;
	start = clock();
	int temp;
	process5.stat_info=fopen("tmp.txt","r");
	strcpy(process1.state, "Ready to run");
	strcpy(process2.state, "Ready to run");
	strcpy(process3.state, "Ready to run");
	strcpy(process4.state, "Ready to run");
	strcpy(process5.state, "Running");
	strcpy(process6.state, "Ready to run");
	strcpy(process5.priviledge, "User level");

	printf("\nProcess 5 is %s",process5.state);
		
	int last_seek = SEEK_CUR;
	fseek(process5.stat_info,0,last_seek);

	int tmp = process5.pc+100000;
	//printf("\n tmp = %d",tmp);

	for(int j=last_seek; j<tmp;j++)
	{
		fscanf(process5.stat_info,"%d",&temp);
	}
	process5.pc=temp;

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	process5.finishTime = process5.finishTime + cpu_time_used;

	if(process2.pc!=1000000)	
		process2.finishTime = process2.finishTime + cpu_time_used;
	if(process3.pc!=1000000)
		process3.finishTime = process3.finishTime + cpu_time_used;
	if(process4.pc!=1000000)
		process4.finishTime = process4.finishTime + cpu_time_used;	
	if(process1.pc!=1000000)
		process1.finishTime = process1.finishTime + cpu_time_used;	
	if(process6.pc!=1000000)
		process6.finishTime = process6.finishTime + cpu_time_used;	
	
/*
	process2.waitTime = process2.waitTime + cpu_time_used;
	process3.waitTime = process3.waitTime + cpu_time_used;
	process4.waitTime = process4.waitTime + cpu_time_used;
	process1.waitTime = process1.waitTime + cpu_time_used;
	process6.waitTime = process6.waitTime + cpu_time_used;
*/	
	process5.execTime = process5.execTime + cpu_time_used;
	
	printf("\nExecution time for this cycle = %f\n",cpu_time_used);
	printf("\nPCB of process 5");
	printf("\n-----------------------------------------------------------");
	printf("\npid = %d",process5.pid);
	printf("\nState = %s",process5.state);
	printf("\nPriviledge = %s",process5.priviledge);
	printf("\nPriority = %d",process5.priority);	

	fclose(process5.stat_info);
	logfile();

}


void fileread6()
{
	printf("\nReading file 6");
	double cpu_time_used;
	start = clock();
	int temp;
	process6.stat_info=fopen("tmp.txt","r");
	strcpy(process1.state, "Ready to run");
	strcpy(process2.state, "Ready to run");
	strcpy(process3.state, "Ready to run");
	strcpy(process4.state, "Ready to run");
	strcpy(process5.state, "Ready to run");
	strcpy(process6.state, "Running");
	strcpy(process6.priviledge, "System level");

	printf("\nProcess 6 is %s",process6.state);
		
	int last_seek = SEEK_CUR;
	fseek(process6.stat_info,0,last_seek);

	int tmp = process6.pc+100000;
	//printf("\n tmp = %d",tmp);

	for(int j=last_seek; j<tmp;j++)
	{
		fscanf(process6.stat_info,"%d",&temp);
	}
	process6.pc=temp;

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	process6.finishTime = process6.finishTime + cpu_time_used;

	if(process2.pc!=1000000)	
		process2.finishTime = process2.finishTime + cpu_time_used;
	if(process3.pc!=1000000)
		process3.finishTime = process3.finishTime + cpu_time_used;
	if(process4.pc!=1000000)
		process4.finishTime = process4.finishTime + cpu_time_used;	
	if(process5.pc!=1000000)
		process5.finishTime = process5.finishTime + cpu_time_used;	
	if(process1.pc!=1000000)
		process1.finishTime = process1.finishTime + cpu_time_used;	
/*
	process2.waitTime = process2.waitTime + cpu_time_used;
	process3.waitTime = process3.waitTime + cpu_time_used;
	process4.waitTime = process4.waitTime + cpu_time_used;
	process5.waitTime = process5.waitTime + cpu_time_used;
	process1.waitTime = process1.waitTime + cpu_time_used;
*/	
	process6.execTime = process6.execTime + cpu_time_used;

	printf("\nExecution time for this cycle = %f\n",cpu_time_used);
	printf("\nPCB of process 6");
	printf("\n-----------------------------------------------------------");
	printf("\npid = %d",process6.pid);
	printf("\nState = %s",process6.state);
	printf("\nPriviledge = %s",process6.priviledge);
	printf("\nPriority = %d",process6.priority);

	fclose(process6.stat_info);
	logfile();

}


void fileread(int val)
{
//decreasing the priority of the process once has been in the processor	
	if(val==1804289383)
	{
		process1.priority--;		
		fileread1();
	}
	if(val==846930886)
	{	
		process2.priority--;
		fileread2();
	}	
	
	if(val==1681692777)
	{
		process3.priority--;
		fileread3();
	}
	if(val==1714636915)
	{
		process4.priority--;
		fileread4();
	}
	if(val==1957747793)
	{
		process5.priority--;
		fileread5();
	}
	if(val==424238335)
	{
		process6.priority--;
		fileread6();
	}
}


