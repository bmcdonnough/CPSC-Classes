/*
* CPSC 3220 HW2
* Benjamin McDonnough and Jeremy Johnsonwall
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct task *create_task(int tid, int arrival, int service, int priority) {
    struct task *temp_task = (struct task *) malloc(sizeof(struct task));
    temp_task->task_id = tid;
    temp_task->arrival_time = arrival;
    temp_task->service_time = service;
    temp_task->remaining_time = service;
    temp_task->completion_time = -1;
    temp_task->response_time = -1;
    temp_task->wait_time = -1;
    temp_task->priority = priority;
    temp_task->next = NULL;
    return temp_task;
}

struct task *createTaskStruct(struct task *tempTask){
    struct task *newTask = (struct task*)malloc(sizeof(struct task));
    newTask->task_id = tempTask->task_id;
    newTask->arrival_time = tempTask->arrival_time;
    newTask->service_time = tempTask->service_time;
    newTask->remaining_time = tempTask->remaining_time;
    newTask->completion_time = tempTask->completion_time;
    newTask->response_time = tempTask->response_time;
    newTask->wait_time = tempTask->wait_time;
    newTask->priority = tempTask->priority;
    newTask->next = NULL;
    return newTask;
}


void insertSorted(struct task **headRef, struct task *newNode) {
    struct task *current;
    if (*headRef == NULL || ((*headRef)->priority > newNode->priority) || ((*headRef)->priority == newNode->priority && (*headRef)->service_time <= newNode->service_time) && (*headRef)->task_id <= newNode->task_id) {
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else {
        current = *headRef;
        while (current->next != NULL && (current->next->priority < newNode->priority || (current->next->priority == newNode->priority && current->next->service_time > newNode->service_time))) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

char getAlphaID(int id){
    if(id == 0){
        return 'Y';
    }
    if(id == 1){
        return 'Z';
    }
    else{
        id = id - 2;
        return 'A' + id;
    }
}

// Function to insert a node into a list sorted by ascending task_id from 65 to 90, the linked list will be passed by memory address and the new node will be passed by struct task *
void insertSortedAscendingTaskID(struct task** headRef, struct task* newNode) {
    struct task *current;
    if(newNode->task_id == 0){
        newNode->task_id = 89;
    }
    else if(newNode->task_id == 1){
        newNode->task_id = 90;
    }
    else{
        newNode->task_id = newNode->task_id + 63;
    }

    if (*headRef == NULL || newNode->task_id < (*headRef)->task_id) {
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else {
        current = *headRef;
        while (current->next != NULL && current->next->task_id < newNode->task_id) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


//Function to return the first task of a linked list and remove it from the list
struct task *pop(struct task **head) {
    struct task *temp = *head;
    *head = (*head)->next;
    return temp;
}

void priorityScheduling(struct task* head, int numTasks){
    printf("Priority scheduling results\n\n");
    printf("time\tcpu\tpriority\tready queue (tid/rst)\n");
    printf("-----------------------------------------------------\n");
    int time = 0;
    struct task* tempTask = NULL;
    struct task* cpuTask = NULL;
    struct task* readyQueue = NULL;
    struct task* completedTasks = NULL;
    int completedTasksCounter = 0;
    int taskIDCounter = 0;

    while(time != -1 && completedTasksCounter != numTasks) {
        // Move from head into readyQueue
        while(head != NULL && head->arrival_time <= time){
            struct task *newNode = createTaskStruct(head);
            insertSorted(&readyQueue, newNode);
            head = head->next;
        }
        // If cpu is empty, move task from readyQueue into the cpu
        if(cpuTask == NULL){
            if(readyQueue != NULL){
                cpuTask = pop(&readyQueue);
                cpuTask->task_id = taskIDCounter++;
                printf("%2d    %c%d    %2d     ", time, getAlphaID(cpuTask->task_id), cpuTask->remaining_time--, cpuTask->priority);
                if(cpuTask != NULL && readyQueue == NULL){
                    printf("  --  \n");
                }

                int tempTaskIDCounter = taskIDCounter;
                tempTask = readyQueue;
                while(tempTask != NULL){
                    tempTask->task_id = tempTaskIDCounter++;
                    printf(" %c%d %d    ", getAlphaID(tempTask->task_id), tempTask->service_time, tempTask->priority);
                    tempTask = tempTask->next;
                    printf("\n");
                }
            }
        }
        // CPU is currently running something
        else{
            // There is a completed task in the cpu
            if(cpuTask->remaining_time == 0){
                cpuTask->completion_time = time;
                cpuTask->wait_time = cpuTask->completion_time - cpuTask->arrival_time - cpuTask->service_time;
                cpuTask->response_time = cpuTask->completion_time - cpuTask->arrival_time;
                insertSorted(&completedTasks, cpuTask);
                completedTasksCounter++;
                cpuTask = NULL;

                if(readyQueue != NULL){
                    cpuTask = pop(&readyQueue);
                    cpuTask->task_id = taskIDCounter++;
                    printf("%2d    %c%d    %2d     ", time, getAlphaID(cpuTask->task_id), cpuTask->remaining_time--, cpuTask->priority);

                    int tempTaskIDCounter = taskIDCounter;
                    tempTask = readyQueue;
                    while(tempTask != NULL){
                        tempTask->task_id = tempTaskIDCounter++;
                        printf(" %c%d %d    ", getAlphaID(tempTask->task_id), tempTask->service_time, tempTask->priority);
                        tempTask = tempTask->next;
                    }

                    if(readyQueue == NULL){
                        printf("  --  \n");
                    }
                    else{
                        printf("\n");
                    }
                }
            }
            // There is an uncompleted task in the cpu
            else{
                printf("%2d    %c%d    %2d     ", time, getAlphaID(cpuTask->task_id), cpuTask->remaining_time--, cpuTask->priority);
                if(readyQueue != NULL){
                    tempTask = readyQueue;
                    int tempTaskIDCounter = taskIDCounter;
                    while(tempTask != NULL){
                        tempTask->task_id = tempTaskIDCounter++;
                        printf(" %c%d %d    ", getAlphaID(tempTask->task_id), tempTask->service_time, tempTask->priority);
                        tempTask = tempTask->next;
                    }
                    printf("\n");
                }
                else{
                    printf("  --  \n");
                }
            }
        }
        if(cpuTask == NULL && readyQueue == NULL && completedTasksCounter != numTasks){
            printf(" %d\t\t\t\t\t\t\t--\n", time);
        }
        time++;
    }
    printf("\n\n");
    printf("             arrival   service completion response wait\n");
    printf("tid   prio   time      time    time       time     time\n");
    printf("--------------------------------------------------------\n");
    struct task * sortedAscendingTaskIdentifiers = NULL;
    while(completedTasks != NULL){
        struct task *newNode = createTaskStruct(completedTasks);
        insertSortedAscendingTaskID(&sortedAscendingTaskIdentifiers, newNode);
        completedTasks = completedTasks->next;
    }
    tempTask = sortedAscendingTaskIdentifiers;
    while(tempTask != NULL){
        printf(" %c     %2d     %2d        %2d      %2d         %2d       %2d\n", 
              tempTask->task_id, tempTask->priority, tempTask->arrival_time, 
              tempTask->service_time, tempTask->completion_time, tempTask->response_time, 
              tempTask->wait_time);

        tempTask = tempTask->next;
    }
}

void customScheduling(struct task* head, int numTasks){
    printf("Custom(preemptive) scheduling results\n\n");
    printf("time\tcpu\tpriority\tready queue (tid/rst)\n");
    printf("-----------------------------------------------------\n");

    int time = 0;
    struct task* tempTask = NULL;
    struct task* cpuTask = NULL;
    struct task* readyQueue = NULL;
    struct task* completedTasks = NULL;
    int completedTasksCounter = 0;
    int taskIDCounter = 0;

    while(time != -1 && completedTasksCounter != numTasks) {
        // Move from stdIn into readyQueue
        while(head != NULL && head->arrival_time <= time){
            struct task *newNode = createTaskStruct(head);
            insertSorted(&readyQueue, newNode);
            head = head->next;
        }
        // If cpu is empty, move task from readyQueue into the cpu
        if(cpuTask == NULL){
            if(readyQueue != NULL){
                cpuTask = pop(&readyQueue);
                cpuTask->task_id = taskIDCounter++;
                printf(" %2d    %c%d    %2d     ", time, getAlphaID(cpuTask->task_id), cpuTask->remaining_time--, cpuTask->priority);
                
                if(cpuTask != NULL && readyQueue == NULL){
                    printf("    --  \n");
                }
                
                if(readyQueue != NULL){
                    int tempTaskIDCounter = taskIDCounter;
                    tempTask = readyQueue;
                    while(tempTask != NULL){
                        tempTask->task_id = tempTaskIDCounter++;
                        printf("  %c%d %d    ", getAlphaID(tempTask->task_id), tempTask->service_time, tempTask->priority);
                        tempTask = tempTask->next;
                    }
                    printf("\n");
                }
            }
        }
        // CPU is currently running something
        else{
            // There is a completed task in the cpu
            if(cpuTask->remaining_time == 0){
                cpuTask->completion_time = time;
                cpuTask->wait_time = cpuTask->completion_time - cpuTask->arrival_time - cpuTask->service_time;
                cpuTask->response_time = cpuTask->completion_time - cpuTask->arrival_time;
                struct task *newNode = createTaskStruct(cpuTask);
                insertSorted(&completedTasks, newNode);
                completedTasksCounter++;
                cpuTask = NULL;

                if(readyQueue != NULL){
                    cpuTask = pop(&readyQueue);
                    if(cpuTask->service_time == cpuTask->remaining_time) {
                        cpuTask->task_id = taskIDCounter++;
                    }

                    printf(" %2d    %c%d    %2d     ", time, getAlphaID(cpuTask->task_id), cpuTask->remaining_time--, cpuTask->priority);
                    if(readyQueue != NULL){
                        int tempTaskIDCounter = taskIDCounter;
                        tempTask = readyQueue;
                        while(tempTask != NULL){
                            if(tempTask->service_time == tempTask->remaining_time) {
                                tempTask->task_id = tempTaskIDCounter++;
                            }
                            printf("  %c%d %d    ", getAlphaID(tempTask->task_id), tempTask->service_time, tempTask->priority);
                            tempTask = tempTask->next;
                        }
                    }
                    if(readyQueue == NULL){
                        printf("    --  \n");
                    }
                    else{
                        printf("\n");
                    }
                }
            }
            // There is an uncompleted task in the cpu
            else {
                tempTask = pop(&cpuTask);
                tempTask->priority += 1;
                insertSorted(&readyQueue, tempTask);
                cpuTask = pop(&readyQueue);
                printf(" %2d    %c%d    %2d     ", time, getAlphaID(cpuTask->task_id), cpuTask->remaining_time--, cpuTask->priority);
                if(readyQueue != NULL){
                    int tempTaskIDCounter = taskIDCounter;
                    tempTask = readyQueue;
                    while(tempTask != NULL){
                        if(tempTask->service_time == tempTask->remaining_time) {
                            tempTask->task_id = tempTaskIDCounter++;
                        }
                        printf("  %c%d %d    ", getAlphaID(tempTask->task_id), tempTask->remaining_time, tempTask->priority);
                        tempTask = tempTask->next;
                    }
                    printf("\n");
                }
                else{
                    printf("    --  \n");
                }
            }

        }
        if(cpuTask == NULL && readyQueue == NULL && completedTasksCounter != numTasks){
            printf(" %2d\t\t\t\t\t\t\t--\n", time);
        }
        time++;
    }
    printf("\n\n");
    printf("             arrival   service completion response wait\n");
    printf("tid   prio   time      time    time       time     time\n");
    printf("--------------------------------------------------------\n");
    struct task * sortedAscendingTaskIdentifiers = NULL;
    while(completedTasks != NULL){
        struct task *newNode = createTaskStruct(completedTasks);
        insertSortedAscendingTaskID(&sortedAscendingTaskIdentifiers, newNode);
        completedTasks = completedTasks->next;
    }
    tempTask = sortedAscendingTaskIdentifiers;
    while(tempTask != NULL){
        printf(" %c     %2d     %2d        %2d      %2d         %2d       %2d\n", 
              tempTask->task_id, (tempTask->priority - tempTask->service_time), tempTask->arrival_time, 
              tempTask->service_time, tempTask->completion_time, tempTask->response_time, 
              tempTask->wait_time);

        tempTask = tempTask->next;
    }
}

int main(int argc, char* argv[]){
    struct task *head = NULL;
    struct task *tail = NULL;
    int numTasks = 0;
    int arrivalTime, serviceTime, priority;
    char taskID = 'Y';

    while(scanf("%d %d %d", &arrivalTime, &serviceTime, &priority) == 3){

        struct task* newTask = create_task(taskID, arrivalTime, serviceTime, priority);

        numTasks++;
        taskID++;
        if(taskID > 'Z'){
            taskID = 'A';
        }
        if(newTask != NULL){
            if(head == NULL){
                head = newTask;
                tail = newTask;
            }
            else{
                tail->next = newTask;
                tail = newTask;
            }
        }
    }

    if(strcmp(argv[1], "-prio") == 0){
        priorityScheduling(head, numTasks);
    }
    else if(strcmp(argv[1], "-custom") == 0){
        customScheduling(head, numTasks);
    }
    else{
        printf("bruh");
        return 0;
    }

    return 0;
}