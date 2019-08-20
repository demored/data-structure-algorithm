#include<stdio.h>
#include<stdlib.h>

/**
 * ˫������
 */

typedef struct line{
    struct line * prior;
    int data;
    struct line * next;
}line;

//˫������Ĵ���
line * initLine(line *head);


//���˫������
void display(line *head);


int main(int argc , char **argv){
	printf("˫������\n");

	line *head = NULL;
	head = initLine(head);

	display(head);

	printf("����������ֵΪ%d\n", head -> next -> next ->data);
    printf("����������ֵΪ%d\n", head -> next -> next ->next->prior->data);
	return 0;
}

line * initLine(line *head){
    //����һ����Ԫ�ڵ�
    head = (line *)malloc(sizeof(line));
    head -> prior = NULL;
    head -> next = NULL;
    head -> data = 1;

    line *list = head;
    for (int i = 2 ; i <= 5 ; i++){
        line *body = (line *) malloc(sizeof(line));
        body -> prior = NULL;
        body -> next = NULL;
        body -> data = i;

        list -> next = body;
        body -> prior = list;

        list = list -> next;

    }

    return head;
}

void display(line *head){
    line *tmp = head;
    while(tmp){
        if(tmp -> next == NULL){
            printf("%d\n", tmp -> data);
        }else{
            printf("%d <-> ", tmp ->data);
        }
        tmp = tmp -> next;
    }
}

