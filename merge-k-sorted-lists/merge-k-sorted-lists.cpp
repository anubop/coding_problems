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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        if(lists.size() == 1) {
            return lists[0];
        }
        
        vector<ListNode*> newList;
        for(int i = 0; i < lists.size(); i+=2) {
            if(i + 1 >= lists.size()) {
                newList.push_back(lists[i]);
            }
            else {
                ListNode* pair = mergeTwoLists(lists[i], lists[i+1]);
                newList.push_back(pair);
            }
        }
        return mergeKLists(newList);
    }
    
private:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* head;
        ListNode* curr;
            
        
        //init head
        if(ptr1 != NULL && ptr2 != NULL) {
        //ptr 1 is less than or equal to ptr 2
            if(ptr1->val <= ptr2->val) {
                head = ptr1;
                ptr1 = ptr1->next;
            } else {
                head = ptr2;
                ptr2 = ptr2->next;
            }
        }
        else if(ptr1 == NULL) {
            
            return ptr2;
        }
        
        else if(ptr2 == NULL) {
            return ptr1;
        }
            
        curr = head;
        while(ptr1 != NULL || ptr2 != NULL) {
            //case 1 both lists are not empty
            if(ptr1 != NULL && ptr2 != NULL) {
                //ptr 1 is less than or equal to ptr 2
                if(ptr1->val <= ptr2->val) {
                    curr->next = ptr1;
                    ptr1 = ptr1->next;
                } else {
                    curr->next = ptr2;
                    ptr2 = ptr2->next;
                }
                curr = curr->next;
            }
            //case 2 list 1 is empty
            else if(ptr1 == NULL) {
                curr->next = ptr2;
                return head;
            }
            //case 3 list 2 is empty
            else if(ptr2 == NULL) {
                curr->next = ptr1;
                return head;
            }
        }
        return head;
    }

};