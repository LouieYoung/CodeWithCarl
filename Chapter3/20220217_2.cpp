// P36.704.���ֲ���
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                right = mid - 1;
            }
            if(nums[mid] < target){
                left = mid + 1;
            }
        }
        return -1;

    }
    int search2(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while(left < right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                right = mid;
            }
            if(nums[mid] < target){
                left = mid + 1;
            }
        }
        return -1;

    }
};

int main() {

    Solution solution;
    vector<int> nums = {1,2,3,4,7,9,10};
    int target = 2;
    cout << solution.search2(nums,target) << endl;
}