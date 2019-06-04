#include <stdio.h>
#include<stdlib.h>
//单链表基本操作
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
		printf("%d ", temp ->elem);
		temp = temp -> next;
	}
	printf("\n");
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


/*
	p 要插入的单链表
	pos 要插入的位置
	add 要插入的元素
*/
link * addElem(link *p , int pos , int add){
	link *temp = p; //创建一个指针遍历单链表，这个可以看成是头指针

	for(int i = 1 ; i < pos ; i++){
		if(temp == NULL){
			printf("插入位置无效\n");
			return p;
		}
		temp = temp -> next; //将指针移动到插入的位置

	}


	//创建一个插入的节点

	link *c = (link *)malloc(sizeof(link));
	c -> elem = add;
	c ->next = temp -> next;
	//将temp 指针
	temp ->next = c;
	return p;
}

//删除单链表某个元素
link * deleteElem(link *p, int pos){
	link *temp = p;
	//根据具体的位置
	for(int i = 1 ; i < pos-1 ; i++){
		temp = temp ->next;
	}
	//创建一个节点指向要删除的节点，便于回收内存
	link *del = temp ->next;
	temp->next = temp ->next->next;
	free(del);

	return p;
}

//修改某个位置的元素

link * updateElem(link *p , int pos , int newElem){
	link *temp = p;
	//指向首元节点，因为本例中创建的是含有头节点的单链表
	temp = temp -> next;
	for(int i = 1; i < pos; i++){
		temp = temp -> next;
	}
	temp -> elem = newElem;
	return p;
}

//查找某个位置上的元素
int findElem(link *p , int pos){
	link *temp = p;
	for(int i = 1 ; i <= pos ; i++){
		if(temp == NULL){
			printf("位置输入失败\n");
			exit(0);
		}
		if(pos == i){
			return temp -> elem;
		}
		temp = temp -> next;
	}
	
}

//查找某个元素的位置

int findPos(link *p , int elem){
	link *temp = p;
	int i = 1;
	while(temp->next){

		if(temp -> elem == elem){
			return i;
		}
		i++;
	}
	return -1;
}

int main(int argc, char *argv[]){
	//初始化一个没有头结点单链表
	link *t = initListNoHeadNode();
	//输出单链表
	displayListNoHeadNode(t);

	link * t1 = addElem(t, 2,100);
	displayListNoHeadNode(t1);

	link *t2 = deleteElem(t1 , 3);
	displayListNoHeadNode(t2);

	link *t3 = updateElem(t2 , 2, 66);
	displayListNoHeadNode(t3);

	int elem = findElem(t3, 2 );
	printf("第2个位置的元素为%d\n", elem);

	int pos = findPos(t3, 66);
	printf("66的位置是%d\n", pos);

	free(t1);
	free(t2);
	free(t3);

	return 0;
}

