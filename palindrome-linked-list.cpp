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

    ListNode* ReverseHalfLL(ListNode* head)
    {
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* newnode = ReverseHalfLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newnode;
    }

    bool isPalindrome(ListNode* head) {

        // Using Stack 
    //  ListNode* temp = head;
    //  int count=0;
    //  while(temp!=nullptr)
    //  {
    //     count++;
    //     temp = temp->next;
    //  } 
    //  stack<int>st; 
    //  temp = head;
    //  for (int i =0;i<count/2;i++)
    //  {
    //     st.push(temp->val);
    //     temp = temp->next;
    //  } 

    // if (count%2!=0) temp = temp->next;

    //  for (int i =0;i<count/2;i++)
    //  {
    //     if(temp->val != st.top()) return false;
    //     st.pop();
    //     temp = temp->next;
    //  }
    //  return true; 



        // Using Reverse Approach
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!=0 && fast->next!=0)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
       ListNode* tail = ReverseHalfLL(slow);
       while(head!=nullptr && tail!=nullptr)
       {
        if (head->val != tail->val) return false;
        head = head->next;
        tail = tail->next;
       }
       return true;
    }
};