#include <iostream>

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution{
    public:
        std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
            std::vector<std::vector<std::string>> res;
            std::unordered_map<std::string,std::vector<std::string>> strmap;
            for(const auto& str:strs){
                std::string sortstr=str;
                std::sort(sortstr.begin(),sortstr.end());
                strmap[sortstr].push_back(str);


            }
            for(const auto& pair : strmap){
                res.push_back(pair.second);
            }
            return res;



        }


};


int main(){
    Solution s;
    std::vector<std::string> strs={"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> res=s.groupAnagrams(strs);
    for(const auto& vec:res){
        for(const auto& str:vec){
            std::cout<<str<<" ";

        }
        std::cout<<std::endl;
    }



    return 0;
}