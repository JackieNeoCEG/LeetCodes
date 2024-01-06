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
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != NULL) {
            ListNode* nextNode = current->next;
            current->next = prev; //reverses the arrow direction in LinkedList
            prev = current; //moves prev pointer one step forward to the current node
            current = nextNode; //moves current pointer one step forward
        }

        return prev;
    }
};
