#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution{
    public:
        std::vector<std::string> letterCombinations(std::string digits){
            std::vector<std::string> res;
            if(digits.empty()){
                return res;
            }

            std::unordered_map<char,std::string> mp ={
                {'2',"abc"},
                {'3',"def"},
                {'4',"ghi"},
                {'5',"jkl"},
                {'6',"mno"},
                {'7',"pqrs"},
                {'8',"tuv"},
                {'9',"wxyz"}
            };

            backtrack(res,mp,digits,"");
            return res;

        }

    private:
        void backtrack(std::vector<std::string>& res,const std::unordered_map<char,std::string>& mp,const std::string& digits,std::string combination){
            if(digits.empty()){
                res.push_back(combination);
            }
            else{
                std::string letters = mp.at(digits[0]);
                for(const auto& letter : letters){
                    backtrack(res,mp,digits.substr(1),combination+letter);
                }
            }

        };
};

int main(){


    return 0;
}