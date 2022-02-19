// P45.59.螺旋矩阵Ⅱ
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:

    vector<vector<int>> generateMatrix(int n)
    {
        // vector<vector<int>> nums = {{1,2,3},{4,5,6}};
        vector<vector<int>> res(n, vector<int>(n,0));
        int startx = 0, starty = 0; //定义每循环一个圈的起始位置
        int loop = n / 2; //每个圈循环几次，如果n为奇数3，那么loop = 1
        int mid = n / 2; //矩阵中间的位置
        int count = 1; //用来给矩阵中每一个空格赋值
        int offset = 1; //每一圈循环都需要控制每一条边遍历的长度
        int i,j;

        while (loop--)
        {
            i = startx;
            j = starty;

            for (j = starty; j < starty + n - offset; j++){
                res[startx][j] = count++;
            }

            for(i = startx; i < startx + n - offset;i ++){
                res[i][j] = count++;
            }

            for(;j > starty;j--){
                res[i][j] = count++;
            }

            for(;i > startx;i--){
                res[i][j] = count++;
            }

            startx++;
            starty++;
            offset+=2;
        }
        if(n%2){
            res[mid][mid] = count;
        }

        return res;
    }
};

int main()
{

    Solution solution;
    int n = 3;
    vector<vector<int>> nums = solution.generateMatrix(n);

    for (vector<vector<int>>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        
        for (vector<int>::iterator itit = (*it).begin(); itit != (*it).end(); itit++)
        {
            cout << *itit << ends;
            cout << " " << ends;
        }
            cout << "\n" << ends;
    }
}