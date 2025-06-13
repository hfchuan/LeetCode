#include <iostream>
#include <vector>
#include <algorithm>

int coinChange(std::vector<int>& coins,int amount){
    std::vector<int> dp(amount+1,amount+1);
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        for(const int& coin : coins){
            if(i-coin>=0){
                dp[i] = std::min(dp[i],dp[i-coin]+1);
            }
        }


    }
    return dp[amount]>amount? -1 : dp[amount];
}



int main(){


    return 0;
}