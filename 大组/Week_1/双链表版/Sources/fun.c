#include "fun.h"

// 初始化链表节点
LinkedList InitList(BOOKL book) {
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = book;
    newNode->prev = NULL;  // 初始化 prev 指针
    newNode->next = NULL;  // 初始化 next 指针
    return newNode;
}

// 插入链表节点
void insert(LinkedList* head, BOOKL book) {
    LinkedList newNode = InitList(book);
    if (*head == NULL) {
        *head = newNode;  // 如果链表为空，新节点作为头节点
    } else {
        LinkedList temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;  // 找到链表的最后一个节点
        }
        temp->next = newNode;  // 将新节点插入到链表末尾
        newNode->prev = temp;  // 设置新节点的 prev 指针
    }
    printf("插入成功！\n");
}

// 删除节点
void delete(LinkedList* head, char* name) {
    if (*head == NULL) {
        printf("链表为空，无法删除\n");
        return;
    }
    LinkedList temp = *head;
    // 如果头节点是要删除的节点
    if (strcmp(temp->data.name, name) == 0) {
        *head = temp->next;  // 更新头节点
        if (*head != NULL) {
            (*head)->prev = NULL;  // 新头节点的 prev 指针置空
        }
        free(temp);  // 释放原头节点
        printf("删除成功: %s\n", name);
        return;
    }
    // 遍历链表查找要删除的节点
    while (temp != NULL && strcmp(temp->data.name, name) != 0) {
        temp = temp->next;
    }
    // 如果找到要删除的节点
    if (temp != NULL) {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;  // 前一个节点的 next 指向下一个节点
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;  // 下一个节点的 prev 指向前一个节点
        }
        free(temp);  // 释放节点
        printf("删除成功: %s\n", name);
    } else {
        printf("未找到图书: %s\n", name);
    }
}

// 查找节点
LinkedList find(LinkedList head, char* name) {
    LinkedList temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            return temp;  // 返回找到的节点
        }
        temp = temp->next;
    }
    printf("未找到图书: %s\n", name);
    return NULL;  // 未找到
}

// 打印链表
void printList(LinkedList head) {
    LinkedList temp = head;
    while (temp != NULL) {
        printf("书名: %s, ISBN: %d\n", temp->data.name, temp->data.ISBN);
        temp = temp->next;
    }
}

// 销毁链表
void freeList(LinkedList head) {
    LinkedList temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);  // 释放当前节点
    }
    printf("链表已销毁\n");
}

// 菜单
void menu1() {
    system("cls");
    printf("*---------------------------------图书管理系统-------------------------------------*\n");
    printf("*                                                                                  *\n");
    printf("*-----------------------------------功能列表---------------------------------------*\n");
    printf("*                                                                                  *\n");
    printf("*1.添加图书信息                  2.查询指定图书信息          3.删除图书信息        *\n");
    printf("*4.销毁链表                      5.修改图书信息              0.退出系统            *\n");
    printf("*----------------------------------------------------------------------------------*\n");
}

// 菜单功能模块
void backmenu1() {
    LinkedList head = NULL;
    char name[20];
    int c = 233;
    BOOKL book;
    while (c != 0) {
        menu1();
        printf("请选择你想要使用的功能：");
        scanf("%d", &c);
        switch (c) {
            case 0:
                printf("您已成功退出图书管理系统！！！\n");
                system("pause");
                return;
            case 1:
                printf("请输入书名：");
                scanf("%s", book.name);
                printf("请输入ISBN号：");
                scanf("%d", &book.ISBN);
                insert(&head, book);
                break;
            case 2:
                printf("请输入要查找的书名：");
                scanf("%s", name);
                LinkedList result = find(head, name);
                if (result != NULL) {
                    printf("找到图书: 书名: %s, ISBN: %d\n", result->data.name, result->data.ISBN);
                }
                break;
            case 3:
                printf("请输入要删除的书名：");
                scanf("%s", name);
                delete(&head, name);
                break;
            case 4:
                freeList(head);
                head = NULL;
                break;
            case 5:
                printf("请输入要查找的书名：");
                scanf("%s", name);
                LinkedList res = find(head, name);
                if (res != NULL) {
                    printf("你要改成什么书名：");
                    scanf("%s", res->data.name);
                    printf("\n你要改成什么ISBN：");
                    scanf("%d", &res->data.ISBN);
                    printf("修改成功！\n");
                }
                break;
            default:
                printf("无效的选择！\n");
                break;
        }
        system("pause");
    }
}
