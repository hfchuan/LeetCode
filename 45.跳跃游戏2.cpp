#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        int jump(std::vector<int>& nums){
            int n = nums.size();
            if(n<=1){
                return 0;
            }

            int jumps = 0;
            int currend = 0;
            int farthest = 0;

            for(int i=0;i<n-1;i++){
                farthest = std::max(farthest,i+nums[i]);
                if(i==currend){
                    jumps++;
                    currend = farthest;

                    if(currend>=n-1){
                        break;
                    }
                }
            }
            return jumps;
        }
};


int main(){


    return 0;
}