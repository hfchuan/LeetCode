#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        int maxProfit(std::vector<int>& prices){
            if(prices.empty()){
                return 0;
            }

            int minPrice = prices[0];
            int maxProfit = 0;
            for(int i = 1; i<prices.size();i++){
                minPrice = std::min(minPrice,prices[i]);
                int curProfit = prices[i]-minPrice;
                maxProfit=std::max(maxProfit,curProfit);
            }
            return maxProfit;
        }
};

int main(){


    return 0;
}