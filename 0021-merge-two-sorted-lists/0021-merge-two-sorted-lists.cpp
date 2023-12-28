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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Handle the case where one of the lists is empty
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* result = nullptr;  // Resultant merged list
        ListNode* current = nullptr;

        // Merge nodes from list1 and list2 until one of them is exhausted
        while (list1 && list2) {
            // Determine the smaller node between list1 and list2
            ListNode*& smaller = (list1->val < list2->val) ? list1 : list2;

            // If result is empty, set it to the smaller node and update current
            if (!result) {
                result = smaller;
                current = smaller;
            } else {
                // Append the smaller node to the merged list and move current
                current->next = smaller;
                current = smaller;
            }

            // Move the pointer of the smaller node to the next node
            smaller = smaller->next;
        }

        // Handle the case where one of the lists is not fully traversed
        ListNode* remaining = (list1) ? list1 : list2;

        // Append the remaining nodes to the merged list
        while (remaining) {
            if (!result) {
                result = remaining;
                current = remaining;
            } else {
                current->next = remaining;
                current = remaining;
            }
            remaining = remaining->next;
        }

        return result;  // Return the head of the merged list
    }
};