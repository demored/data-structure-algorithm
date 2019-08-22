#include <stdio.h>
#include <stdlib.h>

//链栈的使用
typedef struct lineStack{
    int data;
    struct lineStack *next;
}lineStack;

//入栈操作
lineStack *push(lineStack *stack , int a){
    //创建一个入栈的元素
    lineStack * line = (lineStack*)malloc(sizeof(lineStack));
    line -> data = a;
    //新节点和头节点建立联系
    line -> next = stack;
    stack = line;
    printf("入栈的元素%d\n", a);
    return stack;
}

//出栈操作
lineStack *pop(lineStack *stack){
    if(stack){
        lineStack *p = stack;

        //将头指针往后移动一位
        stack = stack ->next;
        printf("出栈元素为%d\n", p->data);
        if(stack){
            printf("新栈顶元素：%d\n",stack->data);
        }else{
            printf("栈已空\n");
        }

        free(p);
    }else{
        printf("栈内没有元素");
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
