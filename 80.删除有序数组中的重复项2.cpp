#include <iostream>
#include <vector>

class Solution{
    public:
        int removeDuplicates(std::vector<int>& nums){
            int i=1,count=1;
            for(int j=1;j<nums.size();j++){
                
                if(nums[j]==nums[j-1]){
                    count++;
                    
                }
                else {
                    count =1;
                }

                if(count<=2){
                    nums[i] = nums[j];
                    i++;
                }
            }

            return i;

        }
};

int main(){


    return 0;
}