#include <iostream>
#include <string>
#include <vector>

class Solution{
    public:
        std::vector<std::vector<std::string>> partition(std::string s){
            std::vector<std::vector<std::string>> res;
            std::vector<std::string> path;
            backtrack(s,0,path,res);
            return res;
        }

    private:
        void backtrack(std::string s, int start, std::vector<std::string>& path, std::vector<std::vector<std::string>>& res){
            if(start == s.size()){
                res.push_back(path);
                return;
            }
            for(int i=start;i<s.size();i++){
                std::string substring = s.substr(start,i-start+1);
                if(isPalindrome(substring)){
                    path.push_back(substring);
                    backtrack(s,i+1,path,res);
                    path.pop_back();
                }
            }
        }

        bool isPalindrome(std::string s){
            int left = 0, right = s.size()-1;
            while(left < right){
                if(s[left]!=s[right]){
                    return false;
                }
                ++left;
                --right;
            }
            return true;

        }
};


int main(){


    return 0;
}