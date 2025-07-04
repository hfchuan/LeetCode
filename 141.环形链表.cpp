#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode () : val(0),next(nullptr){}
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x,ListNode*next) :val(x),next(next){}


};

class Solution{
    public:
        bool hasCycle(ListNode* head){
            if(head==nullptr || head->next==nullptr){
                return false;
            }
            ListNode* slow=head;
            ListNode* fast=head->next;
            while(slow!=fast){
                if(fast==nullptr || fast->next==nullptr){
                    return false;
                }
                slow=slow->next;
                fast=fast->next->next;

            }
            return true;
        }
};



int main(){


    return 0;
}