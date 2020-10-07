/*Given an array of integer numbers, rearrange the array so that all the zeros of the sequence 
appears in the first position of the array without changing the order between the non-zero elements.

Example:
Input    : [2, 3, 0, 4, 8, 0, 5, 9, 0, 11, 0, 45, 0, 23, 21, 0, 36]
Output : [0, 0, 0, 0, 0, 0, 2, 3, 4, 8, 5, 9, 11, 45, 23, 21, 36]*/

#include <iostream>
#include <bits/stdc++.h> 


using namespace std;

int main(){

    int array[] = {2, 3, 0, 4, 8, 0, 5, 9, 0, 11, 0, 45, 0, 23, 21, 0, 36};
    int lenght = sizeof(array)/sizeof(array[0]);

    int rearrangedArray[lenght] = {0};

    stack<int> s;

    int index = 0;

    for (size_t i = 0; i < lenght; i++)
    {
        if (array[i] == 0)
        {
            rearrangedArray[i] = 0;
            index++;
        }
        else
        {
            s.push(array[i]);
        }
    }
        
    cout << endl;

    for (size_t i = (lenght-1); i >= index; i--)
    {
        rearrangedArray[i] = s.top();
        s.pop();
    }
    
    for (size_t i = 0; i < lenght; i++)
    {
        cout << rearrangedArray[i] << " ";
    }

    cout << endl;

    return 0;
}
