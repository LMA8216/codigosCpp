#include <iostream>

using namespace std;

int binarySearch(int A[],int low, int high, int data){

    int mid = low + (high - low)/2;
    
    if(low > high){
        cout << "O numero não está na lista";
        return -1;
    }
    if(A[mid] == data)
        return mid;

    if(data < A[mid]){
        binarySearch(A, low, mid-1, data);
    }
    else{
        binarySearch(A, mid+1, high, data);
    }
}

int main(){

    int array[] = {0,3,4,6,9,13,15,21,30};
    int lenght = sizeof(array)/sizeof(array[0]);

    int indiceToFind;
    cin >> indiceToFind;
    cout << "O indice procurado é " << binarySearch(array, 0, lenght, indiceToFind) << endl;
    return 0;
}