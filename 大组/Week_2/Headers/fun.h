#ifndef _FUN_H
#define _FUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

//����ṹ����
typedef struct ListNode {
    int data;           // ���������ԭdouble��Ϊint��
    char operator;      // �����
    struct ListNode* next;
} ListNode;
//�½�һ��������ʵ�ֵ�ջ�ṹ 
typedef struct{
    ListNode *top;
    int size;
}LinkedListStack; 

//��������
LinkedListStack *newLinkedListStack();//�����ڵ�
void delLinkedListStack(LinkedListStack* s);//����ջ
int size(LinkedListStack* s);//��ȡջ�ĳ���
bool isEmpty(LinkedListStack* s);//�ж�ջ�Ƿ�Ϊ��
void pushNum(LinkedListStack *s, int num);//��ջ�����֣�
void pushOp(LinkedListStack *s,char op);//��ջ�����ţ�
int peekNum(LinkedListStack *s);//����ջ��Ԫ��(���֣�  
char peekOp(LinkedListStack *s);//����ջ��Ԫ��(���ţ�
int popNum(LinkedListStack* s);//��ջ�����֣� 
char popOp(LinkedListStack* s);//��ջ������ 
int precedence(char op);// ��ȡ��������ȼ�
bool isOperator(char ch);// �ж��Ƿ�Ϊ�����
void zhuanyi(char* infix, char* postfix);// ��׺���ʽת��׺���ʽ
int jisuan(char* postfix);// �����׺���ʽ

#endif
