/**
 * @file testlanqiao2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-01
 * 关键：四舍五入处理
 * 输入描述
输入的第一行包含一个整数 n\ (1 \leq n \leq 10^4)n (1≤n≤10 
4
 )，表示考试人数。

接下来 nn 行，每行包含一个 0 至 100 的整数，表示一个学生的得分。

输出描述
输出两行，每行一个百分数，分别表示及格率和优秀率。百分号前的部分 四舍五入保留整数。
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    int test;
    int i;
    int firstnum = 0;
    int secondnum = 0;
    double firstresult = 0;
    double secondresult = 0;
    int score[10000] = {-1};

    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d", &score[i]);
    }

    for (i = 0; i < num; i++) {
        if (score[i] >= 60) {
            firstnum++;
        }
        if (score[i] >= 85) {
            secondnum++;
        }
    }
    firstresult = firstnum*100.0/num;
    secondresult = secondnum*100.0/num;
    if ((firstresult-(int)firstresult) >= 0.5) {
        firstresult++;
    }
    if ((secondresult-(int)secondresult) >= 0.5) {
        secondresult++;
    }
    printf("%d\%\n%d\%", (int)firstresult, (int)secondresult);


}

/**
 * @brief 简洁解法
 * 不用创建数组，四舍五入的处理方法更简单
 */
// #include <iostream>
// using namespace std;
// int main()
// {
//     int num,t=0,m=0,n;
//     cin>>num;
//     for(int i=0;i<num;i++){
//     cin>>n;
//     if(n>60){
//         t++;
//     }
//     if(n>85){
//         m++;
//     }
//     }
//     int a=t*100.0/num*1.0+0.5;
//     int b=m*100.0/num*1.0+0.5;
//     printf("%d%\n%d%\n",a,b);
//     return 0;
// }