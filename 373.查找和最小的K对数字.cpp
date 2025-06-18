#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class SOlution{
    public:
        std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1,std::vector<int>& nums2,int k){
            std::vector<std::vector<int>> res;
            if(nums1.empty() || nums2.empty() || k<=0){
                return res;
            }
            auto cmp=[&](const std::pair<int,int>& a,const std::pair<int,int>& b){
                return nums1[a.first]+nums2[a.second]>nums1[b.first]+nums2[b.second];
            };

            std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,decltype(cmp)>minHeap(cmp);

            for(int i=0;i<nums1.size()&&i<k;i++){
                minHeap.emplace(i,0);
            }

            while(k-- >0 && !minHeap.empty()){
                auto [i,j] = minHeap.top();
                minHeap.pop();
                res.push_back({nums1[i],nums2[j]});

                if(j+1 < nums2.size()){
                    minHeap.emplace(i,j+1);
                }
            }
            return res;

        }
};




int main(){

    return 0;
}