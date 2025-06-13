#include <iostream>
#include <vector>

class Solution{
    public:
        int searchInsert(std::vector<int>& nums,int target){
            int left =0,right = nums.size() -1;
            while(left <= right){
                int mid =(left + right) /2;
                if(nums[mid] == target){
                    return mid;
                }
                else if(nums[mid]>target){
                    right = mid -1;

                }
                else{
                    left = mid +1;
                }
            }

            return left;

        }
};

int main(){
    Solution sol;
    std::vector<int> nums = {1,3,5,6};
    int target = 5;
    std::cout<<sol.searchInsert(nums,target)<<std::endl;


    return 0;
}