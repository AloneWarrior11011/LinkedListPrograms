/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCloneNode(Node* &head,Node* &tail,int data)
    {
        //create a new node
        Node* newNode = new Node(data);
        if(head == NULL)
        {
            head = tail = newNode;  // both keep same in this case
            return; // hey bro come back.
        }  
        else
        {
            tail->next = newNode;
            tail = tail->next;   // or tail = newNode
        }
    }
    Node* copyRandomList(Node* head) {
      // step 1 : crate a clone linked list
      Node* cloneHead = NULL;
      Node* cloneTail = NULL;

      Node* temp = head;
      while(temp != NULL)
      {
        insertCloneNode(cloneHead,cloneTail,temp->val);
        temp = temp->next;
      }

      // step 2 : mapping of original list and clone list so that we can copy random pointer also
      /*
           For keeping the track of random pointer,,,,where does random pointer exactly point to the original linked list.
           we gonna take the map stl so that we could keep track of random pointer in an original list and on that 
           basis we can esily make clone of this random pointer in the clone list.
      */
      // map gonna keep track of original as well as clone linked list's node 
       unordered_map<Node*,Node*> oldToNew;

       Node* originalNode = head;      // head of the original linked list.
       Node* cloneNode = cloneHead;    // head of the cloned linked list.

      //----------------------Mapping----------------------//
       while(originalNode != NULL && cloneNode != NULL)
       {
           oldToNew[originalNode] = cloneNode;
           originalNode = originalNode->next;     // move ahead.
           cloneNode = cloneNode->next;
       }
       // Let's gonna copy random pointer of original list into cloned list.
       originalNode = head;
       cloneNode = cloneHead;
       while(originalNode != NULL)
       {
           cloneNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next;
           cloneNode = cloneNode->next;
       }
       return cloneHead;
    }
};
