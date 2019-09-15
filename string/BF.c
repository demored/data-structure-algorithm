#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * �ַ���ƥ��BF�㷨
 */
//a���ִ���b������
int mate(char *a , char *b){
    int lenA = strlen(a);
    int lenB = strlen(b);
    int i=0,j=0;
    while(i < lenA && j <lenB){
        if(a[i] == b[j]){
            i++;
            j++;
        }else{
            j = j-i+1;
            i = 0;
        }
    }

    if(i == lenA){
        return j-lenA+1;
    }
}

int main(int argc , char *argv[]){

    char *A = "abc";
    char *B = "bacghabcde";
    int pos = mate(A,B);
    printf("A��B�е�λ��Ϊ%d", pos);
    return 0;
}