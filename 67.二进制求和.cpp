#include <iostream>
#include <string>


class Solution{
    public:
        std::string addBinary(std::string a,std::string b){
            int carry=0;
            std::string res="";
            int m=a.size();
            int n=b.size();
            int i=m-1;
            int j=n-1;
            while(i>=0 || j>=0){
                int sum=carry;
                if(i>=0){
                    sum+=a[i]-'0';
                    i--;

                }
                if(j>=0){
                    sum+=b[j]-'0';
                    j--;
                }
                res=std::to_string(sum%2)+res;
                carry=sum/2;


            }
            if(carry>0){
                res=std::to_string(carry)+res;

            }
            return res;
        }
};



int main(){


    return 0;
}