//P19.时间复杂度
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

 // O(n²)
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
         for (long long j = 1; j < n; j = j*2) { // 注意这里j=1
            k++;
         }
     }
 }

 int main() {
     long long n; // 数据规模
     while (1) {
         cout << "输入n：";
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
         cout << "耗时：" << milliseconds(end_time).count() - milliseconds(start_time).count() <<" ms"<< endl;
     }
 }


// 运算结果
// O(n)
// 输入n：100000000
// 耗时：134 ms
// 输入n：1000000000
// 耗时：1338 ms
// 输入n：500000000
// 耗时：672 ms
// 输入n：744000000
// 耗时：998 ms

// O(n²)
// 输入n：1000
// 耗时：1 ms
// 输入n：10000
// 耗时：141 ms
// 输入n：20000
// 耗时：535 ms
// 输入n：25000
// 耗时：845 ms
// 输入n：27000
// 耗时：983 ms
// 输入n：28000
// 耗时：1056 ms

// O(nlogn)
// 输入n：10000
// 耗时：1 ms
// 输入n：1000000
// 耗时：30 ms
// 输入n：10000000
// 耗时：367 ms
// 输入n：20000000
// 耗时：775 ms
// 输入n：30000000
// 耗时：1180 ms
// 输入n：25000000
// 耗时：966 ms
// 输入n：27000000
// 耗时：1053 ms
// 输入n：26000000
// 耗时：1008 ms