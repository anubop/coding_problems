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
        if(head == NULL) {
            return NULL;
        }
        stack<ListNode*> myStack;
        
        ListNode *ptr = head;
        while(ptr->next != NULL) {
            myStack.push(ptr);
            ptr = ptr->next;
        }
        //ptr now points to last element of original list
        ListNode* newHead = ptr;
        while(!myStack.empty()) {
            ptr->next = myStack.top();
            ptr = ptr->next;
            myStack.pop();
        }
        ptr->next = NULL;
        return newHead;
    }
};