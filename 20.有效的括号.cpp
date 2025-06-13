#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

class Solution{
    public:
        bool isValid(std::string s){
            int n=s.length();
            if(n%2!=0){
                return false;
            }
            std::stack<char> st;
            std::unordered_map<char,char> mp ={{')','('},{'}','{'},{']','['}};
            for(const auto&c:s){
                if(mp.count(c) ==0 ){
                    st.push(c);
                }
                else{
                    if(st.empty() || st.top() !=mp[c]){
                        return false;
                    }
                    st.pop();

                }
            }

            return st.empty();
            



        }




};



int main(){
    Solution sol;
    std::string s = "()[]{}";
    
    std::cout<<sol.isValid(s)<<std::endl;



    return 0;
}