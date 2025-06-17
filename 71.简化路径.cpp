#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>


class SOlution{
    public:
        std::string simplifyPath(std::string path){
            std::stack<std::string> stk;
            std::stringstream ss(path);
            std::string dir;
            while(std::getline(ss,dir,'/')){
                if(dir.empty() || dir == "."){
                    continue;
                }
                if(dir == ".."){
                    if(!stk.empty()){
                        stk.pop();
                    }

                }
                else{
                    stk.push(dir);
                }
            }
            std::string res;
            while(!stk.empty()){
                res = "/" + stk.top() + res;
                stk.pop();
            }

            if(res.empty()){
                res = "/";
            }

            return res;

            
        }
};




int main(){


    return 0;
}