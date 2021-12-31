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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> setNodes;
        
        ListNode *curr = head;
        while(curr != NULL) {
            std::pair<std::unordered_set<ListNode*>::iterator, bool > result = setNodes.insert(curr);
            if(result.second == false) {
                return true;
            }
            curr = curr->next;
            
        }
        return false;
    }
};