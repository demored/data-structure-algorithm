#include <stdio.h>

/**
 *  �����������洢˳�����
 *  �˷����������⣬ͷָ���βָ���غϵ㲻�Ϻ���
 */

//������
int inQueue(int *a , int rear, int data){
    a[rear] = data;
    rear++;
    printf("�����Ԫ��Ϊ%d\n", data);
    return rear;
}

//������
int outQueue(int *a, int front , int rear){
    while(front != rear){
        printf("������Ԫ��Ϊ%d\n", a[front]);
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