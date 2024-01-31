/*************************
 *Benjamin McDonnough  
 *CPSC 2311 006
 *mcdonn7@clemson.edu
 *************************/
#include "functions.h"


/*
* Parameters: FILE* in: this is the input file
*             given on the command line
*             FILE* out: this is the output file
*             specified on the command line
* Return:     sentenceCtr: the number of sentences
*             counted in the FILE* in.
* Counts the number of sentences in the file
* by checking the number of punctuations while
* also checking the character before the punctuation
* to ensure any extra punctuation is not counted
*/
void numSentences(FILE* in, FILE* out)
{
    int sentenceCtr = 0;
    char c;

    fseek(in, 0, SEEK_SET);

    char temp;

    while((c = fgetc(in)) != EOF){
        if(c == '.'|| c == '?' || c == '!')
        {
            //Check the character before the current one to 
            //make sure there are no repeats
            if(temp != '.' && temp != '?' && temp != '!')
            {
                //If no repeats, increment the sentence counter
                sentenceCtr++;
            }
        }
        //Change temp to the current char right before 
        //incrementing the current char
        temp = c;
    }
    //Print the number of sentences to the out file
    fprintf(out, "Total number of sentences: %d\n", sentenceCtr);

    fseek(in, 0, SEEK_SET);
}


/*
* Parameters: FILE* in: this is the input file
*             given on the command line
*             FILE* out: this is the output file
*             specified on the command line
* Return:     sentenceCtr: the number of sentences
*             counted in the FILE* in.
* Count the number of words in the file 
* by counting the number of spaces and \n
*/
void numWords(FILE* in, FILE* out)
{
    int wordCtr = 0;
    char c;

    //Loop through the file to check for spaces
    while((c = fgetc(in)) != EOF){
        if(c == ' ' || c == '\n')
        {
            //Increment the word counter
            wordCtr++;
        }
    }
    //Print the number of sentences to the out file
    fprintf(out, "Total number of words: %d", wordCtr);
}
