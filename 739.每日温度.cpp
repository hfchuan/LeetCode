#include <iostream>
#include <vector>
#include <stack>

class Solution{
    public:
        std::vector<int> dailyTemperatures(std::vector<int>& t){
            std::vector<int> res(t.size(),0);
            std::stack<int> st;
            for(int i=0;i<t.size();i++){
                while(!st.empty() && t[i]>t[st.top()]){
                    int index=st.top();
                    st.pop();
                    res[index] = i-index;
                }
                st.push(i);
            }
            return res;

        }
};


int main(){
    Solution sol;
    std::vector<int> t={73,74,75,71,69,72,76,73};
    std::vector<int> res=sol.dailyTemperatures(t);
    for(const auto& n:res){
        std::cout<<n<<" ";
    }
    std::cout<<std::endl;


    return 0;
}