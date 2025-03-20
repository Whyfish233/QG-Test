#ifndef _FUN_H
#define _FUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {     // 图书数据结构
    char name[20];   // 书名
    int ISBN;        // ISBN号
} BOOKL;

// 双向链表节点结构
typedef struct LNode {
    BOOKL data;
    struct LNode* prev;  // 指向前一个节点
    struct LNode* next;  // 指向下一个节点
} LNode, *LinkedList;

// 函数声明
LinkedList InitList(BOOKL book);           // 初始化链表
void insert(LinkedList* head, BOOKL book); // 插入节点
void delete(LinkedList* head, char* name); // 删除节点
LinkedList find(LinkedList head, char* name); // 查找节点
void printList(LinkedList head);           // 打印链表
void freeList(LinkedList head);            // 销毁链表
void menu1();                              // 菜单
void backmenu1();                          // 菜单功能模块

#endif
