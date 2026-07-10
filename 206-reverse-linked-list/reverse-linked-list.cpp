/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        if(head->next==nullptr){
            return head;
        }
        if(head->next->next==nullptr){
            ListNode* prev=head;ListNode* temp=head->next;
            temp->next=prev;
            prev->next=nullptr;
            return temp;
        }
        ListNode* prev=head;ListNode* temp=head->next;ListNode* front=temp->next;prev->next=nullptr;
        while(temp!=nullptr){
            temp->next=prev;
            prev=temp;
            temp=front;
            if(temp==nullptr){
                return prev;
            }
            front=front->next;
        }
        return prev;
        
    }
};