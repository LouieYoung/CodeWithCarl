//P35.测试二维数组是否连续分布
#include <iostream>
using namespace std;
void test_arr() {
    int array[2][3] = {
        {0, 1, 2},
        {3, 4, 5}
    };
    cout << &array[0][0] << " " << &array[0][1] << " " << &array[0][2] << endl; 
    cout << &array[1][0] << " " << &array[1][1] << " " << &array[1][2] << endl; 
}

int main(){
    test_arr();
}

//测试结果
// 0x61fdd0 0x61fdd4 0x61fdd8
// 0x61fddc 0x61fde0 0x61fde4