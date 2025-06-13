#include <iostream>
#include <string>
#include <unordered_map>

class Solution{
    public:
        bool isIsomorphic(std::string s,std::string t){
            if(s.size()!=t.size()){
                return false;
            }
            std::unordered_map<char,char> m1,m2;
            for(int i=0;i<s.size();i++){
                if(m1.find(s[i])==m1.end()){
                    if(m2.find(t[i])!=m2.end()){
                        return false;
                    }
                    m1[s[i]]=t[i];
                    m2[t[i]]=s[i];
                
                
                }
                else{
                    if(m1[s[i]]!=t[i] || m2[t[i]] != s[i]){
                        return false;
                    }

                }

            }
            return true;
        }
};


int main(){


    return 0;
}