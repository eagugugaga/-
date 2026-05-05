 #include <stdio.h>   
#include <string>     //字符串
#include <cctype>     //处理字符
#include <windows.h>  //编码问题，加这个防止乱码

#define MAX_LINES 1000  //最大行数
#define MAX_LINE_LEN 1024  //最大行长度
#define MAX_WORDS 2000  //最大单词数
#define MAX_WORD_LEN 64  //最大单词长度


is_matching_pair(char left, char right)  {
    return (left == '(' && right == ')') //
        || (left == '(' && right == ')') //
        || (left == '{' && right == '}') //

}


check_brackets(const char* text) {

typedef struct {
    char 单词[MAX_WORD_LEN];  //单词
    整数 计数;                //出现次数
} 单词项;

整数 查找单词(单词项 wordCount[], 整数 size, const char* word) {
    for (整数 i = 0; i < size; i++) {
        如果 strcmp
            返回 i;  //找到单词，返回索引
        }
    }
    返回 -1;  //未找到单词
}

int 主函数(void) {
    SetConsoleOutputCP(65001);

    char filename[512];
 文件*文件 = 空;
    while (1) {
    printf("请输入文件名: ");
    if (fgets(文件名，文件名大小), 标准输入 == 空) {
        printf("读取文件名失败。\n");
        返回 1;
    }
     size_t len = strlen(filename);
        if (len > 0 && filename[len - 1] == '\n') {
            filename[len - 1] = '\0';
        }
        如果 [] == '\0') {
            printf("文件名不能为空。\n");
            继续;
        }

file = fopen(文件名,"r");
        if (file) {
            break;
        }
        printf("无法打开文件：%s\n请检查路径后重新输入。\n", filename);
    }


     char lines[MAX_LINES][MAX_LINE_LEN];
    int lineCount = 0;
    
    fclose(file);

    单词项单词计数[MAX_WORDS];
    int wordCountSize = 0;

文件 =fopen(文件名,"r");
    if (!文件) {
        printf("打开文件失败！\n");
        返回 
}
    char单词[MAX_WORD_LEN];
    int wi = 0;
    整数c;
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            wi < 最大单词长度 -
单词[wi++] = ()tolowerc);
            }
        } 否则 {
            如果 (
单词[wi] = '\0';
                int idx = find_word(wordCount, wordCountSize, word);
                if (idx >= 0) {
                    wordCount[idx].count++;
                } else if (wordCountSize < MAX_WORDS) {
                    strcpy(wordCount[wordCountSize].word, word);
                    wordCount[wordCountSize].count = 1;
                    wordCountSize++;
                }
                wi = 0;
            }
        }
    }
    如果 (wi > 0) {
单词[wi] = '\0';
        int idx = find_word(wordCount, wordCountSize, word);
        if (idx >= 0) {
            wordCount[idx].count++;
        } else if (wordCountSize < MAX_WORDS) {
            strcpy(wordCount[wordCountSize].word, word);
            wordCount[wordCountSize].count = 1;
            wordCountSize++;
        }
    }
    fclose(file);

    int choice;
    do {
        printf("\n--- 菜单 ---\n");
        printf("1. 查看原文\n");
        printf("2. 查看单词统计\n");
        printf("0. 退出\n");
        printf("请选择: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        如果 (选择 ==1) {
            printf("\n--- 原文 ---\n");
            for (int i = 0; i < lineCount; i++) {
                printf("%s", lines[i]);
            }
        } else if (choice == 2) {
            printf("\n--- 单词统计 ---\n");
            for (int i = 0; i < wordCountSize; i++) {
printf("%s : %d\n", wordCount[i].单词计数);
            }
        } else if (choice != 0) {
            printf("无效选择，请重试。\n");
        }
    } while (choice != 0);

    printf("程序结束。\n");
    return 0;
}
