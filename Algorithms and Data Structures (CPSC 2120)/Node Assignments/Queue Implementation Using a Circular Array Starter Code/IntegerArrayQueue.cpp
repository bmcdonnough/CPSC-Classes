#include "IntegerArrayQueue.h"

/*Checks to see if the queue is full.
* If queue is full, then return false.
* If queue is not full, then enqueue value and return true;
*/ 
bool IntegerArrayQueue::enqueue(int value)
{
    /*Checks to see if the queue is full by
    * seeing if the remainder of back index + 1
    * % size is equal to front since the only time
    * that they will be equal is when the 
    * back index is at position size - 1.
    */
    


    if(((back + 2) % size == front)){ 
        return false;
    }
    else {
        back = (back + 1) % size;
        array[back] = value;
        return true;
    }
}

/*Checks to see if the queue is emtpy
* If the queue is empty, then return 0;
* If the queue is not empty, then return the dequeue value 
* (Top of the queue)
*/
int IntegerArrayQueue::dequeue()
{
    /*Check if the queue is empty by seeing
    * if the front and back indexes are at
    * the same position.
    * 
    * If the queue is not empty, 
    * then store the value at front into
    * a temp variable, increment the front index
    * and return the temp variable
    */
   
    if(front == back){
        return 0;
    }
    else{
        int temp = array[front];
        front = (front + 1) % size;
        return temp;
    }
}