#include <iostream>

class ListNode {
public:
  int val = 0;
  ListNode *next;

  ListNode(int value) {
    this->val = value;
    next = nullptr;
  }
};
/*
    Problem Statement
    Given the head of a Singly LinkedList, write a function to determine if the LinkedList has a cycle in it or not.

    Constraints:

    The number of the nodes in the list is in the range [0, 104].
    105 <= Node.val <= 105
*/

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast=head;

    while(fast&&fast->next)
    {
        
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            return true;
        }
    }

    return false;
}

ListNode* FindMiddle(ListNode* head)
{
    ListNode* fast=head;
    ListNode* slow=head;


    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
} 
int main()
{
    return 1;
}