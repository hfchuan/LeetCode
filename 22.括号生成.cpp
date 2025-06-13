#include <iostream>
#include <vector>
#include <string>

class Solution{
    public:
        std::vector<std::string> generateParenthesis(int n){
            std::vector<std::string> res;
            std::string s;
            backtrack(res,s,0,0,n);
            return res;


        }

    private:
        void backtrack(std::vector<std::string>& res,std::string& s,int left,int right,int n){
            if(s.size() == 2*n){
                res.push_back(s);
                return;

            }
            if(left < n){
                s.push_back('(');
                backtrack(res,s,left+1,right,n);
                s.pop_back();
            }
            if(right < left){
                s.push_back(')');
                backtrack(res,s,left,right+1,n);
                s.pop_back();
            }

        }
};

int main(){

    return 0;
}