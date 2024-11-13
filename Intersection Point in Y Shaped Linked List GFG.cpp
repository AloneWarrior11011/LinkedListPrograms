     // Linked List Example
     //       1                  8
     //         \               /
     //           2           11
     //            \         /
     //              3      3  
     //               \   /  
     //                5  
     //                 \
     //                  7
     //                   \
     //                    9
#include <iostream>

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

vector<int> take() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    return arr;
}

Node* inputList(int size, vector<int> v) {
    if (size == 0)
        return NULL;

    int val = v[0];

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++) {
        val = v[i + 1];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        // for(Node* t = head1; t != nullptr; t = t->next){
        //   for(Node* tt = head2; tt != nullptr; tt = tt->next){
        //       if(t == tt) return t->data;
        //   }
        // }
        // return -1;
        // unordered_set<Node*> set;
        // for(Node* t = head1; t != nullptr; t = t->next){
        //     set.insert(t);
        // }
        // for(Node* t = head2; t != nullptr; t = t->next){
        //     if(set.find(t) != set.end()) return t->data;
        // }
        // return -1;
        int cnt1 = 0, cnt2 = 0;
        for(Node* t = head1; t != nullptr; t = t->next) cnt1++;
        for(Node* t = head2; t != nullptr; t = t->next) cnt2++;
        
        if(cnt1 > cnt2){
            int diff = cnt1 - cnt2;
            while(diff-- > 0){
                head1 = head1->next;
            }
        }
        if(cnt2 > cnt1){
            int diff = cnt2 - cnt1;
            while(diff-- > 0){
                head2 = head2->next;
            }
        }
        while(head1 != head2){
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1->data;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main() {
    srand(time(0));
    int T, n1, n2, n3;

    cin >> T;
    cin.ignore();
    while (T--) {

        vector<int> v1 = take();
        vector<int> v2 = take();
        vector<int> v3 = take();
        int n1 = v1.size(), n2 = v2.size(), n3 = v3.size();

        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* common = NULL;

        head1 = inputList(n1, v1);
        head2 = inputList(n2, v2);
        common = inputList(n3, v3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
        cout << "~" << endl;
    }
    return 0;
}

