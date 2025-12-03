#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <set>
using namespace std;

template<typename T>
void Print2dArr(const vector<vector<T>> &arr)
{
    for (const auto &row : arr)
    {
        for (auto val : row)
        {
            cout << setw(3) << val << " ";
        }
        cout << endl;
    }
}

template<typename T>
void fullone(vector<vector<T>> &arr, int height, int width, int k)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_row(0, height - 1);
    uniform_int_distribution<> dis_col(0, width - 1);    
    
    int balance = 0;
    set<pair<int, int>> chosen;
    while (balance < k)
    {
        int row = dis_row(gen);
        int col = dis_col(gen);
        if (chosen.count({row, col}) == 0)
        {
            arr[row][col] = 1;
            chosen.insert({row, col});
            balance++;
        }
    }
}

// 回溯：寻找从（0，0）到（h-1，w-1）的一条通路（0表示通路，1表示障碍）
bool findPath(const vector<vector<int>> &arr, int row, int col, vector<vector<int>> &vis, vector<pair<int, int>> &path)
{
    int h = arr.size();
    int w = arr[0].size();
    if (row < 0 || row > h - 1 || col < 0 || col > w - 1) return false;
    if (arr[row][col] == 1 || vis[row][col]) return false;

    vis[row][col] = 1;
    path.emplace_back(row, col);

    // 到达终点
    if (row == h - 1 && col == w - 1) return true;

    // 移动逻辑
    static int drow[4] = {};
    static int dcol[4] = {};
    for (int k = 0; k < 4; k++)
    {
        int nrow = row + drow[k], ncol = col + dcol[k];
        if (findPath(arr, nrow, ncol, vis, path)) 
        return true;   // 一路若通，此路皆通 
    }

    // 回溯
    vis[row][col] = 0;
    path.pop_back();
    return false;    // 一点不同，此路均死 

}

int main()
{
    int height, width;
    if (!(cin >> height >>width)) return 0;
    if (height <= 0 || width <= 0) return 0;

    vector<vector<int>> arr(height, vector<int>(width, 0));
    
    int k = (width * height) * 3 / 8 ;
    fullone(arr, height, width, k);

    arr[0][0] = 0;
    arr[height - 1][width - 1] = 0;

    cout << "矩阵(0 = 通路, 1 = 障碍)" << endl;
    Print2dArr(arr);

    cout << "尝试回溯寻找从(0, 0)到(" << height - 1 << "," << width - 1 << ")的路径..." << endl;
    vector<vector<int>> vis(height, vector<int>(width, 0));
    vector <pair<int, int>> path;
    bool ok = findPath(arr, 0, 0, vis, path);

    if (ok)
    {
        cout << "找到路径,长度 = " << path.size() << endl;
        for (auto &p : path) 
        cout << "(" << p.first << "," << p.second << ")";
        cout << "路径可视化(6表示路径):" << endl;
        for (auto &p : path) arr[p.first][p.second] = 6;
        Print2dArr(arr);
    }
    else
    {
        cout << "未找到路径" << endl;
    }

    return 0;

}

