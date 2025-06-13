#include <iostream>
#include <vector>

class Solution{
    public:
        bool isSubsequence(std::string s,std::string t){
            int i=0,j=0;
            while(i<s.size() && j<t.size()){
                if(s[i]==t[j]){
                    i++;
                }
                j++;

                
            }
            if(i==s.size()){
                return true;
            }
            else{
                return false;
            }
        }
};


int main(){


    return 0;
}