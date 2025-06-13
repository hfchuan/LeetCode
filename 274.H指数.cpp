#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        int hIndex(std::vector<int>& citations){
            int n=citations.size();
            std::sort(citations.begin(),citations.end());
            int h=0;
            for(int i=n-1;i>=0;i--){
                if(citations[i]>h){
                    h++;
                }
                else{
                    return h;
                }
                
            }
            return h;
            
        }
};


int main(){


    return 0;
}