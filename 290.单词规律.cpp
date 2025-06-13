#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution{
    public:
        bool wordPattern(std::string pattern,std::string s){
            std::unordered_map<char,std::string> mp1;
            std::unordered_map<std::string,char> mp2;
            int m=s.size();
            int i=0;
            for(auto ch:pattern){
                if(i>=m){
                    return false;
                }
                int j=i;
                while(j<m && s[j] != ' '){
                    j++;
                }
                const std::string &tmp = s.substr(i,j-i);
                if(mp2.find(tmp) != mp2.end() && mp2[tmp] != ch){
                    return false;

                }
                if(mp1.find(ch) != mp1.end() && mp1[ch] != tmp){
                    return false;
                }
                mp2[tmp] = ch;
                mp1[ch] = tmp;
                i=j+1;
            }
            return i>=m;

        }       
    
};


int main(){


    return 0;
}