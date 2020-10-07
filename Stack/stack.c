#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10;

struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *CreateStack()
{
    struct ArrayStack *S=(struct ArrayStack *) malloc(sizeof(struct ArrayStack));
    if(!S)
        return NULL;
    S->capacity = MAX_SIZE;
    S->top = -1;
    S->array =(int *) malloc(S->capacity*sizeof(int));

    if(!S->array)
        return NULL;
    return S;
};

int isEmptyStack(struct ArrayStack *S){
    return(S->top == -1);
}

int isFullStack(struct ArrayStack *S){
    return(S->top == S->capacity - 1);
}

void push(struct ArrayStack *S, int data){
    if(isFullStack(S)){
        printf("A pilha está cheia\n");
    }
    else
        S->array[++S->top] = data; 
}

int pop(struct ArrayStack *S){
    if(isEmptyStack(S)){
        printf("A pilha esta vazia\n");
        return __INT_MAX__;
    }
    else{
        
        return (S->array[S->top--]);
    }
}

void deleteStack(struct ArrayStack *S){
    if(S){
        if(S->array)  
            free(S->array);
        free(S);
    }
}

int main(){

    struct ArrayStack *stack = CreateStack();

    push(stack, 3);

    printf("o valor do top é %d", pop(stack));

    deleteStack(stack);

    return 0;
}

