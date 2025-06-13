#include <iostream>
#include <string>

class Solution{
    public:
        int romanToInt(std::string s){
            int res=0;
            int pre=0;
            for(int i=s.size()-1;i>=0;i--){
                int cur=0;
                if(s[i]=='M'){
                    cur=1000;
                    
                }
                else if(s[i]=='D'){
                    cur=500;
                }
                else if(s[i]=='C'){
                    cur=100;
                }
                else if(s[i]=='L'){
                    cur=50;
                    }
                else if(s[i]=='X'){
                    cur=10;
                }
                else if(s[i]=='V'){
                    cur=5;
                }
                else if(s[i]=='I'){
                    cur=1;
                }
                if(cur<pre){
                    res-=cur;

                }
                else{
                    res+=cur;
                    pre=cur;
                }
            }
            return res;
                
            
        }
};


int main(){

    return 0;
}