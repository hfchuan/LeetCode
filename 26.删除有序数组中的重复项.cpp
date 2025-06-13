#include <iostream>
#include <vector>

class Solution{
    public:
        int removeDuplicates(std::vector<int>& nums){
            if(nums.empty()){
                return 0;
            }
            int i=0;
            for(int j=1;j<nums.size();j++){
                if(nums[i]!=nums[j]){
                    nums[i] = nums[j];
                    i++;
                }

            }
            return i+1;

        }
};

int main(){



}