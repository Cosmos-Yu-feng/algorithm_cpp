#include <iostream>
#include <set>
#include <random>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int width, heigth, balance = 0;
    cin >> width >> heigth;
    // 一般而言高度为行数，宽度为列数
    vector<vector<int>> arr(heigth, vector<int>(width));

    random_device rd;  // 生成随机种子（利用操作系统无需传参）
    mt19937 gen(rd());   // 生成随机数（需要传入种子参数）
    
    // 设定值的映射区间
    uniform_int_distribution<> dis_row(1, heigth - 1);
    uniform_int_distribution<> dis_col(1, width - 1);

    uniform_int_distribution<> val(1, 10);

    set<pair<int, int>> chosen;
    while (balance < (width-1) * (heigth - 1))
    {
        int row = dis_row(gen);
        int col = dis_col(gen);
        if (chosen.count({row, col}) == 0)
        {
            arr[row][col] = val(gen);
            chosen.insert({row, col});
            balance++;
        }
    }

    for (const auto &row : arr)
    {
        for (auto val : row)
        {
            cout << setw(3) << val <<" ";
        }
        cout << endl;
    }
}    