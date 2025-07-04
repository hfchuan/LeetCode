#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        std::vector<std::vector<int>> ThreeNumberSum(std::vector<int>&nums){
            std::vector<std::vector<int>> res;
            std::sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size()-2;i++){
                if(i>0 && nums[i] == nums[i-1]){
                    continue;
                }
                int left = i+1;
                int right = nums.size()-1;
                while(left<right){
                    int sum = nums[i] + nums[left] + nums[right];
                    if(sum == 0){
                        res.push_back({nums[i],nums[left],nums[right]});
                        
                        while(left<right && nums[left] == nums[left+1]){
                            left++;
                        }
                        while(left<right && nums[right] == nums[right-1]){
                            right--;
                        }
                        left++;
                        right--;
                    }

                    if(sum<0){
                        left++;
                    }
                    if(sum>0){
                        right--;
                    }


                }
            }
            

            return res;


        }

        
};

int main(){
    Solution s;
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    
    std::vector<std::vector<int>> res = s.ThreeNumberSum(nums);

    for(const auto &i:res){
        for(const auto &j:i){
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
    


    return 0;
}