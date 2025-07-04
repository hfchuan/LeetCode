#include <iostream>
#include <vector>
#include <unordered_map>


class Node{
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val){
            val = _val;
            next = NULL;
            random = NULL;
        }
};


class Solution{
    public:
        std::unordered_map<Node* ,Node*> cacheNode;

        Node* copyRandomList(Node* head){
            if(head == NULL){
                return NULL;
            }

            if(!cacheNode.count(head)){
                Node* headNew = new Node(head->val);
                cacheNode[head] = headNew;
                headNew->next = copyRandomList(head->next);
                headNew->random = copyRandomList(head->random);

            }
            return cacheNode[head];
            


        }
};


int main(){



    return 0;
}