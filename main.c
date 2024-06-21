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
			case 'X':
				started = 0;
				break;
			case 'N':
				char name[80];
				char desc[200];
				char deadline[11];
				short priority;
				printf("Enter task name (80 symbols max): ");
				scanf("%79[^\n]", &name);
				printf("Enter description (200 symbols max): ");
				scanf("%199[^\n]", &desc);
				printf("Enter task's priority (from 1 to 5): ");
				scanf("%i", &priority);
				if ((priority < 1) || (priority > 5)){
					printf("Error! Priority is out of range 1-5\n");
					break;
				}
				printf("Enter deadline in format DD-MM-YYYY and NODEADLINE if there is no deadline: ");
				scanf("%10[^\n]", &deadline);
				newtask(name, desc, deadline, priority, wr);
				printf("Successfully written in file %s\n", argv[1]);
				break;
			case 'A':
				// Do something here, I don't know what to do!

		}
	}
}
