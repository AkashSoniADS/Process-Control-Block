struct pro_PCB
{
	int pid ; //identifier
	char state[20]; //state
	char priviledge[20]; //user or system level
	int ppid; //parent process id
	int priority;
	int pc; //program counter
	//int mem_pointer;
	FILE *stat_info;
	double finishTime;
	double taTime;
	double arrivalTime;
	double waitTime;
	double execTime;
};

struct pro_PCB process1;
struct pro_PCB process2;
struct pro_PCB process3;
struct pro_PCB process4;
struct pro_PCB process5;
struct pro_PCB process6;
struct pro_PCB child1;
