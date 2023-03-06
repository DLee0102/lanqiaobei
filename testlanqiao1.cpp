/**
 * @file testlanqiao.cpp
 * @author DL 
 * @brief 
 * @version 0.1
 * @date 2023-01-01
 * 输入描述
输入一行包含一个单词，单词只由小写英文字母组成。

对于所有的评测用例，输入的单词长度不超过 1000。

输出描述
输出两行，第一行包含一个英文字母，表示单词中出现得最多的字母是哪 个。如果有多个字母出现的次数相等，输出字典序最小的那个。

第二行包含一个整数，表示出现得最多的那个字母在单词中出现的次数。
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int count[26]={0};
    char ch;
    while ((ch=getchar())!='\n') {
        count[ch - 'a']++;
        // printf("%d %d %c\n", ch-'a', count[ch-'a'], ch);
    }
    int i = 0;
    int max = 0;
    int max_index = 0;
    for (i=0; i<26; i++) {
        if (count[i] > max){
            max = count[i];
            max_index = i;
        }
    }
    // printf("%d\n", max);
    printf("%c\n%d", 'a'+max_index, max);
}