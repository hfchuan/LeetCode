#include <iostream>
#include <vector>

class Solution{
    public:
        std::vector<int> productExceptSelf(std::vector<int>& nums){
            std::vector<int> res(nums.size(),1);
            int left=0,right=nums.size()-1;
            int lp=1,rp=1;
            while(right>=0 && left<=nums.size()-1){
                res[right]*=rp;
                res[left]*=lp;
                lp*=nums[left++];
                rp*=nums[right--];
            }
            return res;

        }

    
};


int main(){
    Solution sol;
    std::vector<int> nums={1,2,3,4};
    std::vector<int> res=sol.productExceptSelf(nums);
    for(const auto&num:res){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;



    return 0;
}