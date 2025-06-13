#include <iostream>
#include <vector>
#include <queue>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x),next(nullptr) {}
    ListNode(int x, ListNode* next): val(x),next(next) {}
};

class Solution{
    public:
        std::pair<ListNode*,ListNode*>myReverse(ListNode* head,ListNode* tail){
            ListNode* pre = tail->next;
            ListNode* p = head;
            while(pre != tail){
                ListNode * next = p->next;
                p->next = pre;
                pre = p;
                p = next;
            }
            return {tail,head};

        }
        ListNode* reverseKGroup(ListNode* head, int k){
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode *pre = dummy;
            while(head){
                ListNode *tail = pre;
                for(int i=0;i<k;i++){
                    tail = tail->next;
                    if(!tail){
                        return dummy->next;
                    }
                }
                ListNode *next = tail->next;
                std::pair<ListNode*,ListNode*>result = myReverse(head,tail);
                head = result.first;
                tail = result.second;
                pre->next = head;
                tail->next = next;
                pre = tail;
                head = tail->next;
            }

            return dummy->next;
            
            
        }
};

int main(){

    return 0;
}