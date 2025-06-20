#include <iostream>
#include <vector>



class Solution{
    public:
        int singleNumber(std::vector<int>& nums){
            int res=0;
            for(int i=0;i<32;i++){
                int count=0;
                for(auto num:nums){
                    count+=(num>>i)&1;
                }
                if(count%3 !=0){
                    res |= (1<<i);
                }
            }
            return res;


        }
};


int main(){

    return 0;
}