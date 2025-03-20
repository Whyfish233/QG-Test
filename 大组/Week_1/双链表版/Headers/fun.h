#ifndef _FUN_H
#define _FUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {     // ͼ�����ݽṹ
    char name[20];   // ����
    int ISBN;        // ISBN��
} BOOKL;

// ˫������ڵ�ṹ
typedef struct LNode {
    BOOKL data;
    struct LNode* prev;  // ָ��ǰһ���ڵ�
    struct LNode* next;  // ָ����һ���ڵ�
} LNode, *LinkedList;

// ��������
LinkedList InitList(BOOKL book);           // ��ʼ������
void insert(LinkedList* head, BOOKL book); // ����ڵ�
void delete(LinkedList* head, char* name); // ɾ���ڵ�
LinkedList find(LinkedList head, char* name); // ���ҽڵ�
void printList(LinkedList head);           // ��ӡ����
void freeList(LinkedList head);            // ��������
void menu1();                              // �˵�
void backmenu1();                          // �˵�����ģ��

#endif
