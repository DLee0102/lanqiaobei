#include <iostream>
using namespace std;
/**
 * @brief 时间复杂度为2的n次方，故此解提交在蓝桥杯平台上会超时
 * 
 * @param a 
 * @param rows 
 * @param pos 
 * @param length 
 * @param path 
 * @param max_rows 
 * @param max_pathval 
 * @return int 
 */
int dfs(int a[][100], int rows = 0, int pos = 0, int length = 0, int* path = NULL, int max_rows = 0, int max_pathval = 0)
{
    int value = 0;
    value = a[rows][pos];
    path[length] = value;
    length++;
    rows++;

    int left_pos = pos;
    int right_pos = pos + 1;
    if (rows >= max_rows)
    {
        int pathval = 0;
        for (int i = 0; i < length; i ++)
        {
            pathval += path[i];
        }

        if (max_rows%2 == 1 && pos == max_rows/2)
        {
            if (pathval >= max_pathval) max_pathval = pathval;
        }
        if (max_rows%2 == 0 && (pos == max_rows/2 - 1 || pos == max_rows/2))
        {
            if (pathval >= max_pathval) max_pathval = pathval;
        }
        return max_pathval;
    }
    
    max_pathval = dfs(a, rows, left_pos, length, path, max_rows, max_pathval);
    max_pathval = dfs(a, rows, right_pos, length, path, max_rows, max_pathval);

    return max_pathval;
}

int main()
{
    int rows = 0;
    cin >> rows;
    int a[100][100] = {0};

    for (int i = 0; i < rows; i ++)
    {
        for (int j = 0; j < i + 1; j ++)
        {
            cin >> a[i][j];
        }
    }


    cout << dfs(a, 0, 0, 0, new int[rows], rows, 0);

}