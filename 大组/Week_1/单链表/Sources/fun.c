#include "fun.h"

//�½�����ڵ� 
LinkedList InitList(BOOKL book){        
	LinkedList newNode=(LinkedList)malloc(sizeof(LNode));
	if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newNode->data = book;  // ����������
    newNode->next = NULL;  // ��ʼ��ָ����
    return newNode;
	
}

//��������ڵ� 
void insert(LinkedList*head,BOOKL book){
	LinkedList newNode = InitList(book);
    if (*head == NULL) {
        *head = newNode;  // �������Ϊ�գ��½ڵ���Ϊͷ�ڵ�
    } 
	else {
        LinkedList temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;  // �ҵ���������һ���ڵ�
        }
        temp->next = newNode;  // ���½ڵ���뵽����ĩβ
    }
	printf("����ɹ���");	
}

//ɾ���ڵ� 
void delete(LinkedList*head,char*name) {
    if (*head == NULL) {
        printf("����Ϊ�գ��޷�ɾ��\n");
        return;
    }
    LinkedList temp = *head;
    LinkedList prev = NULL;
    // ���ͷ�ڵ���Ҫɾ���Ľڵ�
    if (strcmp(temp->data.name, name) == 0) {
        *head = temp->next;  // ����ͷ�ڵ�
        free(temp);          // �ͷ�ԭͷ�ڵ�
        printf("ɾ���ɹ�: %s\n", name);
        system("pause");
        return;
    }
	// �����������Ҫɾ���Ľڵ� 
    while (temp != NULL && strcmp(temp->data.name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    // ����ҵ�Ҫɾ���Ľڵ�
    if (temp != NULL) {
        prev->next = temp->next;  // ����Ҫɾ���Ľڵ�
        free(temp);               // �ͷŽڵ�
        printf("ɾ���ɹ�: %s\n", name);
        system("pause");
        return;
    } else {
        printf("δ�ҵ�ͼ��: %s\n", name);
        system("pause");
        return;
    }
}

// ���ҽڵ�
LinkedList find(LinkedList head,char*name) {
    LinkedList temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            return temp;  // �����ҵ��Ľڵ�
        }
        temp = temp->next;
    }
    printf("δ�ҵ�ͼ��: %s\n", name); 
    system("pause");
    return NULL;  // δ�ҵ�
}

// ��ӡ����
void printList(LinkedList head) {
    LinkedList temp = head;
    while (temp != NULL) {
        printf("����: %s, ISBN: %.2f\n", temp->data.name, temp->data.ISBN);
        temp = temp->next;
        system("pause");
    }
}

// ��������
void freeList(LinkedList head) {
    LinkedList temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);  // �ͷŵ�ǰ�ڵ�
    }
    printf("����������\n");
    system("pause");
}
//���� 
void menu1()
{
	system("cls");
	printf("*---------------------------------ͼ�����ϵͳ-------------------------------------*\n");
	printf("*                                                                                  *\n");
	printf("*-----------------------------------�����б�---------------------------------------*\n");
	printf("*                                                                                  *\n");
	printf("*1.���ͼ����Ϣ                  2.��ѯָ��ͼ����Ϣ          3.ɾ��ͼ����Ϣ        *\n");
	printf("*4.��������                      5.�޸�ͼ����Ϣ              0.�˳�ϵͳ            *\n");
	printf("*----------------------------------------------------------------------------------*\n");
 }  
 
//����Ĺ���ģ�� 
void backmenu1()
{
	LinkedList head = NULL;
	char name[20];
 	int c=233;
 	BOOKL book;
 	while(c!=0)
    {
    	menu1(); 
    	printf("��ѡ������Ҫʹ�õĹ��ܣ�") ;
		scanf("%d",&c);
    	switch(c)
    	{
     		case 0:printf("���ѳɹ��˳�ͼ�����ϵͳ������\n");
     			   system("pause");
			 	   return;   //�˳�
     		case 1:printf("������������");
                   scanf("%s", book.name);
                   printf("������ISBN�ţ�");
                   scanf("%d", &book.ISBN);
                   insert(&head, book);
                   printf("��ӳɹ���\n");
                   system("pause");
                   break;
     		case 2:printf("������Ҫ���ҵ�������");
                   scanf("%s", name);
                   LinkedList result = find(head, name);
                   if (result != NULL) {
                    printf("�ҵ�ͼ��: ����: %s, ISBN: %d\n", result->data.name, result->data.ISBN);
                    system("pause");
                   }
                   break;
     		case 3:printf("������Ҫɾ����������");
                   scanf("%s", name);
                   delete(&head, name);
                   break;
     		case 4:freeList(head);
                   head = NULL;
                   break;
            case 5:printf("������Ҫ���ҵ�������");
                   scanf("%s", name);
                   LinkedList res = find(head, name);
                   if(res!=NULL){
                   	printf("��Ҫ�ĳ�ʲô������"); 
                   	scanf("%s",res->data.name);
                   	printf("\n��Ҫ�ĳ�ʲôISBN��");
                   	scanf("%d",&res->data.ISBN);
                   	printf("�޸ĳɹ���\n");  // ��ӳɹ���Ϣ
                    system("pause");
				   } 
                   break;       
	 	}
    	if(c==0) 
    	{
			printf("���ѳɹ��˳�ͼ�����ϵͳ������\n");
    		system("pause");
    	}
    }
}

