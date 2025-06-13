#include <iostream>
#include <vector>
#include <unordered_set>


class Solution{
    public:
        bool isValidSudoku(std::vector<std::vector<char>>& board){
            std::unordered_set<char> rows[9],cols[9],boxs[9];
          
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(board[i][j]!='.' && !rows[i].insert(board[i][j]).second){
                        return false;
                    }
                    if(board[i][j]!='.' && !cols[j].insert(board[i][j]).second){
                        return false;
                    }
                    int box_idx=i/3*3+j/3;
                    if(board[i][j]!='.' && !boxs[box_idx].insert(board[i][j]).second){
                        return false;
                    }

                
                }
                
            
            }
            return true;
        }
};



int main(){


    return 0;
}