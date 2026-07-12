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
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr){
            if(n==1){
                delete(head);
                return nullptr;
            }
        }
        while(front!=nullptr){
            count++;
            if(count==n+1){
                break;
            }
            front=front->next;
        }
        if(front==nullptr){
            ListNode* temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        ListNode* slow=head;
        while(front->next!=nullptr){
            slow=slow->next;
            front=front->next;
        }
        ListNode* temp=slow->next;
        if(temp==nullptr){
            slow->next=temp;
            return head;        
        }
        slow->next=temp->next;
        temp->next=nullptr;
        delete(temp);
        return head;
    }
};