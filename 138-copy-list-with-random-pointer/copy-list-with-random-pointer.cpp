/*
 // Definition for a Node.
 class Node {
 public:
     int val;
     Node* next;
     Node* random;

     Node(int _val) {
         val = _val;
         next = NULL;
         random = NULL;
     }
 };
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Insert copy nodes in between original nodes
        Node* temp = head;
        while (temp != nullptr) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        // Step 2: Connect random pointers of copy nodes
        temp = head;
        while (temp != nullptr) {
            if (temp->random != nullptr)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // Step 3: Separate original and copied linked list
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;
        temp = head;

        while (temp != nullptr) {
            copyTail->next = temp->next;
            temp->next = temp->next->next;

            temp = temp->next;
            copyTail = copyTail->next;
        }

        return dummy->next;
    }
};