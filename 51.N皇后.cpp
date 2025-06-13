#include <iostream>
#include <vector>

class Solution{
    public:
        std::vector<std::vector<std::string>> solveNQueens(int n){
            std::vector<std::vector<std::string>> res;
            std::vector<std::string> board(n, std::string(n,'.'));
            std::vector<bool> col(n,false), diag1(2*n-1,false), diag2(2*n-1,false);
            dfs(res,board,col,diag1,diag2,0);
            
            return res;
        }
    
    private:
        void dfs(std::vector<std::vector<std::string>>& result,std::vector<std::string>& board,std::vector<bool>& col,std::vector<bool>& diag1,std::vector<bool>& diag2,int row ){
            if(row == board.size()){
                result.push_back(board);
                return;
            }

            for(int i=0;i<board.size();i++){
                if(col[i] || diag1[row+i] || diag2[row-i+board.size()-1]){
                    continue;
                }
                board[row][i] = 'Q';
                col[i] = diag1[row+i] = diag2[row-i+board.size()-1] = true;
                dfs(result,board,col,diag1,diag2,row+1);
                board[row][i] = '.';
                col[i] = diag1[row+i] = diag2[row-i+board.size()-1] = false;
            }
            
        }
};

int main(){


    return 0;
}