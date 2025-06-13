#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Solution{
    public:
        int largestRectangleArea(std::vector<int>& heights){
            int res =0;
            std::stack<int> st;
            
            int n = heights.size();
            for(int i=0;i<n;i++){
                while(!st.empty() && heights[st.top()]>heights[i]){
                    int h = heights[st.top()];
                    st.pop();
                    int w =i;
                    if(!st.empty()){
                        w=i-st.top()-1;
                    }
                    
                    
                    res = std::max(res,h*w);
                    
                }

            
                st.push(i);
                
            }

            while(!st.empty()){
                int h = heights[st.top()];
                st.pop();
                int w =n;
                if(!st.empty()){
                    w = n-st.top()-1;
                }
                res = std::max(res,h*w);
            }
            return res;
        }
};


int main(){
    Solution sol;
    std::vector<int> heights = {2,1,5,6,2,3};
    std::cout<<sol.largestRectangleArea(heights)<<std::endl;


    return 0;
}