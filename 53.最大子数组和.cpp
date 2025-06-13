#include <iostream>
#include <vector>


class Solution{
    public:
        int maxSubArray(std::vector<int>& nums){
            int global_max =-99999;
            int current_max = 0;
            for(const auto& num:nums){
                current_max += num;
                global_max = std::max(global_max,current_max);
                if(current_max<0){
                    current_max = 0;
                }
            }
            return global_max;

        }
};

int main(){
    Solution sol;
    std::vector<int> nums ={-2,1,-3,4,-1,2,1,-5,4};
    std::cout<<sol.maxSubArray(nums)<<std::endl;


    return 0;
}
