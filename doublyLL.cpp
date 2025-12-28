#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

// Print list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Get length
void getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    cout << "Length of list is " << len << endl;
}

// Insert at head
void insertAtHead(Node*& head, Node*& tail, int d) {

    Node* temp = new Node(d);

    // Empty list
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
}

// Insert at tail
void insertAtTail(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    // Empty list
    if (tail == NULL) {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// Insert at any position (1-based)
void insertAtPosition(Node*& head, Node*& tail, int pos, int d) {

    // Insert at head
    if (pos == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* curr = head;
    int count = 1;

    while (count < pos - 1 && curr != NULL) {
        curr = curr->next;
        count++;
    }

    // Position out of range
    if (curr == NULL) {
        cout << "Position out of range\n";
        return;
    }

    // Insert at tail
    if (curr->next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }

    // Insert in middle
    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
}


void DeleteNode(Node*head,int pos){
   if(pos==1){
      Node*temp=head;
      temp->next->prev=NULL;
      head=temp->next;
      temp->next=NULL;
   }
   else{
// for last 

Node*curr=head;
Node*prev=NULL;
int cnt=1;
while(cnt<pos){
   prev=curr;
   curr=curr->next;
   cnt++;
}
curr->prev=NULL;
prev->next=curr->next;
curr->next=NULL;
delete curr;

   }
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);

    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
  print(head);
    insertAtPosition(head, tail, 3, 25);
      print(head);
DeleteNode(head,3);
    print(head);
    getLength(head);

    return 0;
}
