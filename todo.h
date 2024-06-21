typedef struct{
	unsigned int day:4;
	unsigned int month:3;
	unsigned short year;
} date;

typedef struct{
	const char *name;
	const char *desc;
	unsigned int prior:3;
	date deadline;
} task;

void newtask(task task, FILE *wr){
	fprintf(wr, "%s\n%s\n%s\n%i\n", task.name, task.desc, task.deadline, task.prior);
}
