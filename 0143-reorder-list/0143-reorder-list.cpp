class Solution {
public:
    void reorderList(ListNode* head) 
    {
       
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) 
        {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* current = slow->next; 
        slow->next = nullptr;           
        ListNode* next_node = nullptr;
        
        while (current != nullptr) 
        {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        
        ListNode* first_half = head;
        ListNode* second_half = prev; 
        
        while (second_half != nullptr) 
        {
          
            ListNode* temp1 = first_half->next;
            ListNode* temp2 = second_half->next;
            
           
            first_half->next = second_half;
            
            second_half->next = temp1;
            
           
            first_half = temp1;
            second_half = temp2;
        }
    }
};