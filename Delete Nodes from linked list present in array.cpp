// You are given an array of integers nums and the head of a linked list. Return the head of the 
// modified linked list after removing all nodes from the linked list that have a value that exists in nums.


// Example 1:

// Input: nums = [1,2,3], head = [1,2,3,4,5]

// Output: [4,5]

// Explanation:

// Remove the nodes with values 1, 2, and 3.

// Example 2:

// Input: nums = [1], head = [1,2,1,2,1,2]

// Output: [2,2,2]

// Explanation:

// Remove the nodes with value 1.

// Example 3:

// Input: nums = [5], head = [1,2,3,4]

// Output: [1,2,3,4]

// Explanation:

// No node has value 5.

 
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> set;
        for(int num : nums){
            set.insert(num);
        }
        ListNode *newhead = nullptr, *tail = nullptr;
        ListNode * t = head;

        while(t != nullptr){
            if(set.find(t->val) == set.end()){
                createList(newhead, tail, t->val);
            }
            t = t->next;
        }
        return newhead;
    }
    private : 
    void createList(ListNode*& head, ListNode*& tail, int data){
        ListNode* newnode = new ListNode(data);
        if(head == nullptr){
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            tail = tail->next;
        }
    }
};
