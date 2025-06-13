#include <iostream>
#include <vector>

class Solution{
    public:
        std::vector<int> twoSum(std::vector<int>& nums,int target){
            int l=nums.size()-1;
            std::vector<int> res;
            for(int i=0;i<=l;i++){
                for(int j=i+1;j<=l;j++){
                    if(nums[i]+nums[j] == target){
                        res.push_back(i);
                        res.push_back(j);
                        return res;
                        
                    }

                }
            }
            return res;       
        }

        
};


int main(){

    Solution s;
    std::vector<int> nums={3,2,4};
    int target=6;
    std::vector<int> res=s.twoSum(nums,target);
    for(std::vector<int>::iterator it=res.begin();it!=res.end();it++){
        std::cout<<*it<<""<<std::endl;
    }


    return 0;
}