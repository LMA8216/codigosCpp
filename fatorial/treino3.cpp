#include <iostream>
// algortimo usando recursão para resolver fatorial 
using namespace std;

int isSortedArray(int array[], int n){

    if (n == 1)
    {
        return 1;
    }

    return ( array[n-1] < array[n-2] ? 0 : isSortedArray(array, n-1));
    
}


int main(){

    int arr[] = {1,2,3,4,9,11};

    int size = sizeof(arr)/sizeof(arr[0]);

    cout << isSortedArray(arr,size) << endl;
    return 0;
}