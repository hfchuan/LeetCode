#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>



class Solution {
public:
    std::vector<int> findAnagrams(std::string s,std::string p){
        int slen = s.size();
        int plen = p.size();
        std::vector<int> res;
        if(plen>slen){
            return res;
        }

        std::vector<int> scount(26,0);
        std::vector<int> pcount(26,0);
        for(int i=0;i<plen;i++){
            scount[s[i]-'a']++;
            pcount[p[i]-'a']++;
        }

        if(scount == pcount){
            res.push_back(0);
        }

        for(int i=0;i<slen-plen;i++){
            scount[s[i]-'a']--;
            scount[s[i+plen]-'a']++;
            if(scount == pcount){
                res.push_back(i+1);
            }

        }







        return res;
    }
};



int main(){

    Solution sol;
    std::string s = "cbaebabacd";
    std::string p = "abc";
    std::vector<int> res = sol.findAnagrams(s,p);
    for(int index : res){
        std::cout<<index<<" ";
    }





    return 0;
}