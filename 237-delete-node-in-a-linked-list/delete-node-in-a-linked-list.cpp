/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node==nullptr){
            return;
        }
        ListNode* temp=node;ListNode* prev=nullptr;
        while(temp->next!=nullptr){
            temp->val=temp->next->val;
            prev=temp;
            temp=temp->next;
        }
        prev->next=nullptr;
        delete(temp);
        
        
    }
};