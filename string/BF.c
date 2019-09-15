#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * 字符串匹配BF算法
 */
//a是字串，b是主串
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
    printf("A在B中的位置为%d", pos);
    return 0;
}