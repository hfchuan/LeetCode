#include <iostream>
#include <vector>
#include <algorithm>


class Solution{
    public:
        std::vector<std::vector<int>> permute(std::vector<int>& nums){
            std::vector<std::vector<int>> res;
            backtrack(nums,0,res);
            return res;
        }

    private:
        void backtrack(std::vector<int> &nums,int start,std::vector<std::vector<int>>& res){
            if(start == nums.size()){
                res.push_back(nums);
                return;
            }

            for(int i=start;i<nums.size();i++){
                std::swap(nums[start],nums[i]);
                backtrack(nums,start+1,res);
                std::swap(nums[start],nums[i]);
            }


        }





};




int main(){
    Solution sol;
    std::vector<int> nums={1,2,3};
    std::vector<std::vector<int>> res = sol.permute(nums);
    for(const auto& i : res){
        for(const auto& j : i){
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }


    return 0;
}