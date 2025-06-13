#include <iostream>
#include <vector>

class Solution{
    public:
        std::string convert(std::string s,int numRows){
            if(numRows==1){
                return s;
            }
            int len=s.length();
            std::vector<std::string> res(numRows,"");
            int row=0;
            bool down=false;
            for(auto c:s){
                res[row] +=c;
                if(row==0 || row==numRows-1){
                    down=!down;
                }
                row+=down ? 1 : -1;
            }
            std::string str;
            for(auto r:res){
                str+=r;
            }
            return str;

        }
};

int main(){

    return 0;
}