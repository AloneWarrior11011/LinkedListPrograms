/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
// Note that pos is not passed as a parameter.
// Do not modify the linked list.
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

class Solution {
public:
    bool flag = false;
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> ump;
        ListNode* loopNode = nullptr;
        checkLoopStart(head, ump, loopNode);
        if(flag){
          return loopNode;
        }else{
          return nullptr;
        }
    }
private :
    void checkLoopStart(ListNode* &head, unordered_map<ListNode*, int> &ump, ListNode* &node){
        ListNode* t = head;
        while(true && t != nullptr){
            if(ump.find(t) != ump.end()){
                node = t;
                flag = true;
                break;
            }
            ump[t] = 1;
            t = t->next;
        }
    }
};
