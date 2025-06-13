#include <iostream>
#include <vector>

class Solution{
    public:
        int findMin(std::vector<int>& nums){
            int left = 0, right = nums.size() - 1;
            while(left < right){
                int mid = left + (right -left)/2;
                if(nums[mid]>nums[right]){
                    left = mid +1;
                }
                else{
                    right = mid ;
                }
                
            }
            int k = left;

            if (k==0){
                return nums[0];
            }
            else {
                return nums[k];
            }



        }
};


int main(){
    Solution sol;
    std::vector<int> nums = {3,1,2};
    std::cout << sol.findMin(nums) << std::endl;



    return 0;
}