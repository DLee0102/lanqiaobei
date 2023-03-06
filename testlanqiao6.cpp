/**
 * @file testlanqiao6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-14
 * 输入描述
输入的第一行包含一个整数 n\ (1 ≤ n ≤ 10^4)n (1≤n≤10 
4
 )，表示考试人数。

接下来 nn 行，每行包含一个 0 至 100 的整数，表示一个学生的得分。

输出描述
输出三行。

第一行包含一个整数，表示最高分。

第二行包含一个整数，表示最低分。

第三行包含一个实数，四舍五入保留正好两位小数，表示平均分。
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
    int nums = 0;
    int i = 0;
    int score = 0;
    int max = 0;
    int min = 0;
    int sum = 0;
    int temp_ave = 0;
    double average = 0;
    cin >> nums;
    cin >> score;
    min = score;
    max = score;
    sum += score;

    for(i = 0; i < nums - 1; i++)
    {
        cin >> score;
        if (max <= score) {max = score;}
        if (min >= score) {min = score;}
        sum += score;
    }

    temp_ave = sum*100.0/nums + 0.5;
    average = temp_ave/100.0;

    printf("%d\n%d\n%.2lf", max, min, average);
}