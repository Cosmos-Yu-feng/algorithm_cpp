// A点有一个卒子，每次只能向下或向右移动。
// 在任意一点有敌方的马，记作C点，马及其所控制的点上，卒子均不可通过
// 求A到达B点方法总数
#include <iostream>
#define MAX_SIZE 100
using namespace std;

int main()
{
    int a[30][30] = {};
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {continue;}
            if (i == 0 || j == 0)
            {a[i][j] = 1;}
            else 
            {
                a[i][j] = a[i - 1][j] + a[i][j - 1];
            }

        }
    }
    cout << a[n][m];
}

// /*
// bool no_move(int (&horses)[5][2], long long (&arr)[MAX_SIZE][MAX_SIZE], int x, int y)
// {
//     for (int i = 1; i <= 2; i++)
//     {
//         for (int j = 1; j <= 5; j++)
//         {
//             if (i == x && j == y)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// */

// int main()
// {
//     // 矩阵来模拟棋盘上的点，并将数组元素都初始化为0
//     long long arr[MAX_SIZE][MAX_SIZE] = {};
//     int horses[5][2] = {
//         {1, 7},
//         {3, 8},
//         {2, 5},
//         {6, 2},
//         {4, 2}
//     };
//     int end[2] = {50,40};
//     int &width = end[0];
//     int &heigth = end[1];

    
//     for (int x = 0; x <= width; x++)
//     {
//         for (int y = 0; y <= heigth; y++)
//         {
//             if (x == 0 && y == 0) {continue;}
//             if (x == 0 || y == 0)
//             {
//                 arr[x][y] = 1;
//             }
//             // else if (no_move(horses, arr, x, y))
//             // {
//                 // arr[x][y] = 0;
//             // }
//             else
//             {
//                 arr[x][y] = arr[x - 1][y] + arr[x][y - 1];
//             }
//         }
//     }
//     cout << arr[width][heigth] << endl;
// }
