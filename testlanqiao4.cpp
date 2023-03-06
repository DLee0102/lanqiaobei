/**
 * @brief 
 * 小蓝要为一条街的住户制作门牌号。

这条街一共有 20202020 位住户，门牌号从 11 到 20202020 编号。

小蓝制作门牌的方法是先制作 00 到 99 这几个数字字符，最后根据需要将字符粘贴到门牌上，例如门牌 1017 需要依次粘贴字符 1、0、1、71、0、1、7，即需要 11 个字符 00，22 个字符 11，11 个字符 77。

请问要制作所有的 11 到 20202020 号门牌，总共需要多少个字符 22？
 * 
 */
#include <iostream>
using namespace std;
// int main()
// {

//   int gwei = 0;
//   int swei = 0;
//   int bwei = 0;
//   int qwei = 0;
//   int total = 0;

//   gwei = 2020/10;
//   swei = (2020/100) * 10 + 1;
//   bwei = (2020/1000) * 100;
//   qwei = 1 * 21;
//   total = gwei + swei + bwei + qwei;

//   printf("%d", total);

//   // 请在此输入您的代码
//   return 0;
// }

// 此法更通用
int main() {
    int doornumbers[2020];
    int times;

    for (int i = 0; i < 2020; i++) {
        doornumbers[i] = i + 1;
    }

    for (int i = 0; i < 2020; i++) {
        if (doornumbers[i]%10==2) { times++; }
        if (doornumbers[i]%100/10==2) { times++; }
        if (doornumbers[i]%1000/100==2) { times++; }
        if (doornumbers[i]%10000/1000==2) { times++; }
    }

    cout << times;

}