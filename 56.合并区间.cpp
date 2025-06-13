#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals){
            std::vector<std::vector<int>> res;
            if(intervals.empty()) {
                return res;
            }
            std::sort(intervals.begin(),intervals.end());
            for(int i=0;i<intervals.size();i++){
                if(res.empty()){
                    res.push_back(intervals[i]);
                }
                if (res.back()[0]>intervals[i][1]){
                    res.push_back(intervals[i]);
                    continue;

                }
                if(res.back()[1]>=intervals[i][0] || res.back()[0]>intervals[i][0]){
                    res.back()[1] =std::max(res.back()[1],intervals[i][1]);
                    res.back()[0] = std::min(res.back()[0],intervals[i][0]);
                }
                
                else{
                    res.push_back(intervals[i]);
                }
            }

            return res;


        }
};


int main(){
    Solution sol;
    std::vector<std::vector<int>> intervals ={{1,4},{0,4}};
    std::vector<std::vector<int>> res = sol.merge(intervals);
    for(const auto& i:res){
        for(const auto&j:i){
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;


    return 0;
}