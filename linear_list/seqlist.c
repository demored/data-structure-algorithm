#include<stdio.h>
#include <stdlib.h>
//顺序表的初始化
#define SIZE 5 //定义分配的内存大小
typedef struct Table{
	int *head; //定义一个名为head的定长数组
	int length;//当前数组的长度
	int size;//顺序表分配的大小

}table;

//顺序表初始化

table initTable(){
	table t;
	t.head = (int *)malloc(SIZE * sizeof(int) );
	if(!t.head){
		printf("初始化失败");
		exit(0);
	}

	t.size = SIZE;
	t.length = 0;
	return t;
}

//输出顺序表

void displayTable(table t){
	for (int i = 0 ; i < t.length ; i++){
		printf("%d\n", t.head[i]);
	}
	printf("\n");
}

int main(int argc , char *argv[]){
	//初始化一个顺序表
	table t = initTable();
	//给顺序表添加数据
	for (int i = 1 ; i <= SIZE; i++){
		t.head[i-1] = i;
		t.length++;
	}

	displayTable(t);


}


