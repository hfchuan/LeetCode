#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x),next(nullptr) {}
    ListNode(int x,ListNode* next) : val(x),next(next) {}

};

class Solution {
    public:
        ListNode* swapPairs(ListNode* head){
            if(head==nullptr || head->next==nullptr){
                return head;
            }
            ListNode* dummy=new ListNode(0);
            dummy->next=head;
            ListNode* pre=dummy;
            ListNode* cur=head;
            while(cur!=nullptr && cur->next!=nullptr){
                ListNode* temp = cur->next;
                cur->next=temp->next;
                temp->next=cur;
                pre->next=temp;
                pre=cur;
                cur=cur->next;
            }
            return dummy->next;
            delete dummy;
        }
};


int main(){


    return 0;
}