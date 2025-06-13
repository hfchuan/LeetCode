#include <iostream>
#include <vector>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x,ListNode* next) : val(x),next(next){}
};

class Solution{
    public:
        ListNode* reverseList(ListNode* head){
            if(head == nullptr || head->next == nullptr){
                return head;
            }
            ListNode* pre=nullptr;
            ListNode* cur=head;
            while(cur!=nullptr){
                ListNode* temp = cur->next;
                cur->next = pre;
                pre =cur;
                cur = temp;
            }
            return pre;
        }
};

void printList(ListNode* head){
    ListNode* cur = head;
    while(cur!=nullptr){
        std::cout<<cur->val<<" ";
        cur= cur->next;
    }
    std::cout<<std::endl;
}

int main(){
    ListNode* head =new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    std::cout<<"原链表：";
    printList(head);
    Solution sol;
    ListNode* newhead = sol.reverseList(head);
    std::cout<<"反转后链表：";
    printList(newhead);




    return 0;
}