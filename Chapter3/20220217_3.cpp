// P39.27.ÒÆ³ýÔªËØ
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement1(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums[i] == val){
                for(int j = i + 1; j < size; j++){
                    nums[j-1] = nums[j];
                }
                i--;
                size--;
            }
        }
        cout << nums[0] << endl;
        return size;
    }
    int removeElement2(vector<int>& nums, int val) {
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
            if(nums[fastIndex] != val){
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
};

int main() {

    Solution solution;
    vector<int> nums = {3,2,2,3,3,4,5,6,3};
    int val = 3;
    cout << solution.removeElement2(nums,val) << endl;
}