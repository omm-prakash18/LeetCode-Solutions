class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
        ListNode* head = nullptr; 
        ListNode* ptr = nullptr;
        
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        while (list1 != nullptr && list2 != nullptr) {
            if (head == nullptr) {
                
                if (list1->val < list2->val) {
                    ptr = head = list1;
                    
                    list1 = list1->next; 
                } else {
                    ptr = head = list2;
                    list2 = list2->next;
                }
                continue;
            }
            
            if (list1->val < list2->val) {
                ptr->next = list1;
                ptr = list1;
                
                list1 = list1->next; 
            } else {
                ptr->next = list2;
                ptr = list2;
                
                list2 = list2->next; 
            }
        }
        
        if (list1 != nullptr) {
            ptr->next = list1;
        } else {
            ptr->next = list2;
        }
        
        return head;
    }
};