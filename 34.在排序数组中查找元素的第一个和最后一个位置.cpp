#include <iostream>
#include <vector>

class Solution{
    public:
        std::vector<int> searchRange(std::vector<int>& nums,int target){
            int left =0,right = nums.size()-1;
            std::vector<int> res(2,-1);
            while(left <=right){
                int mid =(left+right)/2;
                if(nums[mid] == target){
                    res[0] = mid;
                    res[1] = mid;
                    while(res[0]-1>=0 && nums[res[0]-1] == target){
                        res[0]--;
                    }
                    while(res[1]+1<nums.size() && nums[res[1]+1] == target){
                        res[1]++;
                    }
                    return res;
                }
                else if(nums[mid] < target){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            return res;
            

            
        }
};

int main(){
    Solution sol;
    std::vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    std::vector<int> res = sol.searchRange(nums,target);
    for(int i=0;i<res.size();i++){
        std::cout<<res[i]<<" ";

    }
    std::cout<<std::endl;


    return 0;
}