// P45.59.���������
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
        int startx = 0, starty = 0; //����ÿѭ��һ��Ȧ����ʼλ��
        int loop = n / 2; //ÿ��Ȧѭ�����Σ����nΪ����3����ôloop = 1
        int mid = n / 2; //�����м��λ��
        int count = 1; //������������ÿһ���ո�ֵ
        int offset = 1; //ÿһȦѭ������Ҫ����ÿһ���߱����ĳ���
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