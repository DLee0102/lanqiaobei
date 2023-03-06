/**
 * @file testlanqiao3.cpp
 * @author DL
 * @brief 
 * @version 0.1
 * @date 2023-01-01
 * 关键：数字拆分、日期判断
 * 输入描述
输入包含一个八位整数 NN，表示日期。

对于所有评测用例，10000101 \leq N \leq 8999123110000101≤N≤89991231，保证 NN 是一个合法日期的 8 位数表示。

输出描述
输出两行，每行 1 个八位数。第一行表示下一个回文日期，第二行表示下一个 ABABBABA 型的回文日期。
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

using namespace std;

bool check(int date) {
    int year;
    int month;
    int day;

    year = date/10000;
    day = date%100;
    month = (date%10000)/100;

    if (month > 12 || month == 0) {
        return false;
    }

    if (day > 31 || day == 0) {
        return false;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return false;
        }        
    }

    if (month == 2) {
        if ((year%400 == 0) || (year%100!=0 && year%4==0)) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    }

    return true;
}

int main(){
    int date = 0;
    int sdate = 0;
    int firstdate;
    int lastdate;
    int g;
    int s;
    int b;
    int q;
    int tempdate;
    int flag = 0;
    cin >> sdate;
    date = sdate;

    while (true) {
        date++;
        firstdate = date/10000;
        lastdate = date - (firstdate*10000);

        g = lastdate%10;
        s = (lastdate%100)/10;
        b = (lastdate%1000)/100;
        q = lastdate/1000;

        tempdate = g*1000 + s*100 + b*10 + q;
        if (tempdate == firstdate && flag == 0) {
            if (check(date)){
                printf("%d\n", date);
                flag = 1;
            }
        }
        if (tempdate == firstdate) {
            if (check(date)){
                if (g == b && s == q) {
                    printf("%d\n", date);
                    break;
                }
            }
        }

    }

}