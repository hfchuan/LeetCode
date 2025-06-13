#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        int firstMissingPositive(std::vector<int>& nums){
            int n = nums.size();
            for (int i = 0 ; i < n ; i ++ ) {
                while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                    std::swap(nums[nums[i] - 1], nums[i]);
                }
            }

            for (int i = 0 ; i < n ; i ++ ) {
                if (nums[i] != i + 1) {
                    return i + 1;
                }
            }
            return n + 1;



        }
};


int main(){
    Solution sol;
    std::vector<int> nums={1,2,0};
    std::cout<<sol.firstMissingPositive(nums)<<std::endl;

    return 0;
}