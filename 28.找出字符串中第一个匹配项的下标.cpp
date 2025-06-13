#include <iostream>
#include <string>

class Solution{
    public:
        int strStr(std::string haystack,std::string needle){
            if(needle.empty()){
                return 0;

            }
            int n = haystack.length();
            int m = needle.length();
            for(int i=0;i<=n-m;i++){
                if(haystack.substr(i,m)==needle){
                    return i;
                }
                else{
                    continue;
                }
            }
            return -1;
        }
};



int main(){


    return 0;
}