#include <iostream>
#include <vector>


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr){}
};

class Solution{
    public:
        ListNode* deleteDuplicates(ListNode* head){
            if(head == nullptr || head->next == nullptr){
                return head;
            }
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* pre = dummy;
            ListNode* cur = head;
            while(cur!=nullptr && cur->next!=nullptr){
                if(cur->val == cur->next->val){
                    int val = cur->val;
                    while(cur!=nullptr && cur->val == val){
                        cur = cur->next;
                        
                    }
                    pre->next = cur;

                }
                else{
                    pre = cur;
                    cur = cur->next;
                }
                
                

            }
            return dummy->next;


        }
};


int main(){

    return 0;
}