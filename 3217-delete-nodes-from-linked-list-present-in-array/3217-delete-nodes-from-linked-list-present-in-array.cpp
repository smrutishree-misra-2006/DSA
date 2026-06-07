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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> hash;

        for (int x : nums) {
            hash.insert(x);
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* temp = head;

        while (temp != NULL) {
            if (hash.find(temp->val) != hash.end()) {
                ListNode* del = temp;
                temp = temp->next;

                prev->next = temp;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};