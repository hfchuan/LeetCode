#include <iostream>
#include <string>
#include <unordered_set>



class Solution{
    public:
        int lengthOfLongestSubstring(std::string s){
            int res = 0;
            int n = s.size();
            int i = 0,j=0;
            std::unordered_set<char> set;
            for(int j=0;j<n;j++){
                while(set.find(s[j]) != set.end()){
                    set.erase(s[i]);
                    i++;
                }
                
                
                set.insert(s[j]);


                res=std::max(res,j-i+1);

            }






            return res;

        }
            
};

int main(){
    Solution s;
    std::string str = "abcabcbb";
    std::cout<<s.lengthOfLongestSubstring(str)<<std::endl;



    return 0;
}
