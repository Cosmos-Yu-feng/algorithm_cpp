// sort（）的API调用，比较函数的定义，结构体比较
#include <iostream>
#include <algorithm>
#define Log(a) cout << a << endl;
using namespace std;


// 逆序比较函数（返回true表示第一个参数排在前面）
bool greatcmp(const int &a, const int &b)
{
    return a >= b;
}

// 结构体
struct student
{
    string name;
    int sex;  // 0代表女性，1代表男性
    int age;
public:
    static bool stucmp(const student &a, const student &b)
    {
        return a.age < b.age;
    } 
};


int main()
{
    int a[10] = {3,5,2,8,9,1,5,2,7,4};
    // sort(a, a + 10);   // Log(正序：从小到大)
    // sort(a, a + 10, greater<int>());   // Log(逆序：从大到小)
    // sort(a, a + 10, greatcmp);  //逆序的比较函数写法
    // PrintArray(a, 10);

    student stus[5] = {
        {"Y", 1, 18},
        {"王子", 1, 1},
        {"张意味", 0, 3},
        {"勋基哈", 1, 17},
        {"甲", 0, 20}
    };
    sort(stus, stus + 5, student::stucmp);
    for (student person : stus)
    {
        Log(person.name);
    }
    return 0;
}

// 打印数组
void PrintArray(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        Log(arr[i]);
    }
    Log("=============================");
}