#include <iostream>
#include <vector>


class Solution{
    public:
        bool canJump(std::vector<int>& nums){
            int n =nums.size();
            int farthest = 0;
            for(int i=0;i<n-1;i++){
                farthest = std::max(farthest, i+nums[i]);
                if(farthest<=i){
                    return false;
                }
            }
            return farthest>=n-1;
        }
};

int main(){

    return 0;
}