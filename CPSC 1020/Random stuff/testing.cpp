#include <iostream>
using namespace std;
 
int main(void)
{
    int arr[] = {10, 20};
    int *p = arr;
    ++*p;

    cout << "arr[0] = " << arr[0];
    cout << ", arr[1] = " << arr[1];
    cout << ", *p = " << *p << endl;

    return 0;
 }