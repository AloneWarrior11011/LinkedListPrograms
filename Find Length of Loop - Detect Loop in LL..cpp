// Input: LinkedList: 25->14->19->33->10->21->39->90->58->45, c = 4
// Output: 7
// Explanation: The loop is from 33 to 45. So length of loop is 33->10->21->39-> 90->58->45 = 7. 
// The number 33 is connected to the last node of the linkedlist to form the loop because according to the input the 4th node from the beginning(1 based indexing) 
// will be connected to the last node for the loop.
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    Node* meeting = nullptr;
    bool doesLoopPresent(Node* head){
        Node* slow = head, *fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr){
                fast = fast->next;
            }
            if(slow == fast){
                meeting = slow;
                return true;
            }
        }
        return false;
    }
    int loopLen(Node* meet){
        Node* curr = meet;
        int cnt = 0;
        while(1){
            curr = curr->next;
            cnt += 1;
            if(curr == meet) break;
        }
        return cnt;
    }
    int countNodesinLoop(struct Node *head) {
        // Code here
        if(!head) return 0;
        
        if(doesLoopPresent(head)){
            return loopLen(meeting);
        }else{
            return 0;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        cout << ob.countNodesinLoop(head) << endl;
    }
    return 0;
}

