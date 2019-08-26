#include "stdio.h"
#include "stdlib.h"

typedef struct QNode{
    int data;           //storage data
    struct QNode *next; //next pointer
}QNode;

// link queue

// init queue
QNode *initQueue(){
    QNode *queue = (QNode *)malloc(sizeof(QNode));
    queue ->next = NULL;
    return queue;
}

//in queue

QNode *enQueue(QNode *rear , int data){
    QNode * enElem = (QNode *) malloc(sizeof(QNode));
    enElem -> data = data;
    enElem ->next = NULL;
    rear -> next = enElem;
    rear = enElem;

    return rear;
}

// out Queue

QNode *outQueue(QNode *top, QNode *rear){
    if (top ->next == NULL){
        printf("queue is nil \n");
        return rear;
    }

    QNode *p = top ->next;
    printf("out queue data :%d \n", p->data);

    top -> next = p->next;
    if(rear == p){
        rear = top;
    }

    return top;

}

int main(int agrc , char **argv){

    QNode *queue,*top,*rear;
    queue = top = rear = initQueue();

    rear=enQueue(rear, 1);
    rear=enQueue(rear, 2);
    rear=enQueue(rear, 3);
    rear=enQueue(rear, 4);

    rear=outQueue(top, rear);
    rear=outQueue(top, rear);
    rear=outQueue(top, rear);
    rear=outQueue(top, rear);
    rear=outQueue(top, rear);

    return 0;

}