//P19.ʱ�临�Ӷ�
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

// O(n)
void function1(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        k++;
    }
}

 // O(n?)
 void function2(long long n) {
     long long k = 0;
     for (long long i = 0; i < n; i++) {
         for (long j = 0; j < n; j++) {
             k++;
         }
     }
 }

 // O(nlogn)
 void function3(long long n) {
     long long k = 0;
     for (long long i = 0; i < n; i++) {
         for (long long j = 1; j < n; j = j*2) { // ע������j=1
            k++;
         }
     }
 }

 int main() {
     long long n; // ���ݹ�ģ
     while (1) {
         cout << "����n��";
         cin >> n;
         milliseconds start_time = duration_cast<milliseconds > (
             system_clock::now().time_since_epoch()
         );
        //  function1(n);
        //  function2(n);
         function3(n);
         milliseconds end_time = duration_cast<milliseconds > (
             system_clock::now().time_since_epoch()
         );
         cout << "��ʱ��" << milliseconds(end_time).count() - milliseconds(start_time).count() <<" ms"<< endl;
     }
 }


// ������
// O(n)
// ����n��100000000
// ��ʱ��134 ms
// ����n��1000000000
// ��ʱ��1338 ms
// ����n��500000000
// ��ʱ��672 ms
// ����n��744000000
// ��ʱ��998 ms

// O(n?)
// ����n��1000
// ��ʱ��1 ms
// ����n��10000
// ��ʱ��141 ms
// ����n��20000
// ��ʱ��535 ms
// ����n��25000
// ��ʱ��845 ms
// ����n��27000
// ��ʱ��983 ms
// ����n��28000
// ��ʱ��1056 ms

// O(nlogn)
// ����n��10000
// ��ʱ��1 ms
// ����n��1000000
// ��ʱ��30 ms
// ����n��10000000
// ��ʱ��367 ms
// ����n��20000000
// ��ʱ��775 ms
// ����n��30000000
// ��ʱ��1180 ms
// ����n��25000000
// ��ʱ��966 ms
// ����n��27000000
// ��ʱ��1053 ms
// ����n��26000000
// ��ʱ��1008 ms