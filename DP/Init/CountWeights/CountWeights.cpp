// 砝码称重问题:
// 问题：你有一架天平和N个砝码，这N个砝码重量依次是W1,W2,⋯,WN。
// 请你计算一共可以称出多少种不同的重量?
// 注意：砝码可以放在天平两边

/*
    0个砝码，称量为0
    1个砝码，称量为w1
    2个砝码，称量为w2，w1+w2，|w1 - w2|
我用dp[i][j]来表示状态，dp[i]为前i个砝码，[j]表示可以称量出j的质量
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, sum = 0;
    cin >> N;
    vector<int> w(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> w[i];
        sum += w[i];
    }

    // 确定状态（我用dp[i][j]来表示状态，dp[i]为前i个砝码，[j]表示可以称量出j的质量）
    vector<vector<int>> dp(N + 1, vector<int>(sum + 1, 0));

    // 确定边界条件
    dp[0][0] = 1;

    // 确定状态转移方程
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (dp[i - 1][j]) 
            {
                dp[i][j] = 1;
                dp[i][abs(j - w[i])] = 1;
                if (j + w[i] <= sum) 
                {
                    dp[i][j + w[i]] = 1;
                }
            }
            


            
        }
    }

    int count = 0;
    // 求方法数（即true的个数）
    for (int i = 1; i <= sum; i++)
    {
        if (dp[N][i] == 1) 
        {count++;}
    }
    cout << count;
}