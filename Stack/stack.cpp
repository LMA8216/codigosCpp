#include <iostream>
#include <new>

using namespace std;

class MyStack
{
private:
    int top = -1;
    int capacity;
    int *array;

    MyStack *createStack();
public:
    MyStack(int);
    ~MyStack();

    bool isEmptyStack();

    bool isFullStack();

    void push(int);

    int pop();
};

MyStack::MyStack(int numElements)
{
    capacity = numElements;
    array = new(nothrow) int[capacity];
    if(array == nullptr)
        cout << "Error na alocação";
}

MyStack::~MyStack()
{
    delete[] array;
    cout << "Pilha deletada" << endl;
}

bool MyStack::isEmptyStack(){
    return(top == -1);
}

bool MyStack::isFullStack(){
    return(top == (capacity - 1));
}

void MyStack::push(int data){
    if(MyStack::isFullStack())
        cout << "A  pilha está cheia, aloque mais memoria" << endl;
    else
        array[++top] = data;
}

int MyStack::pop(){
    if(MyStack::isEmptyStack()){
        cout << "pilha está vazia, adicione algum dado" << endl;
        return INT8_MIN;
    }
    else
        return (array[top--]);
}


int main(){

    MyStack sk(5);

    sk.push(4);
    sk.push(3);

    cout << "O valor do topo é " << sk.pop() << endl;
    cout << "O valor do topo é " << sk.pop() << endl;

    return 0;
}