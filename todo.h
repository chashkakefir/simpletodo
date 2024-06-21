typedef struct{
	const char *name;
	const char *desc;
	short prior;
	char deadline[11];
} task;

void newtask(char name[80], char desc[200], char deadline[11], short prior, FILE *wr){
	fprintf(wr, "%s\n%s\n%s\n%i\n", name, desc, deadline, prior);
}
