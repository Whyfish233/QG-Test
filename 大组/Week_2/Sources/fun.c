#include "fun.h"

//构建节点
LinkedListStack *newLinkedListStack() {
    LinkedListStack *s = malloc(sizeof(LinkedListStack));
    if (!s) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    s->size = 0;
    return s;
}
//消除栈
void delLinkedListStack(LinkedListStack *s) {
    while (s->top) {
        ListNode *n = s->top->next;
        free(s->top);
        s->top = n;
    }
    free(s);
}
//获取栈的长度
int size(LinkedListStack *s) {
    return s->size;
}
//判断栈是否为空
bool isEmpty(LinkedListStack *s) {
    return size(s) == 0;
}
//入栈（数字）
void pushNum(LinkedListStack *s, int num) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (!node) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    node->next = s->top;
    node->data = num;
    node->operator = '\0';
    s->top = node;
    s->size++;
}
//入栈（符号）
void pushOp(LinkedListStack *s, char op) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (!node) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    node->next = s->top;
    node->operator = op;
    node->data = 0;  // 清除冗余的浮点赋值
    s->top = node;
    s->size++;
}
//访问栈顶元素(数字）  
int peekNum(LinkedListStack *s) {
    if (isEmpty(s)) {
        printf("栈为空\n");
        return INT_MAX;
    }
    return s->top->data;
}
//访问栈顶元素(符号）
char peekOp(LinkedListStack *s) {
    if (isEmpty(s)) {
        printf("栈为空\n");
        return '\0';
    }
    return s->top->operator;
}
//出栈（数字）
int popNum(LinkedListStack* s) {
    if (isEmpty(s)) {
        printf("栈为空\n");
        return INT_MAX;
    }
    int val = s->top->data;  // 修正为int
    ListNode *tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    s->size--;
    return val;
}
//出栈（符号 
char popOp(LinkedListStack* s) {
    if (isEmpty(s)) {
        printf("栈为空\n");
        return '\0';
    }
    char op = s->top->operator;
    ListNode *tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    s->size--;
    return op;
}
// 获取运算符优先级
int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}
// 判断是否为运算符
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
// 中缀表达式转后缀表达式
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
// 计算后缀表达式
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
                        printf("错误：除数不能为零\n");
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
