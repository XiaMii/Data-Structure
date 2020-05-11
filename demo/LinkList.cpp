/**
 * LinkList.cpp
 * 单链表的基本使用和应用
 * XiaMii 2020.2.10
*/
#include <stdio.h>
#include <stdlib.h>

typedef int Datatype;
typedef struct LNode
{
    Datatype Data;
    LNode * Next;
}*LinkList;
//LNode为链表的结点类型
//LinkList为指向结点的指针类型（LinkList L;表示L指向头结点(==LNode * L;)）

/**
 * 建立头结点
*/
void InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if(L==NULL){return;}
    L->Next = NULL;
}
/**
 * 通过序号查找
*/
int GetElem(LinkList L,int i,Datatype &e){
    LNode* temp = L->Next;
    int j = 1;
    while (temp && j<i)
    {
        temp = temp->Next;
        j ++;
    }
    if (j>i||!temp){return -1;}
    e = temp->Data;
    return 0;
}
/**
 * 通过内容查找
*/
LNode* GetElem(LinkList L,Datatype e){
    LNode * temp = L->Next;
    while (temp)
    {
        if (e != temp->Data)
        {
            temp = temp->Next;
        }
        else
        {
            return temp;
        }
    }
    return 0;
}
/**
 * 通过内容定位
*/
int GetLocate(LinkList L,Datatype e){
    LNode * temp = L->Next;
    int i = 1;
    while (temp)
    {
        if (e != temp->Data)
        {
            temp = temp->Next;
            i++;
        }
        else
        {
            return i;
        }
    }
    return 0;
}
/**
 * 在单链表L第i个位置之前插入新元素e
*/
int InsertList(LinkList &L,int i,Datatype e){
    LNode * temp = L;
    int j = 0;
    while (temp && j<i-1)
    {
        temp = temp->Next;
        j++;
    }
    if (!temp||j>i-1){return -1;}
    LNode * NewLNode = (LNode *)malloc(sizeof(LNode));
    NewLNode->Data = e;
    NewLNode->Next = temp->Next;
    temp->Next = NewLNode;
    return 0;
}
/**
 * 在带头结点的单链表L中删除第i个元素，通过e返回其值
*/
int DeleteList(LinkList &L,int i,Datatype &e){
    LNode * temp = L;
    int j = 0;
    while (temp && j<i-1)
    {
        temp = temp->Next;
        j++;
    }
    if (!temp->Next || j>i-1){return -1;}
    LNode * deleteNode = temp->Next;
    e = deleteNode->Data;
    temp->Next = deleteNode->Next;
    deleteNode = NULL;
    return 0;
}
/**
 * 逆序输入n个元素的值，建立带头结点的单链表L
*/
void CreateList(LinkList &L,int n){
    L = (LinkList)malloc(sizeof(LNode));
    L->Next = NULL;
    LinkList p;
    for (int i = n; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->Data);
        p->Next = L->Next;
        L->Next = p;
    }
}
/**
 * 顺序输入n个元素的值（尾插法），建立带头结点的单链表L
*/
void CreateList_index(LinkList &L,int n){
    L = (LinkList)malloc(sizeof(LNode));
    L->Next = NULL;
    LinkList p,q;
    q = L;
    for (int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->Data);
        q->Next = p;
        q = p;
    }
    q->Next = NULL;
}
/**
 * 求表长
*/
int ListLength(LinkList L){
    int i = 0;
    while (L->Next)
    {
        L = L->Next;
        i++;
    }
    return i;
}
/**
 * 销毁链表
*/
int DestroyList(LinkList &L){
    LinkList p = L;
    LinkList q;
    while (p)
    {
        q = p;
        p = p->Next;
        q = NULL;
    }
    return 0;
}
/**
 * 如果在表A中出现的元素在表B也出现，则将表A中元素删除
*/
int DelElem(LinkList A,LinkList B){
    int i = 0;
    Datatype e;
    LinkList p = B->Next;
    while (p)
    {
        i = GetLocate(A,p->Data);
        if(i==0){
            p = p->Next;
        }
        else
        {
            DeleteList(A,i,e);
            if (e != p->Data)
            {
                return -1;
            }
        }
    }
    return 0;
}

int main(){
    LinkList A,B;
    printf("input 10 numbers for List A:\n");
    CreateList_index(A,10);
    printf("input 5 number for List B:\n");
    CreateList_index(B,5);
    DelElem(A,B);
    printf("A-B=\n");
    int n = ListLength(A);
    for (int i = 0; i < n; i++)
    {
        A = A->Next;
        printf("    %d\n",A->Data);
    }
    DestroyList(A);
    DestroyList(B);
    system("pause");
    return 0;
}

