#include "fun.h"

int main() {
    char zhong[100];    // 中缀表达式
    char hou[100];      // 后缀表达式
    int result;         // 改为int
    
    printf("整数四则运算计算器（输入'q'退出）\n");
    
    while (1) {
        printf("\n请输入表达式: ");
        fgets(zhong, 100, stdin);
        zhong[strcspn(zhong, "\n")] = '\0';
        
        if (strcmp(zhong, "q") == 0 || strcmp(zhong, "Q") == 0) {
            printf("感谢使用，再见！\n");
            break;
        }
        
        if (strlen(zhong) == 0) {
            printf("输入不能为空\n");
            continue;
        }
        
        zhuanyi(zhong, hou);
        printf("后缀表达式: %s\n", hou);
        
        result = jisuan(hou);
        printf("计算结果: %d\n", result);  // %d 替换 %.2f
    }
    system("pause");
    return 0;
}
