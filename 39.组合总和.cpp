#include <iostream>
#include <vector>


class Solution{
    public:
        std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,int target){
            std::vector<std::vector<int>> res;
            std::vector<int > path;
            backtrack(candidates,target,0,path,res);
            return res;
        }

    private:
        void backtrack(const std::vector<int>& canditates,int target,int start,std::vector<int>& path,std::vector<std::vector<int>>& res){
            if(target == 0){
                res.push_back(path);
                return ;
            }

            if(target < 0){
                return ;
            }

            for(int i = start;i<canditates.size();i++){
                path.push_back(canditates[i]);
                backtrack(canditates,target-canditates[i],i,path,res);
                    path.pop_back();
                }
            
        }
};

int main(){

    return 0;
}