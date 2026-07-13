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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front=head;int count=0;
        for(int i=0;i<n;i++){
            front=front->next;
        }
        if(front==nullptr){
            ListNode* newHead=head->next;
            delete(head);
            return newHead;
        }
        ListNode* slow=head;
        while(front->next!=nullptr){
            slow=slow->next;
            front=front->next;
        }
        ListNode* deleteNode=slow->next;
        slow->next=deleteNode->next;
        delete(deleteNode);
        return head;
    }
};