#include "stdio.h"
#include "stdlib.h"

//˳��ջ��ʹ��
int push(int *a , int top , int elem);
int pop(int *a , int top);

int push(int *a , int top , int elem){
    a[++top] = elem;
    return top;
}

int pop(int *a , int top){
    if(top == -1){
        printf("��ջ\n");
        return 0;
    }
    printf("����ջԪ��%d \n", a[top]);

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




