#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char * argv[]) {
    char message[1024];
    //Copy the first argument into the message variable excluding the escape character
    strncpy(message, argv[1], sizeof(message)-1);
    //Create your salt variable
    const char *salt = "$6$18zMX3QW9QV5l3a1$";
    
    char hashed_message[1024];
    //Encrypt the message using the crypt function and place it in variable hashed_message
    strcpy(hashed_message, crypt(message, salt));
    write(STDOUT_FILENO, hashed_message, strlen(hashed_message));
    return 0;
}