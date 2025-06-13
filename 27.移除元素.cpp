#include <iostream>
#include <vector>

class Solution{
    public:
        int removeElement(std::vector<int>& nums,int val){
            int i=0,j=0;
            while(j<nums.size()){
                if(nums[j] != val){
                    nums[i] = nums[j];
                    i++;
                }
                j++;
            }

            return i;
        }
};


int main(){


    return 0;
}