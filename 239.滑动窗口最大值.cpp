#include <iostream>
#include <vector>
#include <deque>


class Solution{
    public:
        std::vector<int> maxSlidingWindow(std::vector<int>& nums,int k){
            std::vector<int> res;
            if(nums.empty() || k> nums.size()){
                return res;
            }
            std::vector<int> window;
            for (int i=0;i<k;i++){
                window.push_back(nums[i]);
            }
            int max_val = findMax(window);
            res.push_back(max_val);
            for(int i=k;i<nums.size();i++){
                window.erase(window.begin());
                window.push_back(nums[i]);
                max_val = findMax(window);
                res.push_back(max_val);
            }

            return res;
            



        }


        std::vector<int> maxSlidingWindow2(std::vector<int>& nums,int k){
            std::vector<int> res;
            std::deque<int> dp;
            
            for(int i=0;i<nums.size();i++){
                while(!dp.empty() && nums[dp.back()] < nums[i]){
                    dp.pop_back();
                }
                dp.push_back(i);

                if(dp.front() ==i-k){
                    dp.pop_front();
                }

                if(i>=k-1){
                    res.push_back(nums[dp.front()]);
                }

            }
            return res;
            
            
        }

    private: 
        int findMax(std::vector<int>& window){
            int max_val = window[0];
            for(int i=1;i<window.size();i++){
                if(window[i]>max_val){
                    max_val = window[i];
                }
            }
            return max_val;
        }
};



int main(){
    Solution sol;
    std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    std::vector<int> res = sol.maxSlidingWindow2(nums,k);
    for(const auto &num:res){
        std::cout<<num<<" ";
    }



    return 0;
}