#include <stdio.h>
#include<stdlib.h>
#define Size 5
//顺序表的基本操作
//添加、删除节点
typedef struct {
	int *head;
	int length; //当前顺序表的大小
	int size;  //顺序表分配内存的大小
}seqlist;

//初始化顺序表
seqlist init(){
	seqlist t;
	if((t.head = (int *)malloc( Size * sizeof(int))) == NULL){
		printf("分配内存失败\n");
	}else{
		printf("分配内存成功\n");
	}
	
	t.size = Size;
	t.length = 0;
	return t;
}

//输出顺序表
void display(seqlist t){

	printf("输出顺序表\n");

	for (int i = 0 ; i < t.length ; i++){
		printf("%d ", t.head[i]);
	}
	printf("\n");
}

//插入元素
/**
	elem需要添加的元素
	pos 添加的位置
**/
seqlist add(seqlist t, int elem , int pos){
	if(pos > t.length +1 || pos < 1){
		printf("添加的位置有误\n");
		exit(0);
	}

	//如果分配的内存不够，则分配内存
	if(t.length == t.size){
		//在之前的基础上分配
		if((t.head = (int *) realloc(t.head , (t.size+1) * sizeof(int))) == NULL){
			printf("动态分配内存失败\n");
			exit(0);
		}
		t.size += 1;
	}

	for(int i = t.length -1 ; i >= pos-1 ;i--){
		t.head[i] = t.head[i-1];
	}

	t.head[pos-1] = elem;
	t.length ++;
	return t;
}

/*
	删除顺序表位置的元素
	将前面一个数往前移一位
*/
seqlist deleteTable(seqlist t , int pos){
	if (pos > t.length || pos<1) {
        printf("被删除元素的位置有误");
        exit(0);
    }

	for (int i = pos ; i< t.length ; i++){
		t.head[i-1] = t.head[i];
	}
	t.length--;
	return t;
}

/*
	顺序表查找
	elem 为查找的元素
	return 元素的直观位置
*/

int findElem(seqlist t , int elem){
	for (int i = 0 ; i < t.length ; i++){
		if(t.head[i] == elem){
			return i+1; 
		}
	}
}

/*
	修改元素elem 为newElem
*/

seqlist updateElem(seqlist t , int elem, int newElem){
	int pos = findElem(t,elem);
	t.head[pos-1] = newElem;
	printf("修改元素%d -> %d\n",elem, newElem);
	return t;
}


int main(int argc, char *argv[]){
	
	//初始化顺序表
	seqlist t = init();
	//给顺序表添加元素
	for(int i = 0 ; i < t.size ; i++){
		t.head[i] = i+1;
		 t.length++;
	}
	//输出顺序表
	display(t);
	
	printf("顺序表的长度为：%d\n", t.length);
	
	t = deleteTable(t , 2);
	display(t);
	
	//删除最后一个
	t = deleteTable(t , 4);
	display(t);

	int pos = findElem(t, 3);
	printf("元素3的位置是：%d\n", pos);

	display(t);
	t = updateElem(t, 3, 5);
	display(t);
	
	return 0;

}

