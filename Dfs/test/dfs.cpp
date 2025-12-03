#include <iostream>
#include <iomanip>
using namespace std;

int a[6][6] = {};

void f(int x, int y, int count)
{
    a[y][x] = count;
    if (x + 1 <= 4 && a[y][x + 1] == 0)   // 先一直右移直至该方向越界
    {
        f(x + 1, y ,count + 1);
    }
    else if (y + 1 <= 4 && a[y + 1][x] == 0)  // 在依次检索下，左，上，最后四个方向穷尽之后返回结束;
    {
        f(x, y + 1, count + 1);
    }
    else if (x - 1 >= 1 && a[y][x - 1] == 0)
    {
        f(x - 1, y, count + 1);
    }
    else if (y - 1 >= 1 && a[y - 1][x] == 0)
    {
        f(x, y - 1, count + 1);
    }
}

int main ()
{
    f(1, 1, 1);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << setw(5) << a[i][j];
        }
    }

}