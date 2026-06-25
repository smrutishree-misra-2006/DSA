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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy ->next = head;
        unordered_map<int,ListNode*> mp;
        int prefix = 0;
        for(ListNode* curr = dummy;curr;curr = curr -> next){
           prefix += curr -> val;
           mp[prefix] = curr;
        }
        prefix = 0;
        for(ListNode* curr = dummy;curr;curr = curr -> next){
           prefix += curr -> val;
           curr -> next = mp[prefix] -> next;
        }

        
        return dummy -> next;
    }
};