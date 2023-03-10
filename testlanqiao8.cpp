
/**
 * @brief 此法有问题，在于pow的参数为double，会有1的误差
 * 
 */
// #include <iostream>
// #include <cmath>
// using namespace std;
// int main()
// {
//     // 请在此输入您的代码

//     int integerNum = pow(2, 5);
//     int memory = pow(2, 3 + 20 + 8);

//     int result = memory / integerNum;

//     cout << result;

//     return 0;
// }

/**
 * @file testlanqiao8.cpp
 * @author your name (you@domain.com)
 * @brief 注意大数问题（可能导致结果为负）
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // 请在此输入您的代码

    int integerNum = 4;
    int memory = 256 * 1024 * 1024;

    int result = memory / integerNum;

    cout << result;

    return 0;
}