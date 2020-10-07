#include <iostream>

using namespace std;

/*D2 - Given an array of integers, sort the array into a wave like array and return it.  
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5 ...

Given [1, 2, 3, 4]
One possible answer: [2, 1, 4, 3]
Another possible answer: [4, 1, 3, 2]
*/

int main(){

    int array[] = {1,2,3,4};
    //int array[] = {-4,-1,2,3,5,6,7,10,13};
    
    int n = sizeof(array)/sizeof(array[0]);

    int waveArray[n];

    for (size_t i = 0; i < n; i = i+2)
    {
        // when the number of elements is odd, the last element should not change its emplace
        if ( (n%2) == 1 && i == (n-1))
        {
            waveArray[i] = array[i];
            break;
        }
        // swap with the element adjacent and increment in two the counter of step
        waveArray[i] = array[i+1];
        waveArray[i+1] = array[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << waveArray[i] << " " ;
    }
    
    return 0;
}