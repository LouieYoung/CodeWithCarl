// P27.쳲���������
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

long long fibonacci1(long long i)
{
    if (i <= 0)
        return 0;
    if (i == 1)
        return 1;
    return fibonacci1(i - 1) + fibonacci1(i - 2);
}

// ʱ�临�Ӷȣ�O(2^n)���ռ临�Ӷȣ�O(1)
// ����n��40
// 102334155
// ��ʱ��691 ms
// ����n��50
// 12586269025
// ��ʱ��85956 ms

long long fibonacci2(long long first, long long second, long long n)
{
    if (n <= 0)
        return 0;
    if (n < 3)
        return 1;
    if (n == 3)
        return first + second;
    return fibonacci2(second, first + second, n - 1);
}

// ʱ�临�Ӷȣ�O(n)���ռ临�Ӷȣ�O(n)
// ����n��40
// 102334155
// ��ʱ��0 ms
// ����n��50
// 12586269025
// ��ʱ��0 ms

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
        long long a = fibonacci2(1,1,n);
        milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch());
        cout << a << endl;
        cout << "��ʱ��" << milliseconds(end_time).count() - milliseconds(start_time).count() << " ms" << endl;
    }
}
