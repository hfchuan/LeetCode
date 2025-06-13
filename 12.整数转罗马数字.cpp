#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution{
    public:
        std::string intToRoman(int num){

            std::vector<std::pair<int,std::string>> map={
                {1000,"M"},
                {900,"CM"},
                {500,"D"},
                {400,"CD"},
                {100,"C"},
                {90,"XC"},
                {50,"L"},
                {40,"XL"},
                {10,"X"},
                {9,"IX"},
                {5,"V"},
                {4,"IV"},
                {1,"I"}

            };
           
            std::string result;
            for(auto p:map){
                while(num>=p.first){
                    result+=p.second;
                    num-=p.first;
                }
            }
            return result;
        }
};


int main(){


    return 0;
}