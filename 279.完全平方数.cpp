#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

int numSquares(int n){

    std::vector<int> dp(n+1,INT_MAX);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            dp[i] = std::min(dp[i],dp[i-j*j]+1);
        }
    }

    return dp[n];
}


int main(){
    int n=12;
    int res = numSquares(n);
    std::cout<<res<<std::endl;

    return 0;
}