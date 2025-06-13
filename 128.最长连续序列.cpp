#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution{
    public:
        int longestnums(std::vector<int>& nums){
            int res=0;
            std::unordered_set<int> set_nums;
            for(const auto& num:nums){
                set_nums.insert(num);
            }
            for(const auto& num:set_nums){
                int currentnum;
                int currentres=1;
                if(!set_nums.count(num-1)){
                    
                    currentnum = num;

                    while(set_nums.count(currentnum+1)){
                        currentnum+=1;
                        currentres+=1;

                }

                res = std::max(res,currentres);
                

                }
                
            }

            return res;

        }
};



int main(){


    std::vector<int> nums ={100,4,200,1,3,2};
    Solution s;
    int res = s.longestnums(nums);
    std::cout<<res<<std::endl;



    return 0;

}