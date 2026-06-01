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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = head;
        ListNode* prev = dummy;
        dummy->next = head;
        int data;
        while (temp != NULL && temp->next != NULL) {
            int data = prev->val;
            if (temp->val != temp->next->val) {
                prev = temp;
                temp = temp->next;
            } else {

                data = temp->val;

                prev->next = temp->next->next;
                temp = temp->next->next;

                while (temp && data == temp->val) {
                    prev->next = temp->next;
                    temp = temp->next;
                }
            }
        }
        return dummy->next;
    }
};