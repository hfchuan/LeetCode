#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}

};

class Solution{
    public:
        ListNode* reverseBetween(ListNode* head,int left,int right){
            if(head==nullptr || left==right){
                return head;
            }
            ListNode* dummy=new ListNode(0);
            dummy->next=head;
            ListNode* pre=dummy;
            for(int i=0;i<left-1;i++){
                pre=pre->next;
            }
            ListNode* cur = pre->next;
            ListNode* next=nullptr;
            for(int i=0;i<right-left;i++){
                next=cur->next;
                cur->next=next->next;
                next->next=pre->next;
                pre->next=next;
            }
            return dummy->next;

        }
};



int main(){


    return 0;
}