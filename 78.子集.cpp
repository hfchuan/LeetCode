#include <iostream>
#include <vector>


class Solution{
    public:
        std::vector<std::vector<int>> subsets(std::vector<int>& nums){
            std::vector<std::vector<int>> res;
            std::vector<int> currentSubset;
            backtrack(nums,0,currentSubset,res);
            return res;
        }

    private:
        void backtrack(const std::vector<int>& nums,int start,std::vector<int>&  currentSubset,std::vector<std::vector<int>>& res){
            res.push_back(currentSubset);
            for(int i=start;i<nums.size();i++){
                currentSubset.push_back(nums[i]);
                backtrack(nums,i+1,currentSubset,res);
                currentSubset.pop_back();
            }
        }
    
};

int main(){


    return 0;
}