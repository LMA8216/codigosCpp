/*Create an algorithm to find the index of an element in an array containing an ordered sequence of integers. 
The sequence is not necessarily composed of consecutive numbers.
[1,4,5,7,8,12,34,56,78,90,100]
*/

#include <iostream>

using namespace std;

int findIndex(int element, int array[]){

    int lenght = sizeof(array)/sizeof(array[0]);
    int indexToFind = 0;
    
    for (size_t i = 0; i < lenght; i++)
    {
        if(array[i] == element){
            indexToFind = i;
        }
    }

    cout << indexToFind;

    return indexToFind;        
}

int main(){

    int arr[] = {1,4,5,7,8,12,34,56,78,90,100};

    cout << findIndex(90,arr) << endl;

    return 0;
}

