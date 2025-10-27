#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_FD 0
#define WRITE_FD 1

struct Date{
    int day;
    int month;
    int year;
};

void *calculate_days_left(void* data){
    struct Date *future_date = (struct Date*)(data);
    time_t now = time(NULL);  // get the current time
    struct tm *local_time = localtime(&now);   // convert to local time

    struct Date *date_difference;
    date_difference->month = 0;
    date_difference->year = 0;
    date_difference->day = future_date->day - local_time->tm_mday;

    if(date_difference->day < 0){
        date_difference->month -= 1;
        date_difference->day *= -1;

        int month_before_fut_mon = future_date->month - 1;

        if(month_before_fut_mon == 0 || month_before_fut_mon == 1 || month_before_fut_mon == 3 ||
           month_before_fut_mon == 5 || month_before_fut_mon == 7 || month_before_fut_mon == 9 ||
           month_before_fut_mon == 10 || month_before_fut_mon == 12){
            date_difference->day = 31 - date_difference->day;
        } else if(month_before_fut_mon == 3 || month_before_fut_mon == 5 || month_before_fut_mon == 7 ||
                month_before_fut_mon == 10) {
            date_difference->day = 30 - date_difference->day;
        } else{
            date_difference->day = 28 - date_difference->day;
        }
    }

    date_difference->month += future_date->month - (local_time->tm_mon + 1);

    if(date_difference->month < 0){
        date_difference->year--;
        date_difference->month *= -1;

        date_difference->month = 12 - date_difference->month;
    }

    int current_year = local_time->tm_year + 1900;
    date_difference->year += future_date->year - current_year;

    return (void *)date_difference;
}
int main(int argc, char* argv[]){
    
    bool isValid = false;
    int counter = 0;

    //Check to make sure there are the correct number of command line arguments. 
    do
    {
        if(argc != 3){
            isValid = false;
            fprintf(stderr,"Error: Incorrect number of arguments.\n");
            counter++;
        }
        else{
            isValid = true;
        }
        if(counter == 3){
            return 1;
        }
    } while (!isValid);
    

    char word [1024];
    strncpy(word, argv[1], sizeof(word) - 1);

    struct Date future_date;

   sscanf(argv[2], "%d/%d/%d", &future_date.month, &future_date.day, &future_date.year);

   pid_t pid1, pid2;
   int status;
   int link[2];
   char sha_of_word[1024];

   if(pipe(link) == -1){
        perror("pipe");
        exit(1);
   }

   pid1 = fork();
   if (pid1 == 0){
        printf("Child1: pid: %d, ppid: %d, SHA512 of %s is:", getpid(), getppid(), word);
        fflush(stdout);
        close(link[READ_FD]);
        execl("./sha512hash", "sha512hash", word, NULL);
        read(link[READ_FD], &sha_of_word, sizeof(sha_of_word));
        perror("execl");
        exit(EXIT_FAILURE);
   } 
   else{
        close(link[WRITE_FD]);
        wait(NULL);
   }

   pid2 = fork();
   if(pid2 == 0){
        pthread_t tid;
        void *ret_val;
        pthread_create(&tid, NULL, calculate_days_left, (void *)&future_date);
        pthread_join(tid, &ret_val);

        struct Date* date_difference = (struct Date*)ret_val;

        printf("\nChild2: pid: %d, ppid: %d\n\tThread 1: tid %ld\n\tTime until %s is %d days, %d months and %d years\n", 
               getpid(), getppid(), tid, argv[2], date_difference->day, date_difference->month, date_difference->year);
   }
   else{
        waitpid(pid2, &status, 0);
   }

    
}