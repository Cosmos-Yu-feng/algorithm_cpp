#include <iostream>
#include <vector>
using namespace std;

int fib(vector<int> &dp, int n)
{
    dp.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)   // 计算顺序(通常从小到大)
    {
        if (i == 1 || i == 2)     // 确定边界条件
        {
            dp[i] = 1;
        }
        else 
        {   
            dp[i] = dp[i - 1] + dp[i - 2];   // 状态转移方程
        }
    }
    return dp[n];
}

int main()
{
    vector<int> dp;
    int res = fib(dp, 7);
    cout << res;
    return 0;
}