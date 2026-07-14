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
    ListNode* findNthNode(ListNode* head,int N){
        int count=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            count++;
            if(count==N){
                return temp;
            }
        temp=temp->next;
        }
    
        return nullptr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        //finding length of LL
        if(head==nullptr){
            return head;
        }
        int length=1;ListNode* temp=head;
        while(temp->next!=nullptr){
            length++;
            temp=temp->next;
        }
        if(k%length==0){
            return head;
        }
        k=k%length;
        temp->next=head;
        ListNode* newLastNode=findNthNode(head,length-k);
        head=newLastNode->next;
        newLastNode->next=nullptr;
        return head;
    }
};