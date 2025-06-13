#include <iostream>
#include <vector>

class Solution{
    public:
        int canCompleteCircuit(std::vector<int>& gas,std::vector<int>& cost){
            int n=gas.size();
            int sum=0;
            int start=0;
            int tank=0;
            for(int i=0;i<n;i++){
                sum+=gas[i]-cost[i];
                tank+=gas[i]-cost[i];
                if(tank<0){
                    start=i+1;
                    tank=0;
                    continue;

                }

            }

            if(sum>=0){
                return start;
            }
            else{
                return -1;
            }
        }
};


int main(){


    return 0;
}