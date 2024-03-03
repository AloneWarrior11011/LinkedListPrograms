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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // finding the count of nodes in a list
        // set cnt 1 cuz we already at the node 1 in the list.
        int cnt = 1;
        ListNode* temp = head;
        while(temp != NULL)
        {
          cnt++;
          temp = temp->next;
        }
        // assume length of list = 5 then newCnt = 5 - n(2) = 3 
        int newCnt = cnt - n;

        ListNode* prev = head;
        ListNode* curr = head;
        
        if(n == 1 && head->next == NULL)
        {
            return NULL;
        }
        // this for case 3 : 
        // head = [1,2] and n = 1 so in that case 
         if(newCnt == 1)
         {
            head = curr->next;
            return head;
         }
        int counter = 1;
        while(curr != NULL && counter != newCnt)
        {
           counter++;
           prev = curr;
           curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;

        return head;
        
    }
};
