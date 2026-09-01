class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if (fast == nullptr) {
            ListNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete; 
            return head;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; 
        
        return head;
    }
};