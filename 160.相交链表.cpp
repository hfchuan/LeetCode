#include <iostream>


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(NULL) {}
};


class Solution{
    public:
        ListNode *getIntersectionNode(ListNode *headA,ListNode *headB){

            if(!headA || !headB){
                return nullptr;
            }
            ListNode *pA = headA, *pB = headB;
            ListNode *res;
            int skipA = 0,skipB = 0;
            while(pA){
                skipA++;
                pA = pA->next;
            }

            while(pB){
                skipB++;
                pB = pB->next;
            }
            pA = headA;
            pB = headB;
            if(skipA > skipB){
                for(int i = 0;i<skipA - skipB;i++){
                    pA = pA->next;
                }
            }
            else{
                for(int i =0;i<skipB - skipA;i++){
                    pB = pB->next;
                }
            }

            while(pA && pB){
                if(pA == pB){
                    return pA;
                }
                pA = pA->next;
                pB = pB->next;
            }
            return nullptr;
            


        }
};



int main(){
    Solution sol;
    




    return 0;
}