#include <iostream>
#include <vector>

class Solution{
    public:
        void moveZeroes(std::vector<int>& nums){
            int j=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    nums[j]=nums[i];
                    j++;
                }
            }

            for(;j<nums.size();j++){
                nums[j]=0;
            }

            for(int i=0;i<nums.size();i++){
                std::cout<<nums[i]<<" ";
            }


        }
};

int main(){

    std::vector<int> nums ={0,1,0,3,12};
    Solution s;
    s.moveZeroes(nums);
    
    




    return 0;
}