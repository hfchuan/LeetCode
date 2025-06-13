#include <iostream>
#include <vector>

class SOlution{
    public:
        int minSubArrayLen(int target,std::vector<int>& nums){
            int n=nums.size();
            int left=0,right=0,sum=0,minlen=n+1;
            while(right<n){
                sum+=nums[right];
                while(sum>=target){
                    sum-=nums[left];
                    minlen=std::min(minlen,right-left+1);
                    left++;
                    

                }
                
                right++;
            }
            if(minlen==n+1){
                return 0;
            }
            return minlen;
        }
};


int main(){


    return 0;
}