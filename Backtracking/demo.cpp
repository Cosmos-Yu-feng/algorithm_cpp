#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// 打印二维数组
void PrintArray(vector<vector<int>> &arr)
{
    for (auto &row : arr)
    {
        for (auto val : row)
        {
            cout << setw(3) << val << " ";
        }
        cout << endl;
    }
}

// 可视化路径
void plotpath(vector<pair<int, int>> &path, vector<vector<int>> &plot)
{
    for (auto pair : path)
    {
        plot[pair.first][pair.second] = 1;
    }
    PrintArray(plot);
}

// 回溯逻辑：0 可走，1 障碍
void backtrack(
            vector<vector<int>> &arr, int row, int col,
            vector<vector<int>> &vis,
            vector<pair<int, int>> &path,
            vector<vector<pair<int, int>>> &res
            )
{
    int h = arr.size();
    int w = arr[0].size();

    // 越界或已访问或障碍 -> 失败
    if (row < 0 || row > h - 1 || col < 0 || col > w - 1) return;
    if (vis[row][col]) return;
    if (arr[row][col] == 1) return;

    // 记录当前位置
    vis[row][col] = 1;
    path.emplace_back(row,col);

    // 终止条件:到达终点：保存当前路径（但不返回，继续回溯以找其他路径）
    if (row == h - 1 && col == w - 1) 
    {
        res.push_back(path);
    }
    else
    {
        // 移动回溯逻辑
        int drow[4] = {0, 1, 0, -1};
        int dcol[4] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i], ncol = col + dcol[i];
            backtrack(arr, nrow, ncol, vis, path, res);
        }
    }

    // 回溯：撤销本步
    vis[row][col] = 0;
    path.pop_back();
}

// 主函数
int main()
{
    // 创建动态二维数组
    int height, width;
    cout << "分别输入矩阵的高和宽..." << endl;
    cin >> height >> width;
    vector<vector<int>> arr(height, vector<int>(width, 0));

    // 创建访问数组和路径数组
    vector<vector<int>> vis(height, vector<int>(width, 0));
    vector<pair<int, int>> path;

    // 创建路径保存数组
    vector<vector<pair<int, int>>> res;

    backtrack(arr, 0, 0, vis, path, res);
    
    int t = 1;
    for(auto &row : res)
    {
        cout << "这是第" << t << "条路线：" << endl;
        vector<vector<int>> plot(height, vector<int>(width, 0));
        for (auto pair : row)
        {
            cout << "(" << pair.first << "," << pair.second << ")" << " -> ";
        }
        cout << endl;
        plotpath(row, plot);
        cout << "========================";
        cout << endl << endl;
        t++;
    }
}