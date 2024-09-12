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
// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.
// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]
// Example 2:

class Solution {
public:
    void createList(ListNode* &h, ListNode* &t, int data){
        ListNode* newnode = new ListNode(data);
        if(h == nullptr){
            h = newnode;
            t = newnode;
        }else{
            t->next = newnode;
            t = newnode;
        }
    }
    ListNode* oddEvenList(ListNode* head) {
        // better brute force 
        if(!head) return nullptr;
        ListNode* odd = head;
        int cnt = 1;
        ListNode *h , *t;
        h = t = nullptr;
        
        while(odd != nullptr){
            if((cnt & 1) == 1){
                createList(h, t, odd->val);
            }
            cnt++;
            odd = odd->next;
        }
        ListNode* even = head;
        cnt = 1;
        while(even != nullptr){
           if((cnt & 1) == 0){
             createList(h,t, even->val);
           }
           cnt++; 
           even = even->next;
        }
        return h;
    }
};
