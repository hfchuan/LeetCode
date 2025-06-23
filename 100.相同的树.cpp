#include <iostream>
#include <vector>
#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
    public:
        bool isSameTree(TreeNode* p,TreeNode* q){
            if(p==NULL && q==NULL){
                return true;
            }
            if(p==NULL || q==NULL){
                return false;
            }
            if(p->val!=q->val){
                return false;
            }
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }

        bool isSameTree2(TreeNode* p,TreeNode* q){
            if(p==NULL && q==NULL){
                return true;
            }
            if(p==NULL || q==NULL){
                return false;
            }
            std::queue<TreeNode*> q1,q2;
            q1.push(p);
            q2.push(q);
            while(!q1.empty() && !q2.empty()){
                TreeNode* p1=q1.front();
                q1.pop();
                TreeNode* p2=q2.front();
                q2.pop();
                if(p1==NULL && p2==NULL){
                    continue;
                }
                if(p1==NULL || p2==NULL){
                    return false;
                }
                if(p1->val!=p2->val){
                    return false;

                }
                q1.push(p1->left);
                q1.push(p1->right);
                q2.push(p2->left);
                q2.push(p2->right);
            }
            return true;
        
            

        }
};



int main(){


    return 0;
}