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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummynode = new ListNode(-1);
        dummynode->next = head;

        ListNode* prev = dummynode;
        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {
            ListNode* alt = temp->next;

            temp->next = alt->next;
            alt->next = temp;
            prev->next = alt;

            prev = temp;
            temp = temp->next;
        }

        return dummynode->next;
    }
};