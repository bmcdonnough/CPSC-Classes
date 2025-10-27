#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TASKS 26

struct task {
    int task_id,
        arrival_time,
        service_time,
        remaining_time,
        completion_time,
        response_time,
        wait_time,
        priority;
    struct task *next;
};

void print_trace(FILE *output, int time, struct task *running_task, struct task *ready_queue) {
    fprintf(output, " %2d ", time);
    if (running_task != NULL) {
        fprintf(output, "   %c%d    %2d     ", 'A' + running_task->task_id, running_task->remaining_time, running_task->priority);
    } else {
        fprintf(output, "                ");
    }
    struct task *current = ready_queue;
    if (current == NULL){
        fprintf(output, "    --  ");
    }
    while (current != NULL) {
        fprintf(output, "    %c%d %d ", 'A' + current->task_id, current->remaining_time, current->priority);
        current = current->next;
    }
    fprintf(output, "\n");
}

void print_summary_priority(FILE *output, struct task *tasks, int num_tasks) {
    // Sort tasks by TID
    for (int i = 0; i < num_tasks - 1; i++) {
        for (int j = 0; j < num_tasks - i - 1; j++) {
            if (tasks[j].task_id > tasks[j + 1].task_id) {
                struct task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    fprintf(output, "             arrival   service completion response wait\n");
    fprintf(output, "tid   prio   time      time    time       time     time\n");
    fprintf(output, "--------------------------------------------------------\n");
    for (int i = 0; i < num_tasks; ++i) {
        fprintf(output, " %c     %2d     %2d        %2d      %2d         %2d       %2d\n",
               'A' + tasks[i].task_id, tasks[i].priority, tasks[i].arrival_time, tasks[i].service_time,
               tasks[i].completion_time, tasks[i].response_time, tasks[i].wait_time);
    }
}

void print_summary_custom(FILE *output, struct task *tasks, int num_tasks) {
    // Sort tasks by TID
    for (int i = 0; i < num_tasks - 1; i++) {
        for (int j = 0; j < num_tasks - i - 1; j++) {
            if (tasks[j].task_id > tasks[j + 1].task_id) {
                struct task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < num_tasks; i++){
        tasks[i].priority -= (tasks[i].service_time - 1);
    }

    fprintf(output, "             arrival   service completion response wait\n");
    fprintf(output, "tid   prio   time      time    time       time     time\n");
    fprintf(output, "--------------------------------------------------------\n");
    for (int i = 0; i < num_tasks; ++i) {
        fprintf(output, " %c     %2d     %2d        %2d      %2d         %2d       %2d\n",
               'A' + tasks[i].task_id, tasks[i].priority, tasks[i].arrival_time, tasks[i].service_time,
               tasks[i].completion_time, tasks[i].response_time, tasks[i].wait_time);
    }
}

void print_service_wait_pairs(FILE *output, struct task *tasks, int num_tasks) {
    fprintf(output, "service wait\n");
    fprintf(output, " time   time\n");
    fprintf(output, "------- ----\n");
    for (int i = 0; i < num_tasks; ++i) {
        fprintf(output, "  %2d     %2d\n", tasks[i].service_time, tasks[i].wait_time);
    }
}

void schedule_tasks_priority(FILE *output, struct task *tasks, int num_tasks) {
    int time = 0;
    struct task *running_task = NULL;
    struct task *ready_queue = NULL;
    int num_tasks_completed = 0;

    while (num_tasks_completed < num_tasks || ready_queue != NULL || running_task != NULL) {

        // Add arriving tasks to the ready queue
        for (int i = 0; i < num_tasks; ++i) {
            if (tasks[i].arrival_time == time) {
                struct task *new_task = &tasks[i];
                new_task->remaining_time = new_task->service_time;
                new_task->next = NULL;
                if (ready_queue == NULL) {
                    ready_queue = new_task;
                    num_tasks_completed++;
                } else {
                    struct task *current = ready_queue;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = new_task;
                    num_tasks_completed++;
                }
            }
        }

        // Schedule task with highest priority and shortest service time
        if (running_task == NULL && ready_queue != NULL) {
            struct task *highest_priority = ready_queue;
            struct task *current = ready_queue->next;
            while (current != NULL) {
                if (current->priority < highest_priority->priority ||
                    (current->priority == highest_priority->priority && current->service_time < highest_priority->service_time)) {
                    highest_priority = current;
                }
                current = current->next;
            }
            running_task = highest_priority;

            // Remove running task from ready queue
            if (ready_queue == running_task) {
                ready_queue = ready_queue->next;
            } else {
                struct task *prev = ready_queue;
                while (prev->next != running_task) {
                    prev = prev->next;
                }
                prev->next = running_task->next;
            }
        }

        print_trace(output, time, running_task, ready_queue);

        // Execute task for one time unit
        if (running_task != NULL) {
            running_task->remaining_time--;
            if (running_task->remaining_time == 0) {
                running_task->completion_time = time + 1;
                running_task = NULL;
            }
        }

        // Increment time
        time++;
    }

    // Calculate wait times and response times
    for (int i = 0; i < num_tasks; ++i) {
        tasks[i].wait_time = tasks[i].completion_time - tasks[i].arrival_time - tasks[i].service_time;
        tasks[i].response_time = tasks[i].service_time + tasks[i].wait_time;
    }
}

/*

⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣶⣶⣶⣶⣶⣦⠀⣰⣶⣶⣶⣶⣦⡀⠀⣶⣶⡾⠀⣰⣶⣶⢲⣶⣶⡖⠀⣶⣶⡶⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⠿⣿⣿⣿⣇⣿⣿⡿⢿⣿⣿⡇⣸⣿⣿⠇⢠⣿⣿⡟⣼⣿⣿⠁⣸⣿⣿⠇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣟⣠⣿⣿⡟⣸⣿⣿⠃⣸⣿⣿⢧⣿⣿⡟⠀⣼⣿⣿⢱⣿⣿⣧⣤⣿⣿⡟⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⡍⢠⣿⣿⣿⣾⣿⡿⠋⣼⣿⣿⠃⢰⣿⣿⣇⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⠀⢰⣿⣿⡏⢉⣿⣿⣿⣾⣿⣿⢿⣿⣿⠀⢰⣿⣿⡏⢀⣿⣿⡿⣸⣿⣿⠏⢹⣿⣿⡏⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡴⠁⠀⣾⣿⣿⣶⣾⣿⣿⢿⣿⣿⠇⢸⣿⣿⠀⢼⣿⣿⣷⣾⣿⣿⢃⣿⣿⡟⠀⣾⣿⣿⣀⣤⡴⠖⠊⠁
⠀⠀⠀⣠⣿⠃⠀⢸⠿⠿⠿⠿⠿⠛⠁⡿⠿⡿⠀⠸⡿⣿⡇⠘⠿⣿⣿⡿⠟⢁⣼⣿⣿⣷⣾⡿⠟⠋⠉⠀⠀⠀⠀⠀
⠀⠀⣼⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣶⣶⣿⣿⣿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⣼⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣤⣴⣶⣾⣿⣿⣿⣿⣿⠿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢸⣿⣿⣿⣿⣿⣿⣶⣶⣤⣴⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠈⠙⠛⠿⠿⠿⠟⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

*/
void schedule_tasks_custom(FILE *output, struct task* tasks, int num_tasks){
    int time = 0;
    struct task *running_task = NULL;
    struct task *ready_queue = NULL;
    int num_tasks_completed = 0;

    while (num_tasks_completed < num_tasks || ready_queue != NULL || running_task != NULL) {

        // Add arriving tasks to the ready queue
        for (int i = 0; i < num_tasks; ++i) {
            if (tasks[i].arrival_time == time) {
                struct task *new_task = &tasks[i];
                new_task->remaining_time = new_task->service_time;
                new_task->next = NULL;
                if (ready_queue == NULL) {
                    ready_queue = new_task;
                    num_tasks_completed++;
                } else {
                    struct task *current = ready_queue;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = new_task;
                    num_tasks_completed++;
                }
            }
        }

        // Schedule task with highest priority and shortest service time
        if (running_task == NULL && ready_queue != NULL) {
            struct task *highest_priority = ready_queue;
            struct task *current = ready_queue->next;
            while (current != NULL) {
                if (current->priority < highest_priority->priority ||
                    (current->priority == highest_priority->priority && current->service_time < highest_priority->service_time)) {
                    highest_priority = current;
                }
                current = current->next;
            }
            running_task = highest_priority;

            // Remove running task from ready queue
            if (ready_queue == running_task) {
                ready_queue = ready_queue->next;
            } else {
                struct task *prev = ready_queue;
                while (prev->next != running_task) {
                    prev = prev->next;
                }
                prev->next = running_task->next;
            }
        }

        print_trace(output, time, running_task, ready_queue);

        // Execute task for one time unit
        if (running_task != NULL) {
            running_task->remaining_time--;
            if (running_task->remaining_time == 0) {
                running_task->completion_time = time + 1;
                running_task = NULL;
            }
            else {
                running_task->priority++;
            }
        }

        // Add running task back to ready queue if it was no completed
        if (running_task != NULL && running_task->remaining_time > 0){
            if (ready_queue == NULL){
                ready_queue = running_task;
            }
            else {
                struct task *itr = ready_queue;
                while (itr->next != NULL){
                    itr = itr->next;
                }
                running_task->next = NULL;
                itr->next = running_task;
            }
            running_task = NULL;
        }

        // Increment time
        time++;
    }

    // Calculate wait times and response times
    for (int i = 0; i < num_tasks; ++i) {
        tasks[i].wait_time = tasks[i].completion_time - tasks[i].arrival_time - tasks[i].service_time;
        tasks[i].response_time = tasks[i].service_time + tasks[i].wait_time;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Wrong number of command line arguments\n");
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    FILE *output = fopen(argv[3], "w");
    if (output == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    struct task tasks[MAX_TASKS];
    int num_tasks = 0;
    char task_id = 'Y'; // Starting task ID

    // Read tasks from input file
    while (fscanf(file, "%d %d %d", &tasks[num_tasks].arrival_time, &tasks[num_tasks].service_time, &tasks[num_tasks].priority) == 3) {
        tasks[num_tasks].task_id = task_id - 'A';
        task_id++;
        if (task_id > 'Z') {
            task_id = 'A';
        }
        tasks[num_tasks].remaining_time = 0;
        tasks[num_tasks].completion_time = 0;
        tasks[num_tasks].response_time = -1;
        tasks[num_tasks].wait_time = 0;
        tasks[num_tasks].next = NULL;
        num_tasks++;
    }
    fclose(file);

    // Run scheduling algorithm
    if (strcmp(argv[1], "-prio") == 0){
        fprintf(output, "time  cpu  priority  ready queue (tid/rst)\n");
        fprintf(output, "------------------------------------------\n");
        schedule_tasks_priority(output, tasks, num_tasks);
        // Print task summary
        fprintf(output, "\n");
        print_summary_priority(output, tasks, num_tasks);
    }
    else if (strcmp(argv[1], "-custom") == 0){
        fprintf(output, "time  cpu  priority  ready queue (tid/rst)\n");
        fprintf(output, "------------------------------------------\n");
        schedule_tasks_custom(output, tasks, num_tasks);
        // Print task summary
        fprintf(output, "\n");
        print_summary_custom(output, tasks, num_tasks);
    }
    else {
        printf("Please try again using -prio for priority based or -custom for custom scheduling.\n");
        return 0;
    }

    // Print service time and wait time pairs
    fprintf(output, "\n");
    print_service_wait_pairs(output, tasks, num_tasks);

    return 0;
}
