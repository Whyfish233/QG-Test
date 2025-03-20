#ifndef _FUN_H
#define _FUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{     //搞一个关于图书的数据类型 
	char name[20];  //书名 
	int ISBN;       //ISBN号 
}BOOKL;

//定义链表结构体
typedef struct LNode{
	BOOKL data;
	struct LNode* next;
}LNode,*LinkedList; 

//函数声明
LinkedList InitList(BOOKL book);           //创建链表 
void insert(LinkedList*head,BOOKL book);  //插入节点 
void delete(LinkedList*head,char*name);   //删除节点 
LinkedList find(LinkedList head,char*name);//查找链表 
void printList(LinkedList head);              //打印链表 
void freeList(LinkedList head);				  //销毁链表 
void menu1();							//界面 
void backmenu1(); 						//界面的功能模块 


#endif 
