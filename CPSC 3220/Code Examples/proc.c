#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>


int main() {

  int cpid = fork(); 
     if (cpid > 0) {  // Parent process 
        printf("Printing from parent process\n");
        while(1){}    // inf_loop

     }else if (cpid == 0) {   // Child process 
        printf("Printing from child process\n");
        pid_t ppid = getppid();
        printf("Parent ID: %ld\n", (long) ppid);

        // kill your parent and take a nap
        kill(ppid, SIGKILL); // send kill signal
        sleep(3);

        printf("Parent Dead :( \n");

        // who is my new daddy? 
        ppid = getppid();
        printf("My new parent is:  %ld\n", (long) ppid);
     }  // end of else

return 0; }
