#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


class Solution{
    public:
        std::string minWindow(std::string s,std::string t){
            std::string res ="";
            int n =s.size();
            int m =t.size();
            if(m>n){
                return res;
            }
            std::unordered_map<char,int> s_count;
            std::unordered_map<char,int> t_count;
            for(int i=0;i<m;i++){
                t_count[t[i]]++;
            }
            int left=0,right=0,start=0;
            int required = t_count.size();
            int formed =0;
            int min_len=n+1;
            for(;right<n;right++){
                s_count[s[right]]++;
                if(t_count.find(s[right]) != t_count.end() && s_count[s[right]] == t_count[s[right]]){
                    formed++;
                }
                while(left<=right && formed ==required){
                    if(right-left+1 < min_len){
                        min_len = right-left+1;
                        start =left;
                    }
                    s_count[s[left]]--;
                    if(t_count.find(s[left]) != t_count.end() && s_count[s[left]] < t_count[s[left]]){
                        formed--;
                    }
                    left++;
                }


            }
            if(min_len ==n+1){
                return res;
            }
            res = s.substr(start,min_len);
            





            return res;

        }
};


int main(){
    Solution sol;
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string res = sol.minWindow(s,t);
    
    std::cout << res << std::endl;


    return 0;
}