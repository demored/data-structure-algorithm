#include<stdio.h>
#include<stdlib.h>
#define maxSize 6
//静态链表

typedef struct{
	int data; //数据
	int cur;	//游标

}component;
//初始化静态链表
int initArr(component *arr);
//创建备用链表
void reserveArr(component *arr);
//提取分配空间
int mallocArr(component * arr);

//创建备用链表
void reserveArr(component *arr){
 for (int i=0; i<maxSize; i++) {
        arr[i].cur = i+1; //将每个数组分量链接到一起
        arr[i].data = -1;
    }
    arr[maxSize-1].cur=0; //链表最后一个结点的游标值为0
}

//提取备用链表给数据链表
int mallocArr(component *arr){
	 int i = arr[0].cur; //取出第一个单元游标
	 if(arr[0].cur){
	 	//将备用链表指向下一个游标
	 	arr[0].cur = arr[i].cur;
	 }
	 return i;
}


int initArr(component *arr){
	reserveArr(arr);
	int body= mallocArr(arr);
	 //声明一个变量，把它当指针使，指向链表的最后的一个结点，因为链表为空，所以和头结点重合
    int tempBody=body;
    
    for (int i=1; i<4; i++) {
        int j=mallocArr(arr);//从备用链表中拿出空闲的分量
        arr[tempBody].cur=j;//将申请的空闲分量链接在链表的最后一个结点后面
        arr[j].data=i;		//给新申请的分量的数据域初始化
        tempBody=j;			//将指向链表最后一个结点的指针后移
    }
    
    arr[tempBody].cur=0;//新的链表最后一个结点的指针设置为0
    return body;
}

void displayArr(component * array,int body){
	
    int tempBody=body;//tempBody准备做遍历使用
    while (array[tempBody].cur) {
        printf("%d,%d ",array[tempBody].data,array[tempBody].cur);
        tempBody=array[tempBody].cur;
    }
    printf("%d,%d\n",array[tempBody].data,array[tempBody].cur);
}

int main(int argc, char **argv){
	
	component arr[maxSize];
	int body = initArr(arr);
	printf("静态链表为：\n");
	displayArr(arr, body);
	return 0;
}
