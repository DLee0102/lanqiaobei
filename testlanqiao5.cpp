/**
 * @file testlanqiao5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-09
 * 小蓝有很多数字卡片，每张卡片上都是数字 00 到 99。

小蓝准备用这些卡片来拼一些数，他想从 11 开始拼出正整数，每拼一个，就保存起来，卡片就不能用来拼其它数了。

小蓝想知道自己能从 11 拼到多少。

例如，当小蓝有 3030 张卡片，其中 00 到 99 各 33 张，则小蓝可以拼出 11 到 1010，

但是拼 1111 时卡片 11 已经只有一张了，不够拼出 1111。

现在小蓝手里有 00 到 99 的卡片各 20212021 张，共 2021020210 张，请问小蓝可以从 11 拼到多少？

提示：建议使用计算机编程解决问题。
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
  int cards[10] = {0};
  for (int i = 0; i < 10; i++) {
    cards[i] = 2021;
  }

  int i = 0;
  // 循环1-2021
  for (i = 1; true; i++) {
    int j = 0;
    // 循环数组
    for (j = 0; j < 10; j++) {
      int weishu = 0;
      int record = 1;
      // 求位数
      for (int test = 10; true; test = test * 10) {
        if (i/test == 0) { weishu = record; break;}
        record++;
      }
      int n = 0;
      //  循环位数
      for (n = 0; n < weishu; n++) {
        int key = 0;
        key = 10*pow(10, n);
        if (i%key/(key/10)==j) { cards[j]--; }
        if (cards[j] == -1) { i--; break; }
      }

      if (cards[j] == -1) { break; }
    }

    if (cards[j] == -1) { break; }
  }

  cout << i;

  // 请在此输入您的代码
  return 0;
}