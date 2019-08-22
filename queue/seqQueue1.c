#include <stdio.h>

/**
 *  采用数组来存储顺序队列
 *  此方法存在问题，头指针和尾指针重合点不断后移
 */

//进队列
int inQueue(int *a , int rear, int data){
    a[rear] = data;
    rear++;
    printf("入队列元素为%d\n", data);
    return rear;
}

//出队列
int outQueue(int *a, int front , int rear){
    while(front != rear){
        printf("出队列元素为%d\n", a[front]);
        front++;
    }
    return front;
}

int main(){
    int a[100];
    int front,rear;
    front=rear = 0;
    rear = inQueue(a, rear, 10);
    rear = inQueue(a, rear, 13);
    front = outQueue(a, front,rear);
}