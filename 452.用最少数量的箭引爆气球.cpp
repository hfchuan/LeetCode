#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        int findMinArrowShots(std::vector<std::vector<int>>& points){
            if(points.empty()){
                return 0;
            }
            std::sort(points.begin(),points.end(),[](const std::vector<int>& a,const std::vector<int>& b){
                return a[1]<b[1] || (a[1] == b[1] && a[0]<b[0]);
            });

            int arrows=1;
            int arrowPosition = points[0][1];
            for(int i=1;i<points.size();i++){
                if(points[i][0]>arrowPosition){
                    arrows++;
                    arrowPosition = points[i][1];
                }
            }
            return arrows;



        }
};



int main(){

    return 0;
}