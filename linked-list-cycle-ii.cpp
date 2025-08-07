/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* second = head;
      if (head == nullptr || head->next == nullptr) return nullptr;
      while (second != nullptr && second->next != nullptr)
      {
        first = first->next;
        second = second->next->next;
        if (first == second) 
        {
             ListNode* temp = head;
            while(temp!=first)
            {
                temp=temp->next;
                first = first->next;
            }
            return temp;
           
        
        }

      }  
      return nullptr;
    }
};