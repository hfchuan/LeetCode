#include <iostream>
#include <vector>
#include <algorithm>


class Solution{
    public:
        std::vector<std::string> summaryRanges(std::vector<int>& nums){
            std::vector<std::string> res;
            if(nums.empty()){
                return res;
            }
            int start = nums[0];
            int end = nums[0];
            for(int i=1;i<nums.size();i++){
                if(nums[i]==end+1){
                    end = nums[i];

                }
                else{
                    if(start==end){
                        res.push_back(std::to_string(start));

                    }
                    else{
                        res.push_back(std::to_string(start)+"->"+std::to_string(end));

                    }
                    start = nums[i];
                    end = nums[i];

                }
                
                }
                
                    if(start==end){
                        res.push_back(std::to_string(start));

                    }
                    else{
                        res.push_back(std::to_string(start)+"->"+std::to_string(end));
                       

                    }

            
            return res;

        }
};


int main(){


    return 0;
}