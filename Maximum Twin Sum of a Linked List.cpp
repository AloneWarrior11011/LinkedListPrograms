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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr, *curr = head, *nxt = nullptr;

        while(curr != nullptr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    void createList(ListNode* &h, ListNode* &t, int x){
        ListNode* newnode = new ListNode(x);
        if(h == nullptr){
            h = newnode;
            t = newnode;
        }else{
            t->next = newnode;
            t = newnode;
        }
    }
    int pairSum(ListNode* head) {
        if(!head) return 0;
    
        ListNode* t = head;
        int n = 0;
        while(t != nullptr){
            n++;
            t = t->next;
        }
        int cnt = 0;
        t = head;

        ListNode* hh = nullptr, *tt = nullptr;
        ListNode* h = nullptr, *tail = nullptr;
        while(t != nullptr){
            if(cnt >= (n/2)){
                createList(h, tail, t->val);
            }
            createList(hh, tt, t->val);
            cnt++;
            t = t->next;
        }
        ListNode* rev = reverse(h);
        ListNode* a = rev, *b = hh;

        int maxi = INT_MIN;
        for(; a != nullptr && b != nullptr; a = a->next , b = b->next){
            maxi = max(maxi, a->val + b->val);
        }
        return maxi;
    }
};
