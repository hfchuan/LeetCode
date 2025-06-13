#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>




class Solution{
    public:
        bool wordBreak(std::string s,std::vector<std::string>& wordDict){
            auto wordDictSet = std::unordered_set<std::string> ();
            for(auto word : wordDict){
                wordDictSet.insert(word);
            }

            auto dp = std::vector<bool>(s.size() + 1);
            dp[0] = true;
            for(int i = 1;i<=s.size();i++){
                for(int j =0;j<i;j++){
                    if(dp[j] && wordDictSet.find(s.substr(j,i-j)) != wordDictSet.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }

            return dp[s.size()];

        }
};



int main(){
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet","code"};
    Solution sol;

    if(sol.wordBreak(s,wordDict)){
        std::cout<<"可以拼接出字符串 s"<<std::endl;

    }
    else{
        std::cout<<"不可以拼接出字符串 s"<<std::endl;
    }


    return 0;
}