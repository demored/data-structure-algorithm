#include "stdio.h"
#include "stdlib.h"

//顺心栈的使用
int push(int *a , int top , int elem);
int pop(int *a , int top);

int push(int *a , int top , int elem){
    a[++top] = elem;
    return top;
}

int pop(int *a , int top){
    if(top == -1){
        printf("空栈\n");
        return 0;
    }
    printf("弹出栈元素%d \n", a[top]);

    top--;
    return top;

}

int main(int argc , char **argv){
    int a[100];
    int top=-1;
    top = push(a, top, 1);
    top = push(a, top, 2);

//    printf("top:%d",top);

    top = pop(a, top);
    top = pop(a, top);
    return 0;
}




