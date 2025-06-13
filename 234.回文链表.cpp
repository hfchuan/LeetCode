#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x,ListNode* next) : val(x),next(next){}
};


class Solution{
    public:
        bool isPalindrome(ListNode* head){
            if(head == nullptr || head->next == nullptr){
                return true;
            }
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast!=nullptr && fast->next !=nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* pre = nullptr;
            ListNode* cur = slow;
            while(cur!=nullptr){
                ListNode* temp = cur->next;
                cur->next = pre;
                pre=cur;
                cur=temp;
            }
            ListNode* first = head;
            ListNode* second = pre;
            while(second!=nullptr){
                if(first->val!=second->val){
                    return false;
                }
                first=first->next;
                second=second->next;
            }
            return true;
            

        }
};



int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    Solution sol;
    bool res = sol.isPalindrome(head);
    std::cout<<res<<std::endl;



    return 0;
}