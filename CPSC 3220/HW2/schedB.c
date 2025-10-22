#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct task
{
    int task_id;
    int arrival_time;
    int service_time;
    int remaining_time;
    int completion_time;
    int response_time;
    int wait_time;
    int priority;
    struct task *next;
};

struct task *initializeTask(int id, int arrival_time, int service_time, int priority){
    struct task *new_task = (struct task * )malloc(sizeof(struct task));
    new_task->task_id = id;
    new_task->arrival_time = arrival_time;
    new_task->service_time = service_time;
    new_task->remaining_time = 0;
    new_task->completion_time = -1;
    new_task->response_time = service_time;
    new_task->wait_time = 0;
    new_task->priority = priority;
    new_task->next = NULL;

    return new_task;
}

void priorityScheduling(struct task*, struct task*, struct task*, int, FILE*);

void insertSortedQueue(struct task *head, struct task *newNode){
    //If the new node has a greater priority (lower number) than the head, insert at the beginning
    if(head == NULL || head->priority <= newNode->priority){
        newNode->next = head;
        head = newNode;
    }
    else{
        struct task* temp = head;
        while(temp != NULL && temp->priority > newNode->priority){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertSortedFinished(struct task *head, struct task *newNode){
    //If the new node has a greater priority (lower number) than the head, insert at the beginning
    if(head == NULL || head->priority >= newNode->priority){
        newNode->next = head;
        head = newNode;
    }
    else{
        struct task* temp = head;
        while(temp != NULL && temp->priority < newNode->priority){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printQueue(struct task *q, FILE *outputFile){
    while(q != NULL){
        fprintf(outputFile, "%c%d %d\t", q->task_id, q->remaining_time, q->priority);
        q = q->next;
    }
}

void priorityCtr(struct task* head, struct task* queue, struct task* finished, FILE *outputFile){
    fprintf(outputFile, "Priority scheduling results\n");
    fprintf(outputFile, "time\tcpu\t\tpriority\tready queue (tid/rst)\n");
    fprintf(outputFile, "----------------------------\n");

    int time = 0;
    priorityScheduling(head, queue, finished, time, outputFile);

    fprintf(outputFile, "   \t    \tarrival\tservice\tcompletion\tresponse\twait\n");
    fprintf(outputFile, "tid\tprio\ttime   \ttime   \ttime      \ttime    \ttime");
    fprintf(outputFile, "--------------------------------------------------------------");
    while(finished != NULL){
        fprintf(outputFile, " %c\t %2d\t   %2d\t\t%2d\t\t%2d\t\t %2d\t\t  %2d", 
                (char)finished->task_id, finished->priority, finished->arrival_time,
                finished->service_time, finished->completion_time, 
                finished->response_time, finished->wait_time);

        struct task* temp = finished;
        finished = finished->next;
        free(temp);
    }
}

void priorityScheduling(struct task* head, struct task* queue, struct task* finished, int time, FILE *outputFile){
    struct task *currentTask = head;

    if(currentTask==NULL){
        return;
    }
    else{
        //Nothing is in the queue and the service time for a task has come up
        if(currentTask->arrival_time < time && queue == NULL){
            fprintf(outputFile, "%2d\t\t\t\t\t\t\t\t--\n", time);
            time++;
            priorityScheduling(head, queue, finished, time, outputFile);
        }
        else{
            while(currentTask->service_time != 0){
                if(currentTask->next->arrival_time >= currentTask->arrival_time){
                    currentTask->next->wait_time += currentTask->service_time;
                    insertSortedQueue(queue, currentTask->next);
                }

                fprintf(outputFile, "%2d\t", time);
                fprintf(outputFile, "%c%d\t\t%d\t\t\t", (char)currentTask->task_id, 
                                                currentTask->remaining_time, 
                                                currentTask->priority);
                if(queue == NULL){
                    fprintf(outputFile, "--\n");
                }
                else{
                    printQueue(queue, outputFile);
                }
                time++;
            }

            currentTask->response_time += currentTask->wait_time;
            currentTask->completion_time = time + 1;
            head = currentTask->next;
            if(finished == NULL){
                finished = currentTask;
            }
            else{
                insertSortedFinished(finished, currentTask);
            }

            free(currentTask);
            
            if(queue != NULL && queue->priority < head->priority){
                struct task* temp = queue;
                queue = queue->next;
                temp = head;
                head = temp->next;
                priorityScheduling(temp, queue, finished, time, outputFile);
            }
            priorityScheduling(head, queue, finished, time, outputFile);
        }    
    }
}

void customScheduling(){

}

int main(int argc, char *argv[]) {
    FILE *inputFile = fopen(argv[2], "r");
    if(inputFile == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    //create the pointers for the tasks
    struct task* head = NULL;
    struct task* tail = NULL;

    //create the pointer for the queue
    struct task* queue = NULL;

    //create the pointer for the finished list
    struct task* finished = NULL;

    int task_counter = 0;
    int arrival_time, service_time, priority;
    int task_id;

    while(fscanf(inputFile, "%d %d %d", &arrival_time, &service_time, &priority) != EOF){
        if(task_counter < 26){
            task_id = 'A' + (task_counter++);
        }
        else{
            task_counter = 0;
            task_id = 'A' + (task_counter++);
        }

        struct task *new_task = initializeTask(task_id, arrival_time, service_time, priority);
        
        if(new_task != NULL){
            if(head == NULL){
                head = new_task;
                tail = new_task;
            }
            else{
                tail->next = new_task;
                tail = new_task;
            }
        }
    }
    fclose(inputFile);

    FILE *outputFile = fopen(argv[3], "w");
    if(outputFile == NULL){
        printf("Error opening file 2");
        exit(1);
    }

    if(strcmp(argv[1], "-prio") == 0){
        priorityCtr(head, queue, finished, outputFile);
    }

    fclose(outputFile);
}