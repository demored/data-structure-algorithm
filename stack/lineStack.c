#include <stdio.h>
#include <stdlib.h>

//????????
typedef struct lineStack{
    int data;
    struct lineStack *next;
}lineStack;

//???????
lineStack *push(lineStack *stack , int a){
    //???????????????
    lineStack * line = (lineStack*)malloc(sizeof(lineStack));
    line -> data = a;
    //??????????????
    line -> next = stack;
    stack = line;
    printf("????????%d\n", a);
    return stack;
}

//pop stack
lineStack *pop(lineStack *stack){
    if(stack){
        lineStack *p = stack;

        //??????????????¦Ë
        stack = stack ->next;
        printf("???????%d\n", p->data);
        if(stack){
            printf("?????????%d\n",stack->data);
        }else{
            printf("????\n");
        }

        free(p);
    }else{
        printf("?????????");
        return stack;
    }
    return stack;
}

int main(int argc , char **argv){
    lineStack *stack = NULL;
    stack = push(stack, 1);
    stack = push(stack, 2);

    stack = pop(stack);
    stack = pop(stack);
}
