#ifndef _FUN_H
#define _FUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

//链表结构内容
typedef struct ListNode {
    int data;           // 存放整数（原double改为int）
    char operator;      // 运算符
    struct ListNode* next;
} ListNode;
//新建一个以链表实现的栈结构 
typedef struct{
    ListNode *top;
    int size;
}LinkedListStack; 

//函数声明
LinkedListStack *newLinkedListStack();//构建节点
void delLinkedListStack(LinkedListStack* s);//消除栈
int size(LinkedListStack* s);//获取栈的长度
bool isEmpty(LinkedListStack* s);//判断栈是否为空
void pushNum(LinkedListStack *s, int num);//入栈（数字）
void pushOp(LinkedListStack *s,char op);//入栈（符号）
int peekNum(LinkedListStack *s);//访问栈顶元素(数字）  
char peekOp(LinkedListStack *s);//访问栈顶元素(符号）
int popNum(LinkedListStack* s);//出栈（数字） 
char popOp(LinkedListStack* s);//出栈（符号 
int precedence(char op);// 获取运算符优先级
bool isOperator(char ch);// 判断是否为运算符
void zhuanyi(char* infix, char* postfix);// 中缀表达式转后缀表达式
int jisuan(char* postfix);// 计算后缀表达式

#endif
