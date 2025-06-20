#include <iostream>
#include <vector>

class Solution{
    public:
        int rangeBitwiseAnd(int left,int right){
            int shift=0;
            while(left<right){
                left>>=1;
                right>>=1;
                shift++;
            }
            return left<<shift;
   
        }
};


int main(){
    Solution sol;
    int left=1,right=1;
    int res=sol.rangeBitwiseAnd(left,right);
    std::cout<<res<<std::endl;


    return 0;
}