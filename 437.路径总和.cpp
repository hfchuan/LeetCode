#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(left),right(right){}
};

class Solution{
    public:
        int pathSum(TreeNode* root,int targetSum){
            std::unordered_map<int ,int>pathCount;
            pathCount[0] = 1;
            return dfs(root,targetSum,0,pathCount);


        }

    private:
        int dfs(TreeNode* node,int targetSum,int currentSum,std::unordered_map<int,int>&pathCount){
            if(node == nullptr){
                return 0;
            }
            currentSum += node->val;
            int count = pathCount[currentSum - targetSum];
            pathCount[currentSum]++;
            count += dfs(node->left,targetSum,currentSum,pathCount);
            count += dfs(node->right,targetSum,currentSum,pathCount);

            pathCount[currentSum]--;
            return count;

        }
};

int main(){

    return 0;
}