#include <iostream>
#include <string>
#include <stack>

class MinStack{
    public:
        MinStack(){
            

        }

        void push(int val){
            mainStack.push(val);
            if(minStack.empty() || val<=minStack.top()){
                minStack.push(val);
            }

        }

        void pop(){
            if(mainStack.empty()){
                return;
            }
            int topval = mainStack.top();
            mainStack.pop();
            if(topval == minStack.top()){
                minStack.pop();
            }

        }

        int top(){
            if(mainStack.empty()){
                return -1;
            }
            return mainStack.top();

        }

        int getMin(){
            if(minStack.empty()){
                return -1;
            }
            return minStack.top();

        }

    private:
        std::stack<int> mainStack;
        std::stack<int> minStack;


};


int main(){


    return 0;
}