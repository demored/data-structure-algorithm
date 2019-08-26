#include <stdio.h>

// seq queue kind 1

//in queue
int inQueue(int *a , int rear, int data){
    a[rear] = data;
    rear++;
    printf("in queue data:%d\n", data);
    return rear;
}

//out queue
int outQueue(int *a, int front , int rear){
    while(front != rear){
        printf("out queue data:%d\n", a[front]);
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