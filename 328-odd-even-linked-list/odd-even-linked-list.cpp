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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        //solving it by 2 pointer approach(trailing pointer technique)
        ListNode* curr=head;ListNode* evenNode=head->next;int count=1;ListNode* store=head;
        while(curr!=nullptr && curr->next!=nullptr){
            if(count%2!=0 && curr->next->next!=nullptr){
                store=curr->next->next;
            }
            ListNode* forward=curr->next;
            curr->next=curr->next->next;
            curr=forward;
            count++;
        }
        store->next=evenNode;
        return head;

    }
};