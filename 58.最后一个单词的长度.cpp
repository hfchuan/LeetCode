#include <iostream>
#include <string>

class Solution{
    public:
        int lengthOfLastWord(std::string s){
            int len=0;
            int i=s.size()-1;
            while(i>=0 && s[i]==' '){
                
                i--;
            }
            while(i>=0 && s[i]!=' '){
                len++;
                i--;
            }
            return len;
        }
};


int main(){


    return 0;
}