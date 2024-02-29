#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
	// Initialising the array for clarity's sake
	char gantt[COL_LEN][ROW_LEN][MAX_LEN] = {
						/* Headings */{"T","| ","\0"," | ","January", " | ", "February", " | ", "March", " | ", "April", " | ", "May", " | ", "June", " | ", "July", " | ", "August", " | ", "September", " | ", "October", " | ", "November", " | ", "December", " | ","Dependencies"," | "},
						/* Task 1 */  {"0","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 2 */  {"1","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 3 */  {"2","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 4 */  {"3","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 5 */  {"4","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 6 */  {"5","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 7 */  {"6","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 8 */  {"7","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 9 */  {"8","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 10 */ {"9","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "}
						// Months+index                      J4         F6         M8         A10         M12        J14        J16        A18        S20        O22       N24        D26
					};

	// Another gantt to be filled with example tasks
	char example_gantt[COL_LEN][ROW_LEN][MAX_LEN] = {
						/* Headings */{"T","| ","\0"," | ","January", " | ", "February", " | ", "March", " | ", "April", " | ", "May", " | ", "June", " | ", "July", " | ", "August", " | ", "September", " | ", "October", " | ", "November", " | ", "December", " | ","Dependencies"," | "},
						/* Task 1 */  {"0","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 2 */  {"1","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 3 */  {"2","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 4 */  {"3","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 5 */  {"4","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 6 */  {"5","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 7 */  {"6","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 8 */  {"7","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 9 */  {"8","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "},
						/* Task 10 */ {"9","| ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | ","\0"," | "," "," | "}
						// Months+index                      J4         F6         M8         A10         M12        J14        J16        A18        S20        O22       N24        D26
					};


	// Number of x,s to be filled in each col for neatness
	const char x_marks[12][MAX_LEN] = {"xxxxxxx","xxxxxxxx","xxxx","xxxx","xxx","xxxx","xxxx","xxxxxx","xxxxxxxxx","xxxxxxx","xxxxxxxx","xxxxxxxx"};

	// Will store the length of eavh string in the top row of the x axis to allow for the widths to be adjusted accordingly
	int widths[ROW_LEN];
	// Formatting specific cols
	widths[0] = 1;
	widths[1] = strlen(gantt[0][1]);
	widths[2] = MAX_LEN;
	widths[ROW_LEN-2] = MAX_LEN;
	widths[ROW_LEN-1] = 3;
	// Iterating from 1 until the second lasrt element of the array across the top row as 0 and 27 are alr initialised
	for(int y = 3; y < ROW_LEN-2; y++)
	{
		// Getting the width of each heading
		int width = strlen(gantt[0][y]);
		// Storing the aforementioned width in widths
		widths[y] = width;
	}

	// Exmaple structs for example array
	task example_tasks[10];
	task task1 = {"Task 1",1,2,0};
	task task2 = {"Task 2",2,3,0};
	task task3 = {"Task 3",2,4,0};
	task task4 = {"Task 4",5,5,0};
	task task5 = {"Task 5",6,7,0};
	task task6 = {"Task 6",7,9,0};
	task task7 = {"Task 7",8,10,0};
	task task8 = {"Task 8",10,11,0};
	task task9 = {"Task 9",11,11,0};
	task task10 = {"Task 10",11,12,0};

	// Filling the example struct array with all our tasks created above
	example_tasks[0] = task1;
	example_tasks[1] = task2;
	example_tasks[2] = task3;
	example_tasks[3] = task4;
	example_tasks[4] = task5;
	example_tasks[5] = task6;
	example_tasks[6] = task7;
	example_tasks[7] = task8;
	example_tasks[8] = task9;
	example_tasks[9] = task10;

	/* Greeting the user */
	int num_tasks = 10;
	task arr_of_tasks[num_tasks];
    char user_choice[2];
    // Writing the example tasks into the char array from the array of structs
    data_from_struct_to_gantt(example_tasks,example_gantt,x_marks,num_tasks);
	puts("Welcome to the Gantt Generator");
	// Repeats question unless t or c is entered
	do{
		puts("Would you like to use a test example (t) or (c) create your own Gantt?");
		scanf("%s",user_choice);
		getchar();
		// User wants an example gantt
	    if(strcasecmp(user_choice,"t") == 0){
	        display_gantt(example_gantt,widths,num_tasks);
	    }
	    // User wants to create a gantt
	    else if(strcasecmp(user_choice,"c") == 0){
	        // Stores the number of tasks the user wishes to enter
			num_tasks = get_num_tasks();

			// Getting task data from the user to populate the above array of structs
			for(int i = 0; i < num_tasks; i++)
			{
				get_task(arr_of_tasks,i,num_tasks);
			}

			/* Writing task names to the array */
			data_from_struct_to_gantt(arr_of_tasks,gantt,x_marks,num_tasks);

			/* Outputting the gantt */
			display_gantt(gantt,widths,num_tasks);
		}
	} while(strcasecmp(user_choice,"t") != 0 && strcasecmp(user_choice,"c") != 0);

	// Statement to determine what the user wants to do with the data presented
	char choice[2];
	do{
		puts("To edit the Gantt, type (e), to test the Gantt type (t), or type (q) to quit");
		fflush(stdout);
		scanf("%s",choice);
		getchar();
		if(strcasecmp(choice,"e\0") == 0){
			// Editing the gantt the user created
			if(strcasecmp(user_choice,"c\0") == 0){
				// edit the created gantt
				char tsk_name[MAX_LEN];
				puts("Enter the exact name of the task you wish to change: ");
				fflush(stdout);
				fgets(tsk_name,sizeof(tsk_name),stdin);
				tsk_name[strcspn(tsk_name,"\n")] = '\0';
				// Look in every struct for the task name
				for(int i = 0; i < num_tasks; i++)
				{
					if(strcmp(arr_of_tasks[i].task_name,tsk_name) == 0){
						get_task(arr_of_tasks,i,num_tasks);
					}
				}
			}
			// Editing the sample gantt
			else{
				// edit sample one
				char tsk_name[MAX_LEN];
				puts("Enter the exact name of the task you wish to change: ");
				fflush(stdout);
				fgets(tsk_name,sizeof(tsk_name),stdin);
				tsk_name[strcspn(tsk_name,"\n")] = '\0';
				// Look in every struct for the task name
				for(int i = 0; i < num_tasks; i++)
				{
					if(strcmp(example_tasks[i].task_name,tsk_name) == 0){
						get_task(example_tasks,i,num_tasks);
					}
				}
			}
		}
		else if(strcasecmp(choice,"t\0") == 0){
			// test the gantt
		}
	// Will iterate until the user enters q
	} while(strcasecmp(choice,"q\0") != 0);


	// Displaying final Gantt
	if(strcasecmp(user_choice,"c\0") == 0){
		// show created one
		data_from_struct_to_gantt(arr_of_tasks,gantt,x_marks,num_tasks);
		display_gantt(gantt,widths,num_tasks);
	}
	else if(strcasecmp(user_choice,"t\0") == 0){
		// show example one
		data_from_struct_to_gantt(example_tasks,example_gantt,x_marks,num_tasks);
		display_gantt(example_gantt,widths,num_tasks);
	}


	return 0;
}