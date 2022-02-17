// P42.209.长度最小的子数组
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    //暴力解法
    int minSubArrayLen1(int target, vector<int> &nums)
    {
        int result = INT32_MAX;
        int sum = 0;
        int subLength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum >= target)
                {
                    subLength = j - i + 1;
                    result = result < subLength ? result : subLength;
                    break;
                }
            }
        }
        return result == INT32_MAX ? 0 : result;
    }

    //滑动窗口
    int minSubArrayLen2(int target, vector<int> &nums)
    {
        int result = INT32_MAX;
        int sum = 0;
        int subLength = 0;
        int i = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                subLength = j - i + 1;
                result = result < subLength ? result : subLength;
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main()
{

    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << solution.minSubArrayLen2(target, nums) << endl;
}