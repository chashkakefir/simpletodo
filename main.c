#include <stdio.h>
#include <stdlib.h>
#include "todo.h"

int main(int argc, char *argv[]){
	short started = 1;
	printf("Simple To Do programm\n");
	printf("by chashkakefir\n");
	if (argc == 1){
		printf("No file to work with specified!\n");
		return 1;
	}
	FILE *re;
	if (!(re = fopen(argv[1], "r"))){
		printf("Error! Can't open file %s to read it!\n", argv[1]);
		return 1;
	}
	FILE *wr;
	if (!(wr = fopen(argv[1], "a"))){
		printf("Error! Can't open file %s to write in it!\n", argv[1]);
		return 1;
	}
	while (started){
		char operator;
		printf("Select, what to do.\n(N) for new task, (A) for agenda, (E) to edit task properties, X to exit: ");
		scanf("%c", &operator);
		switch(operator){
			case 'X'
				started = 0;
				break;
			case 'N':
				char name[80];
				char desc[200];
				unsigned int day:4;
				unsigned int month:3;
				unsigned short year;
				short priority;
				printf("Enter task name (80 symbols max): ");
				scanf("%79s[^\n]", &name);
				printf("Enter description (200 symbols max): ");
				scanf("%199s[^\n]", &desc);
				printf("Enter task's priority (from 1 to 5): ");
				scanf("%i", &priority);
				if ((priority < 1) || (priority > 5)){
					printf("Error! Priority is out of range 1-5\n");
					break;
				}
				printf("Enter deadline day:");
				scanf("%i", &day);
				printf("Enter deadline month: ");
				scanf("%i", &)
				task task = {name, desc, priority, deadline};
				newtask(task, wr);
				printf("Successfully written in file %s\n", argv[1]);
				break;
			case 'A':
				char name[80];
				char desc[200];
				char deadline[11];
				short priority;
				while(fscanf("%s\n%s\n%s\n%i\n", &name, &desc, &deadline, &priority, re)== 3){
					task t = {name, desc, priority, deadline};
					printf("Task name: %s\n", t.name);
					printf("Description: %s\n", t.desc);
					printf("Deadline: %s\n", t.deadline);
					printf("Task priority: %i\n", t.prior);
				}

		}
	}
}
