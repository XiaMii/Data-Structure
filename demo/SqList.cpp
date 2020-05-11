/**
 * SqList.cpp
 * 顺序表的基本使用
 * XiaMii 2020.2.10
*/
#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 5  //存储空间的初始分配量
#define LISTINCREMENT 10    //存储空间的分配增量

typedef int elemtype;   //元素类型
typedef struct
{
    elemtype *elem;     //存储空间基址
    int length;     //当前长度
    int size;       //当前分配的存储容量
}SqList;

/**
 * 构造一个新的顺序表
 **/
int InitList_Sq(SqList &L){
    L.elem = (elemtype *)malloc(LIST_INIT_SIZE * sizeof(elemtype));//分配存储空间
    if(!L.elem){return -1;}     //存储分配失败
    L.length = 0;       //长度为0
    L.size = LIST_INIT_SIZE;        //初始存储容量
    return 0;
}
/**
 * 插入顺序表
 **/
int InsertList(SqList &L,elemtype e,int i){
    if (i<1 || i>L.length + 1){return (-1);}//插入位置不合法
    if (L.length >= L.size){//存储空间已满
        elemtype *newbase;//新基址
        newbase = (elemtype *)realloc(L.elem,(L.size + LISTINCREMENT)*sizeof(elemtype));//重新分配存储空间
        if(!newbase){return -1;}//存储分配失败
        L.elem = newbase;
        L.size += LISTINCREMENT;
    }
    elemtype *q,*p;//p为表尾位置
    q = &(L.elem[i-1]);//插入位置
    for (p = &(L.elem[L.length -1]); p>=q; p--){
        *(p+1) = *p;//插入位置及之后的元素后移
    }
    *q = e;//插入e
    ++L.length;//表长加一
    return 0;
}
/**
 *  删除顺序表
 **/
int DeleteList(SqList &L,int i,elemtype &e){
    if(L.length == 0){return -1;}//为空表
    if(i<1 || i>L.length){return -1;}//删除位置不合法
    elemtype *q,*p;
    q = &(L.elem[i-1]);//删除位置
    p = &L.elem[L.length-1];//表尾位置
    e = *q;
    for (++q; p >= q; q++)//被删除元素之后的元素前移
    {
        *(q-1) = *q;
    }
    L.length--;//表长减一
    return 0;
}
/**
 *  按序号查找元素
 **/
int GetElem(SqList &L,int i,elemtype &e){
    if(i<1 || i>L.length){return -1;}
    e = L.elem[i-1];
    return 0;
}
/**
 *  按内容查找元素，返回值为序号
 **/
int GetElem(SqList &L,elemtype e){
    for (int i = 0; i < L.length; i++)
    {
        if(L.elem[i]==e){return (i+1);}
    }
    return -1;
}
/**
 *  主函数
 **/
int main(){
    SqList L;
    elemtype temp,temp2;
    elemtype *tempdata;
    if(-1==InitList_Sq(L)){
        printf("InitList_Sq error!\n");
    }
    printf("please input 10 number:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&temp);
        InsertList(L,temp,i+1);
    }
    DeleteList(L,3,temp2);
    printf("%d\n\n",temp2);
     for (int j = 1; j < L.length+1; j++)
    {
        GetElem(L,j,temp2);
        printf("%d\n",temp2);
    }
    system("pause");
    return 0;
}