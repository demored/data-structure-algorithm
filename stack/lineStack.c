#include <stdio.h>
#include <stdlib.h>

//��ջ��ʹ��
typedef struct lineStack{
    int data;
    struct lineStack *next;
}lineStack;

//��ջ����
lineStack *push(lineStack *stack , int a){
    //����һ����ջ��Ԫ��
    lineStack * line = (lineStack*)malloc(sizeof(lineStack));
    line -> data = a;
    //�½ڵ��ͷ�ڵ㽨����ϵ
    line -> next = stack;
    stack = line;
    printf("��ջ��Ԫ��%d\n", a);
    return stack;
}

//��ջ����
lineStack *pop(lineStack *stack){
    if(stack){
        lineStack *p = stack;

        //��ͷָ�������ƶ�һλ
        stack = stack ->next;
        printf("��ջԪ��Ϊ%d\n", p->data);
        if(stack){
            printf("��ջ��Ԫ�أ�%d\n",stack->data);
        }else{
            printf("ջ�ѿ�\n");
        }

        free(p);
    }else{
        printf("ջ��û��Ԫ��");
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
