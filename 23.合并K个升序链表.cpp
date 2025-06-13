#include <iostream>
#include <vector>
#include <queue>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x,ListNode* next): val(x),next(next){}
};

class Solution{
    public:
        ListNode* mergeKLists(std::vector<ListNode*>& lists){
            auto cmp = [](ListNode* l1,ListNode* l2){
                return l1->val > l2->val;
            };
            std::priority_queue<ListNode*,std::vector<ListNode*>,decltype(cmp)> minHeap(cmp);
            for(ListNode* list : lists){
                if(list){
                    minHeap.push(list);
                }
            }
            ListNode* dummy = new ListNode(0);
            ListNode* current = dummy;
            while(!minHeap.empty()){
                ListNode* minNode = minHeap.top();
                minHeap.pop();
                current->next = minNode;
                current = current->next;
                if(minNode->next){
                    minHeap.push(minNode->next);
                }

            }
            return dummy->next;
        }
};

int main(){


    return 0;
}