#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, tmp;
vector< vector<int> >num(101);
vector< vector<bool> >flag(101);
 
int main()
{
	// 请在此输入您的代码
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
		{
			cin >> tmp;
			num[i].push_back(tmp);
			flag[i].push_back(false);
		}
 
	if (n % 2)	//n为奇数，则最后一行有奇数个数，最中间的数可作为终点
		flag[n - 1][(n - 1) / 2] = true;
	else		//i为偶数，则最后一行有偶数个数，最中间两个数可作为终点
	{
		flag[n - 1][n / 2] = true;
		flag[n - 1][n / 2 - 1] = true;
	}
	for (int j = 0; j < n; j++)//最后一行其余的数设为0
		if (!flag[n - 1][j])
			num[n - 1][j] = 0;
 
	for (int i = n - 2; i >= 0; i--)//从倒数第二行往上遍历
	{
		for (int j = 0; j <= i; j++)//从左往右遍历
		{
			if (!flag[i + 1][j] && !flag[i + 1][j + 1])//该点不能到达
				num[i][j] = 0;//设为0，方便计算
			else										//该点能到达
			{
				num[i][j] += max(num[i + 1][j], num[i + 1][j + 1]);//取两者最大即可
				flag[i][j] = true;//标记该点能到达
			}
		}
	}
	cout << num[0][0] << endl;//输出结果
	return 0;
}