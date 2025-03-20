#ifndef _FUN_H
#define _FUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{     //��һ������ͼ����������� 
	char name[20];  //���� 
	int ISBN;       //ISBN�� 
}BOOKL;

//��������ṹ��
typedef struct LNode{
	BOOKL data;
	struct LNode* next;
}LNode,*LinkedList; 

//��������
LinkedList InitList(BOOKL book);           //�������� 
void insert(LinkedList*head,BOOKL book);  //����ڵ� 
void delete(LinkedList*head,char*name);   //ɾ���ڵ� 
LinkedList find(LinkedList head,char*name);//�������� 
void printList(LinkedList head);              //��ӡ���� 
void freeList(LinkedList head);				  //�������� 
void menu1();							//���� 
void backmenu1(); 						//����Ĺ���ģ�� 


#endif 
