#include <iostream>
#include <vector>
#include <string>

class Solution{
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs){
           
            int n=strs.size();
            std::string minlen=strs[0];
            for(int i=1;i<n;i++){
                if(strs[i].length()<minlen.length()){
                    minlen=strs[i];
                }


            }
            int len=minlen.length();
            std::string res="";
            for(int i=0;i<len;i++){
                char c=minlen[i];
                for(int j=0;j<n;j++){
                    if(strs[j][i]==c){
                        if(j==n-1){
                            res+=c;
                        }
                        
                    }
                    else{
                        return res;
                    }

                }
            }
            return res;

            
        }

};


int main(){


    return 0;
}