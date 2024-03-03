class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    // Write your code here.
    if(head == NULL) return NULL;

    int zeroCnt = 0, oneCnt = 0, twoCnt = 0;

    Node* temp = head;

     // counting the number of 0's,1's,2's
    while(temp != NULL)
    {
        if(temp->data == 0) zeroCnt++;

        else if(temp->data == 1) oneCnt++;

        else if(temp->data == 2) twoCnt++;

        temp = temp->next;
    }

    // again set it out temp to head and replace the data
    temp = head;
    while(temp != NULL)
    {
        if(zeroCnt != 0) 
        {
            temp->data = 0;
            zeroCnt--;
        }
        else if(oneCnt != 0) 
        {
            temp->data = 1;
            oneCnt--;
        }
        else if(twoCnt != 0) 
        {
            temp->data = 2;
            twoCnt--;
        }
        
         temp = temp->next;
    }
    return head;
}
// ========================= 2nd Approach ==================
/*
Following is the class structure of the Node class:

//---------------------by creating dummy nodes of 0,1,2's and merge them -------------------------

void insertAtTail(Node* &tail,Node* curr)
{
    tail->next = curr;
    tail = curr;
}
Node* sortList(Node *head){
    // creating a dummy nodes of 0's,1's,2's
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    // this is for creating 0,1,2's wali nodes
    while(curr != NULL)
    {
        int val = curr->data;

        if(val == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if(val == 1)
        {
            insertAtTail(oneTail,curr);
        }
        else if(val == 2)
        {
            insertAtTail(twoTail,curr);
        }
        curr = curr->next;
    }

    // step 2 : merging of the 0,1,2's wali list together
    // if 1's list is not empty
    if(oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    // 1's list is empty
    else
    {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;  // list ka end ko NULL krna pdega bro

    // head ko 0's ke head ke dummy ka next rkhna pdega
    head = zeroHead->next;

    // delete the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}
