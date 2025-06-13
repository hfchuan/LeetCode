#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>


class Solution{
    public:
        std::vector<int> partitionLabels(std::string s){
            int n = s.size();   
            std::vector<int> res;
            std::unordered_map<char,int> lastPosition;

            for(int i=0;i<n;i++){
                lastPosition[s[i]] = i;
            }
            int currend = 0;
            int start = -1;
            for(int i=0;i<n;i++){
                currend = std::max(currend,lastPosition[s[i]]);
                if(i==currend){
                    res.push_back(currend-start);
                    start = i;
                }
            }
            return res;
        }
};

int main(){


    return 0;
}