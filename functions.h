#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define COL_LEN 11
#define ROW_LEN 30
#define MAX_LEN 21
#define MAX_DEPS 9
#define MAX_TASKS 10
#define MIN_TASKS 1

// All the related data for an individual task
typedef struct
{
	char task_name[MAX_LEN];
	int start_month;
	int end_month;
	int num_dependencies;
	int dependencies[MAX_DEPS];
}task;

// Gets the number of tasks the user wants to enter
int get_num_tasks(void);

// Grabs input from the user and fills the struct array with said data obtained from the user
void get_task(task tasks[],int index_in_structArray,int number_of_tasks);

// Transfers relevant data from the struct array to the gantt
void data_from_struct_to_gantt(task tasks[],char gant[COL_LEN][ROW_LEN][MAX_LEN],const char x_fills[12][MAX_LEN],int num_tasks);

// Displays a gantt
void display_gantt(char gant[COL_LEN][ROW_LEN][MAX_LEN],int widthz[ROW_LEN],int num_rows_to_print);

#endif /* FUNCTIONS_H_ */