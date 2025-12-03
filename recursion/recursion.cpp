// 递归和递推的区别
// 形式上：递归使用函数调用——逆推，递推使用for循环——顺推

// 斐波那契数列的递归与递推形式
#include <iostream>
using namespace std;

/*
int f(int n)    // 递归深度较深时，栈区的函数调用较多，且多次重复计算相同的数据，消耗了不必要的资源
{
    if (n == 1 || n == 2) {return 1;}
    return f(n - 1) + f(n - 2);
}    
int main()
{
    cout << f(50);
    return 0;
}
*/

int main()
{
    int n;
    cin >> n;
    long long a[60];
    a[1] = 1, a[2] = 1;
    for (int i = 3; i < n; i++)
    {
        a[i] == a[i - 1] + a[i - 2];
    }
    cout << a[n];
    return 0;
}
