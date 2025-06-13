#include <iostream>
#include <vector>
#include <string>



class Solution{
    public:
        bool exist(std::vector<std::vector<char>>& board,std::string word){
            if(board.empty() || word.empty()){
                return false;
            }
            int m=board.size();
            int n=board[0].size();
            std::vector<std::vector<bool>> visited(m,std::vector<bool>(n,false));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(dfs(board,word,0,i,j,visited)){
                        return true;
                    }
                }
            }
            return false;
        }

    private:
        bool dfs(std::vector<std::vector<char>>& board,std::string word,int index,int i,int j,std::vector<std::vector<bool>>& visited){
            if(index == word.size()){
                return true;
            }
            if(i<0 || i>=board.size() || j>0 || j>=board[0].size() || visited[i][j] || board[i][j] != word[index]){
                return false;
            }
            visited[i][j]=true;
            if(dfs(board,word,index+1,i+1,j,visited) || dfs(board,word,index+1,i-1,j,visited) || dfs(board,word,index+1,i,j+1,visited) || dfs(board,word,index+1,i,j-1,visited)){
                return true;
            }
            visited[i][j]=false;
            return false;
        }
};

int main(){



    return 0;
}