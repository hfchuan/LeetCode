#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        void quickSort(std::vector<int>& nums,int start,int end){
            if(start<end){
                int base=nums[start];
                int left=start;
                int right=end;
                while(left<right){
                    while(left<right && nums[right]>=base){
                        right--;
                    }
                    nums[left] = nums[right];
                    while(left<right && nums[left]<base){
                        left++;
                    }
                    nums[right] = nums[left];
                }
                nums[left] = base;
                quickSort(nums,start,left-1);
                quickSort(nums,left+1,end);
            }
        }
};


int main(){
    std::vector<int > nums = {5,2,7,5,1,8,4,6};
    Solution sol;
    sol.quickSort(nums,0,nums.size()-1);
    for(int i=0;i<nums.size();i++){
        std::cout<<nums[i]<<" ";
    }
    std::cout<<std::endl;


    return 0;
}