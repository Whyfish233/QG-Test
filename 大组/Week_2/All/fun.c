#include "fun.h"

//�����ڵ�
LinkedListStack *newLinkedListStack() {
    LinkedListStack *s = malloc(sizeof(LinkedListStack));
    if (!s) {
        printf("�ڴ����ʧ��\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    s->size = 0;
    return s;
}
//����ջ
void delLinkedListStack(LinkedListStack *s) {
    while (s->top) {
        ListNode *n = s->top->next;
        free(s->top);
        s->top = n;
    }
    free(s);
}
//��ȡջ�ĳ���
int size(LinkedListStack *s) {
    return s->size;
}
//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(LinkedListStack *s) {
    return size(s) == 0;
}
//��ջ�����֣�
void pushNum(LinkedListStack *s, int num) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (!node) {
        printf("�ڴ����ʧ��\n");
        exit(EXIT_FAILURE);
    }
    node->next = s->top;
    node->data = num;
    node->operator = '\0';
    s->top = node;
    s->size++;
}
//��ջ�����ţ�
void pushOp(LinkedListStack *s, char op) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (!node) {
        printf("�ڴ����ʧ��\n");
        exit(EXIT_FAILURE);
    }
    node->next = s->top;
    node->operator = op;
    node->data = 0;  // �������ĸ��㸳ֵ
    s->top = node;
    s->size++;
}
//����ջ��Ԫ��(���֣�  
int peekNum(LinkedListStack *s) {
    if (isEmpty(s)) {
        printf("ջΪ��\n");
        return INT_MAX;
    }
    return s->top->data;
}
//����ջ��Ԫ��(���ţ�
char peekOp(LinkedListStack *s) {
    if (isEmpty(s)) {
        printf("ջΪ��\n");
        return '\0';
    }
    return s->top->operator;
}
//��ջ�����֣�
int popNum(LinkedListStack* s) {
    if (isEmpty(s)) {
        printf("ջΪ��\n");
        return INT_MAX;
    }
    int val = s->top->data;  // ����Ϊint
    ListNode *tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    s->size--;
    return val;
}
//��ջ������ 
char popOp(LinkedListStack* s) {
    if (isEmpty(s)) {
        printf("ջΪ��\n");
        return '\0';
    }
    char op = s->top->operator;
    ListNode *tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    s->size--;
    return op;
}
// ��ȡ��������ȼ�
int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}
// �ж��Ƿ�Ϊ�����
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
// ��׺���ʽת��׺���ʽ
void zhuanyi(char* zhong, char* hou) {
    LinkedListStack *s = newLinkedListStack();
    int i = 0, j = 0;
    char ch, x;

    while ((ch = zhong[i++]) != '\0') {
        if (ch == ' ') continue;
        
        if (isdigit(ch)) {
            while (isdigit(zhong[i-1])) {
                hou[j++] = zhong[i-1];
                if (!isdigit(zhong[i])) break;
                ch = zhong[i++];
            }
            hou[j++] = ' ';
        } else if (ch == '(') {
            pushOp(s, ch);
        } else if (ch == ')') {
            while ((x = popOp(s)) != '(') {
                hou[j++] = x;
                hou[j++] = ' ';
            }
        } else if (isOperator(ch)) {
            while (!isEmpty(s) && precedence(ch) <= precedence(peekOp(s))) {
                hou[j++] = popOp(s);
                hou[j++] = ' ';
            }
            pushOp(s, ch);
        }
    }
    
    while (!isEmpty(s)) {
        hou[j++] = popOp(s);
        hou[j++] = ' ';
    }
    
    hou[j] = '\0';
    delLinkedListStack(s);
}
// �����׺���ʽ
int jisuan(char* hou) {
    LinkedListStack *s = newLinkedListStack();
    int i = 0;
    char ch;
    int num = 0;

    while ((ch = hou[i++]) != '\0') {
        if (isdigit(ch)) {
            num = 0;
            while (isdigit(ch)) {
                num = num * 10 + (ch - '0');
                ch = hou[i++];
            }
            pushNum(s, num);
            i--;
        } else if (ch == ' ') {
            continue;
        } else if (isOperator(ch)) {
            int b = popNum(s);
            int a = popNum(s);
            switch (ch) {
                case '+': pushNum(s, a + b); break;
                case '-': pushNum(s, a - b); break;
                case '*': pushNum(s, a * b); break;
                case '/':
                    if (b == 0) {
                        printf("���󣺳�������Ϊ��\n");
                        exit(EXIT_FAILURE);
                    }
                    pushNum(s, a / b);
                    break;
            }
        }
    }
    
    int result = popNum(s);
    delLinkedListStack(s);
    return result;
}
