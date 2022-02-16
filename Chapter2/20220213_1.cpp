// P31.���ַ����ݹ�ʵ�֣�
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

long long binary_search(int arr[], int l, int r, int x)
{
 
    if (r >= l)
    {
        int mid = (r + l) / 2;
        if (arr[mid] == x){
            return mid;
        }
        if (arr[mid] > x){
            return binary_search(arr, l, mid -1, x);
        }
        return binary_search(arr, mid +1, r, x);
    }
    return -1;
}

// �ռ临�Ӷȣ�O(logn)
// ����n��1
// 0
// ��ʱ��0 ms
// ����n��2
// 1
// ��ʱ��0 ms
// ����n��3
// 2
// ��ʱ��0 ms
// ����n��4
// 3
// ��ʱ��0 ms
// ����n��5
// 4
// ��ʱ��0 ms
// ����n��6
// -1
// ��ʱ��0 ms
// ����n��7
// -1
// ��ʱ��0 ms
// ����n��-1

int main()
{
    long long n; // ���ݹ�ģ
    while (1)
    {
        cout << "����n��";
        cin >> n;
        milliseconds start_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch());

        int arr[] = {1,2,3,4,5};
        long long a = binary_search(arr,0, 4, n);
        milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch());
        cout << a << endl;
        cout << "��ʱ��" << milliseconds(end_time).count() - milliseconds(start_time).count() << " ms" << endl;
    }
}