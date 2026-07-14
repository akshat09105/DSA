class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //no need of edge case as Node length is greater than equal to 1
        int carry=0;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* curr=dummyNode;ListNode* t1=l1;ListNode* t2=l2;
        while(t1!=nullptr || t2!=nullptr){
            int sum=carry;
            if(t1)sum+=t1->val;
            if(t2)sum+=t2->val;
            curr->next=new ListNode(sum%10);
            carry=sum/10;
            curr=curr->next;
            if(t1)t1=t1->next;
            if(t2)t2=t2->next;
        }
        if(carry){
            curr->next=new ListNode(1);
            curr=curr->next;
        }
        return dummyNode->next;
        
    }
};