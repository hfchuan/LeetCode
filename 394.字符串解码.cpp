#include <iostream>
#include <string>
#include <stack>
#include <cctype>


class Solution{
    public:
        std::string decodeString(std::string s){
            std::stack<int> countStack;
            std::stack<std::string> stringStack;
            std::string currentString;
            int currentNum = 0;
            for(char c : s){
                if(std::isdigit(c)){
                    currentNum = currentNum *10 + (c -'0');
                }
                else if(c=='['){
                    countStack.push(currentNum);
                    stringStack.push(currentString);
                    currentNum=0;
                    currentString.clear();
                }
                else if(c==']'){
                    std::string prevString = stringStack.top();
                    stringStack.pop();
                    int repeatTimes = countStack.top();
                    countStack.pop();
                    for(int i=0;i<repeatTimes;i++){
                        prevString+=currentString;

                    }
                    currentString = prevString;
                }
                else{
                    currentString+=c;
                }
            }
            return currentString;

        }
};


int main(){
    std::string s = "3[a]2[bc]";
    Solution sol;
    std::string result = sol.decodeString(s);
    std::cout<<result<<std::endl;


    return 0;
}