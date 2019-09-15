#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 字符串的块链存储结构
 */



//定义每个节点存储的数据个数
#define linkNum 3

typedef struct Link{
    char a[linkNum];
    struct Link *next;
}link;

link * initLink(link *head , char *str);
void displayLink(link *head);

//字符串的块链结构
link *initLink(link *head , char *str){
    int length = strlen(str);
    //总的节点数
    int num = length / linkNum;
    if(length % linkNum){
        num++;
    }
    //创建并初始化首元节点
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

//输出链表
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
    //字符串的顺序存储结构
//    char str[20] = "hello";
//    printf("string is %s", str);
//    //字符串的长度
//    printf("string length is %d", strlen(str));

    link *head = NULL;
    head = initLink(head, "this is data structure");
    displayLink(head);

    return 0;
}





