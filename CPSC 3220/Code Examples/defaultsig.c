// Code source: devopedia.org
// Example shows a custom handler for SIGINT
// but the handler reverts to default action for future signals.
// Thus, first ctrl+c will allow program to continue
// and second ctrl+c will terminate the program.
 
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
 
void sig_handler1(int num)
{
	printf("You are here becoz of signal: %d\n", num);
	signal(SIGINT, SIG_DFL);
}
 
int main()
{
	signal(SIGINT, sig_handler1);
	while(1)
	{
		printf("Hello\n");
		sleep(2);
	}
}
