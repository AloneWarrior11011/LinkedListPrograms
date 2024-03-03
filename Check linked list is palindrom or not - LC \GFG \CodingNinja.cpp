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
    ListNode* getMiddle(ListNode* &head)
    {
        ListNode* slow = head;
        ListNode* fast = slow->next;

        while(fast != NULL && fast->next != NULL)
        {
             slow = slow->next;
             fast = fast->next->next;
        }
        return slow;     // this will at the middle of the linked list
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;

        while(curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
bool isPalindrom(ListNode* head)
{
if(head == NULL || head->next == NULL) return false;

       // step 1 : find the middle node of the list.
       ListNode* middle = getMiddle(head);


       // step 2 : reverse nodes from (list) the mid of the list.
       ListNode* temp = middle->next;
       // assuming 1->2->2->1 then mid of the list would be 2 at position 2nd 
       // we made reversal to the next node of mid then reverse of mid->next would be like
       // then list->   1-2-1-2
       middle->next = reverseList(temp);      // 1-2

       // get traverse from head from the middle next of the linked list.
       ListNode* head1 = head;
       ListNode* head2 = middle->next; // for making traversal from the mid->next wala nodes.

    // step 3 : Comparing two halves (data part of left and right halves) is it equal or not.
       while(head2 != NULL)
       {
           
           if(head2->val != head1->val) return false;

           //  if it's equal then no issue move ahead pointer and do checking.
           head1 = head1->next;
           head2 = head2->next;
       }
       return true;
       
    }
};
