#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        void rotate(std::vector<int>& nums,int k){
            int n=nums.size();
            k=k%n;
            if(k==0){
                return;
            }
            std::reverse(nums.begin(),nums.end());
            std::reverse(nums.begin(),nums.begin()+k);
            std::reverse(nums.begin()+k,nums.end());

        }
};

int main(){
    Solution sol;
    std::vector<int> nums={1,2,3,4,5,6,7};
    int k=3;
    sol.rotate(nums,k);

    return 0;
}