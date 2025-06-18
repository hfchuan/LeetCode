#include <iostream>
#include <vector>


class SOlution{
    public:
        std::vector<std::vector<int>> combine(int n,int k){
            std::vector<std::vector<int>> res;
            std::vector<int> path;
            backtrack(n,k,1,path,res);
            return res;
        }

        void backtrack(int n,int k,int start,std::vector<int>& path,std::vector<std::vector<int>>& res){
            if(path.size() == k){
                res.push_back(path);

            }
            for(int i=start;i<=n;i++){
                path.push_back(i);
                backtrack(n,k,i+1,path,res);
                path.pop_back();

            }
            
        }
};


int main(){


    return 0;
}