#include <iostream>
#include <vector>

class Solution{
    public:
        void gameOfLife(std::vector<std::vector<int>>&board){
            int m=board.size();
            int n=board[0].size();
            
            int dirs[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    int count=0;
                    for(auto dir:dirs){
                        int x=i+dir[0];
                        int y=j+dir[1];
                        if(x>=0&&x<m&&y>=0&&y<n){
                            if(board[x][y]==1 || board[x][y]==-1){
                                count++;
                            }
                            
                        }
                    }

                    if(board[i][j]==1){
                        if(count<2 || count>3){
                            board[i][j]=-1;
                        }
                       
                    }
                    else{
                        if(count==3){
                            board[i][j]=2;
                        }
                    }
                    

                }

            }

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]==-1){
                        board[i][j]=0;
                    }
                    else if(board[i][j]==2){
                        board[i][j]=1;
                    }
                }
            }


        }
};


int main(){


    return 0;
}