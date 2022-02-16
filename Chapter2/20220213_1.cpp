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
// ����n��40
// 102334155
// ��ʱ��691 ms
// ����n��50
// 12586269025
// ��ʱ��85956 ms

int main()
{
    long long n; // ���ݹ�ģ
    while (1)
    {
        cout << "����n��";
        cin >> n;
        milliseconds start_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch());

        // long long a = fibonacci1(n);
        int arr[] = {1,2,3,4,5};
        long long a = binary_search(arr,0, 4, n);
        milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch());
        cout << a << endl;
        cout << "��ʱ��" << milliseconds(end_time).count() - milliseconds(start_time).count() << " ms" << endl;
    }
}