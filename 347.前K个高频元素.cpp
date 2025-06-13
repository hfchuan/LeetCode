#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>


class Solution{
    public:
        std::vector<int> topKFrequent(std::vector<int>& nums,int k){
            std::unordered_map<int,int> freq;
            for(const auto& num:nums){
                freq[num]++;
            }

            std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> minHeap;
            for(const auto& [num,count]:freq){
                minHeap.push({count,num});
                if(minHeap.size()>k){
                    minHeap.pop();
                }
            }
            std::vector<int> res;
            while(!minHeap.empty()){
                res.push_back(minHeap.top().second);
                minHeap.pop();
            }
            return res;
        }
};

int main(){


    return 0;
}