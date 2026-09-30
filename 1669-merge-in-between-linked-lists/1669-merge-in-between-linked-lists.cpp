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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* curr = list1;
        for (int i = 0; i < a - 1; i++) {
            curr = curr->next;
        }
        ListNode* start = curr;
        for (int i = 0; i < b - a + 1; i++) {
            curr = curr->next;
        }
        ListNode* end = curr->next;
        ListNode* tail2 = list2;
        while (tail2->next != nullptr) {
            tail2 = tail2->next;
        }
        start->next = list2;
        tail2->next = end;
        
        return list1;
    }
};