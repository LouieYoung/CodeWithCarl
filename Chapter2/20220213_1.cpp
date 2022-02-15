// P31.二分法（递归实现）
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

long long binary_search(int arr[], int l, int r, int x)
{
    if (r >= 1)
    {
        int mid = 1 + (r - 1) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binary_search(arr, l, mid -1, x);
        return binary_search(arr, mid +1, r, x);
    }
    return -1;
}

// 时间复杂度：O(2^n)，空间复杂度：O(1)
// 输入n：40
// 102334155
// 耗时：691 ms
// 输入n：50
// 12586269025
// 耗时：85956 ms

int main()
{
    long long n; // 数据规模
    while (1)
    {
        cout << "输入n：";
        cin >> n;
        milliseconds start_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch());

        // long long a = fibonacci1(n);
        int arr[] = new int[5];
        long long a = binary_search(1, 1, n);
        milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch());
        cout << a << endl;
        cout << "耗时：" << milliseconds(end_time).count() - milliseconds(start_time).count() << " ms" << endl;
    }
}
