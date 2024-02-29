#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int get_num_tasks(void)
{
	// Stores the number of tasks the user wishes to enter
	int num_tasks;

	/* Get the number of taks the user wants to enter */
	do{
		// Determining how many tasks the user wants
		puts("How many tasks would you like to add (1-10)?");
		fflush(stdout);
		// Storing user input for use in function and creating of struct array
		scanf("%d",&num_tasks);
		// Eats the \n left in the input buffer so that fgets can read without issue
		getchar();
	// Iterates until a valid task number is entered
	} while(num_tasks < MIN_TASKS || num_tasks > MAX_TASKS);
	return num_tasks;
}


void get_task(task tasks[],int index_in_structArray,int number_of_tasks)
{
	// Stores the task name before being put in the actual string, to prevent buffer overflow if the user enters a large string beyond the specified limits
	char temp[100];
	// String of specified max len where user input will be stored once it is validated to be put in the struct
	char safe[MAX_LEN];
	// Stores the months for being put in the struct
	int start,end,num_of_dependencies,dep_task;

	/* Get the task name from the user */
	do{
		// Instructions for the user
		printf("Task Name (Max 20 chrs): ");
		fflush(stdout);
		// fgets allows for spaces to be included in task names, as well as being more robust than scanf
    	fgets(temp,sizeof(temp),stdin);
    	// fgets reads the \n chr so we have to replace that with a \0 for a null terminating string
    	temp[strcspn(temp,"\n")] = '\0';
    // Will keep iterating until the user enters a string that satisfies the conditions set by the instructions
    } while(strlen(temp) > MAX_LEN-1);
    // Once out of the loop we know it is safe to write the string into it's designated string without risk of buffer overflow
    strcpy(safe,temp);
    // Hence it can be safely stored in the struct
    strcpy(tasks[index_in_structArray].task_name,safe);

    /* Get the start month of the task */
    do{
    	// Instructions for the user
    	printf("Start month (1-12): ");
    	fflush(stdout);
    	// Using scanf for the integer value entered by the user
    	scanf("%d",&start);
    	// Gobbles the \n left by scanf so that fgets won't be accidentally skipped by leaving a \n in the input buffer
    	getchar();
    	// Will iterate until the conditions are met and we have a valid start month
	} while(start < 1 || start > 12);
	// Once out of loop we can be assured we have a valid start month, thus it can be stored in the struct
    tasks[index_in_structArray].start_month = start;

    /* Get the end month of the task */
    do{
    	// Instructions for the user
    	printf("End month (1-12): ");
    	fflush(stdout);
    	// Using scanf for the integer value enterd by the user
    	scanf("%d",&end);
    	// Gobbles the \n left by scanf so that fgets won't be accidentally skipped by leaving a \n in the input buffer
    	getchar();
    	// Extra hints for the user if the end month is invalid
    	if(end < start){
    		puts("The task can't end before it starts!");
    		fflush(stdout);
    	}
    // Will iterate until a valid end month is obtained
	} while(end < 1 || end > 12 || end < start);
	// Out of loop, hence we can safely append the value to the struct
    tasks[index_in_structArray].end_month = end;

    /* Get the number of dependencies for the task */
    do{
    	// Instructions for the user
    	printf("Enter how many dependencies this task has (0-9): ");
    	fflush(stdout);
    	// Using scanf for the integer value entered by the user
    	scanf("%d",&num_of_dependencies);
    	// Gobbles the \n left by scanf so that fgets won't be accidentally skipped by leaving a \n in the input buffer
    	getchar();
    // Iterates until a valid num dependencies is entered
    } while(num_of_dependencies < 0 || num_of_dependencies > MAX_DEPS);
    // Loop is broken, hence we can safely write the data to the struct
    tasks[index_in_structArray].num_dependencies = num_of_dependencies;

    /* Get the dependent tasks for each task */
    for(int x = 0; x < num_of_dependencies; x++)
    {
    	do{
    		// Instructions for the user
    		printf("Enter dependent task (0 - (num_tasks-1)): ");
    		fflush(stdout);
    		scanf("%d",&dep_task);
    		// Gobbles \n
    		getchar();
    	// Conditions to ensure the task is valid
    	} while(dep_task < 0 || dep_task >= number_of_tasks);
    	// Fills the int array with dependant tasks
    	tasks[index_in_structArray].dependencies[x] = dep_task;
    }
    
}

void data_from_struct_to_gantt(task tasks[],char gant[COL_LEN][ROW_LEN][MAX_LEN],const char x_fills[12][MAX_LEN],int num_tasks)
{
	/* Writing task names to the array */
	for(int z = 0; z < num_tasks; z++)
	{
		// Putting the task name in the appropriate location in the gantt
		strcpy(gant[z+1][2],tasks[z].task_name);

		// Clearing the rnage where the months are filled to allow for editing
		for(int index_of_months = 4; index_of_months <= 26; index_of_months += 2)
		{
			strcpy(gant[z+1][index_of_months],"");
		}
		// Adjusting the index of the months according to the gantt index
		int start_of_task = (tasks[z].start_month) * 2 + 2;
		int end_of_task = (tasks[z].end_month) * 2 + 2;

		// Iterates over the gantt, filling in the months where the chosen task is active
		for(/*start_of_task*/; start_of_task <= end_of_task; start_of_task += 2)
		{
			// Used to refenence the 2D array with the perfect number of x's for neatness and aesthetics
			int original_index = ((start_of_task-2) / 2) - 1;
			// Copying said string to the respective column
			strcpy(gant[z+1][start_of_task],x_fills[original_index]);
		}
		// Writing the dependencies to the gantt
		if(tasks[z].num_dependencies > 0){
			int temp_init = tasks[z].dependencies[0];
			char int_to_str_init [2];
			int_to_str_init[0] = (temp_init + '0');
			int_to_str_init[1] = '\0';
			strcpy(gant[z+1][28],int_to_str_init);
			strcat(gant[z+1][28]," ");
		}
		for(int p = 1; p < tasks[z].num_dependencies; p++)
		{
			// Storing the integer value from the integer array
			int temp = tasks[z].dependencies[p];
			// Where the integer will be stored once turned into a string
			char int_to_str[2];
			// chrs 0-9 are in the ascii range 48-57, allowing for a nice and simple addition to convert from int to chr,
			// this only is reliable as we can only encounter single digit integers in this section
			int_to_str[0] = (temp + '0');
			// Adding the null terminater to the string
			int_to_str[1] = '\0';
			// Note strcat instead of string copy as we want to keep the previous values in the string when appending multiple values from the integer array
			strcat(gant[z+1][28],int_to_str);
			// Spacing between values
			strcat(gant[z+1][28]," ");
		}
	}
}


void display_gantt(char gant[COL_LEN][ROW_LEN][MAX_LEN],int widthz[ROW_LEN],int num_rows_to_print)
{
	/* Outputting the gantt */
	for(int i = 0; i <= num_rows_to_print; i++)
	{
		for(int z = 0; z < ROW_LEN; z++)
		{
			printf("%-*s",widthz[z],gant[i][z]);
			fflush(stdout);
		}
		puts("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------");
	}
}