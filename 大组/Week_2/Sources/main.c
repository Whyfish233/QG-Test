#include "fun.h"

int main() {
    char zhong[100];    // ��׺���ʽ
    char hou[100];      // ��׺���ʽ
    int result;         // ��Ϊint
    
    printf("�����������������������'q'�˳���\n");
    
    while (1) {
        printf("\n��������ʽ: ");
        fgets(zhong, 100, stdin);
        zhong[strcspn(zhong, "\n")] = '\0';
        
        if (strcmp(zhong, "q") == 0 || strcmp(zhong, "Q") == 0) {
            printf("��лʹ�ã��ټ���\n");
            break;
        }
        
        if (strlen(zhong) == 0) {
            printf("���벻��Ϊ��\n");
            continue;
        }
        
        zhuanyi(zhong, hou);
        printf("��׺���ʽ: %s\n", hou);
        
        result = jisuan(hou);
        printf("������: %d\n", result);  // %d �滻 %.2f
    }
    system("pause");
    return 0;
}
