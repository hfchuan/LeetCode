#include <iostream>


struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode* next) : val(x),next(next){}
};

class Solution{
    public:
        ListNode* partition(ListNode* head,int x){
            ListNode* dummy1 = new ListNode(0);
            ListNode* dummy2 = new ListNode(0);
            ListNode* p1=dummy1;
            ListNode* p2=dummy2;
            while(head){
                if(head->val<x){
                    p1->next=head;
                    p1=p1->next;

                }
                else{
                    p2->next=head;
                    p2=p2->next;
                }
                head=head->next;

            }
            p2->next=nullptr;
            p1->next=dummy2->next;
            return dummy1->next;
        }
};

int main(){


    return 0;
}