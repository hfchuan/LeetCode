#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
    public:
        int subarraySum1(std::vector<int>& nums,int k){
            int res=0;
            int sum = 0;
            int n = nums.size();
            for(int start=0;start<n;++start){
                for(int end=start;end>=0;--end){
                    sum+=nums[end];
                    if(sum==k){
                        res++;
                    }
                }
            }

            return res;
        }

        int subarraySum2(std::vector<int>& nums, int k){
            int res=0;
            int sum = 0;
            int n = nums.size();
            int l=0;
            for(int r=0;r<n;++r){
                sum+=nums[r];
                if(sum==k){
                    res++;
                }
                if(sum<k){
                    continue;
                }
                while(sum>k && l<=r){
                    sum-=nums[l];
                    l++;
                    if(sum==k){
                        res++;
                    }
                }

            }
            return res;
        }


        int subarraySum3(std::vector<int>& nums, int k){
            int res=0;
            int sum=0;
            std::unordered_map<int,int> mp;
            mp[0]=1;
            for(const auto& num:nums){
                sum+=num;
                if(mp.count(sum-k)){
                    res+=mp[sum-k];
                }
                mp[sum]++;
            }

            return res;
        }
};


int main(){

    Solution sol;
    std::vector<int> nums = {1,1,1};
    int k=2;
    std::cout<<sol.subarraySum3(nums,k)<<std::endl;


    return 0;
}