#include <iostream>
#include <vector>


class Solution{
    public:
        int hammingWeight(int n){
            int count=0;
            while(n!=0){
                n=n&(n-1);
                count++;

            }
            return count;
        }
};


int main(){

    return 0;
}