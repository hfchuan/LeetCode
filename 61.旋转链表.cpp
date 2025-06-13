#include <iostream>
#include <vector>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x,ListNode* next): val(x),next(next){}
    
};


class Solution{
    public:
        ListNode* rotateRight(ListNode* head,int k){
            if(head==nullptr || head->next==nullptr || k==0){
                return head;
            }
            int len=1;
            ListNode* p=head;
            while(p->next){
                len++;
                p=p->next;

            }
            p->next=head;
            k=k%len;
            if(k==0){
                p->next=nullptr;
                return head;
            }
            
            ListNode* cur=head;
            int count=len-k-1;
            while(count>0){
                cur=cur->next;
                count--;
            }
            ListNode* newhead=cur->next;
            cur->next=nullptr;
            
            return newhead;
           
        
        }
};




int main(){


    return 0;
}