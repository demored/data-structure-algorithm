#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * �ַ����Ŀ����洢�ṹ
 */



//����ÿ���ڵ�洢�����ݸ���
#define linkNum 3

typedef struct Link{
    char a[linkNum];
    struct Link *next;
}link;

link * initLink(link *head , char *str);
void displayLink(link *head);

//�ַ����Ŀ����ṹ
link *initLink(link *head , char *str){
    int length = strlen(str);
    //�ܵĽڵ���
    int num = length / linkNum;
    if(length % linkNum){
        num++;
    }
    //��������ʼ����Ԫ�ڵ�
    head = (link *)malloc(sizeof(link));
    head -> next = NULL;
    link * temp = head;
    for(int i = 0; i <num ; i++){
        int j = 0;
        for (; j < linkNum ; j++){
            if(i*linkNum +j < length){
                temp -> a[j] = str[i*linkNum + j];
            }else{
                temp -> a[j] = '#';
            }
        }

        if(i * linkNum +j < length){
            link *newLink = (link *)malloc(sizeof(link));
            newLink -> next = NULL;
            temp -> next = newLink;
            temp = newLink;
        }
    }

    return head;
}

//�������
void displayLink(link *head){
    link *temp = head;
    while (temp) {
        for (int i = 0 ; i < linkNum ; i++){
            printf("%c", temp -> a[i]);
        }
        temp = temp -> next ;
    }
}

int main(int argc, char **argv){
    //�ַ�����˳��洢�ṹ
//    char str[20] = "hello";
//    printf("string is %s", str);
//    //�ַ����ĳ���
//    printf("string length is %d", strlen(str));

    link *head = NULL;
    head = initLink(head, "this is data structure");
    displayLink(head);

    return 0;
}





