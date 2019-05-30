#include<stdio.h>
#include <stdlib.h>

//单链表
typedef struct Link{
	char elem;
	struct Link *next;
}link;

//单链表初始化
//创建不含头结点的单链表
link * initListNoHeadNode(){
	//初始化头指针
	link *p = NULL;
	//创建首元节点
	link *temp = (link *)malloc(sizeof(link));

	//首元节点初始化
	temp -> elem = 1;
	temp -> next = NULL;

	p = temp;//头指针指向首元节点

	//从第2个节点开始创建

	for (int i = 2 ; i<5 ; i++){
		link *a = (link *)malloc(sizeof(link));
		a -> elem = i;
		a->next = NULL;

		//将temp指针指向a
		temp -> next = a;

		temp = temp -> next;
	}

	return p;

}

//创建一个含头结点的单链表

link * initListHaveHeadNode(){
	//创建一个头结点
	link *p = (link *)malloc(sizeof(link));
	link *temp = p; //声明一个指针指向头结点
	//生成链表
	for(int i = 1; i < 5 ; i++){
		link *a = (link *)malloc(sizeof(link));
		a -> elem = i;
		a->next = NULL;
		temp -> next = a;
		temp = temp -> next;
	}

	return p;
} 

//输出单链表,不含有头结点
void displayListNoHeadNode(link *p){
	printf("输出单链表\n");
	link *temp = p;
	while(temp){
		printf("%d\n", temp ->elem);
		temp = temp -> next;
	}
}
//输出单链表，含有头结点的
void displayListHaveHeadNode(link *p){
	printf("输出单链表\n");
	link *temp = p;
	while(temp -> next){
		temp = temp -> next;
		printf("%d\n", temp ->elem);
		
	}
}

int main(int argc, char *argv[] ){
	//创建含有含有头结点的单链表
	link *p = initListHaveHeadNode();
	displayListHaveHeadNode(p);
	
	//创建不含头结点的单链表

	link *p1 = initListNoHeadNode();
	displayListNoHeadNode(p1);
	
	return 0;
}