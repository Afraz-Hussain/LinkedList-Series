// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    
    Node(int data){
      this->data=data;
      this->next=NULL;
    }
};
void insertAtHead(Node*&head ,int d ){
    // create new node
    Node* temp=new Node(d);
    // point node next to node head
    temp->next=head;
    // make head first 
    head=temp;
}
void print( Node *&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insertback(Node*&tail,int d){

    Node*temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertAtAnyPosition(Node*& tail, Node*& head, int position, int d) {

    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // insert at tail
    if (temp->next == NULL) {
        insertback(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
void deleteNode(int pos,Node*&head){
    if(pos==1){
        cout<<"1 node deletion"<<endl;
        Node*temp=head;
        head=head->next;
        delete temp;
    }
    else{
        Node*prev=NULL;
        Node*curr=head;

        int cnt=1;
        while(cnt<pos){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        delete curr;

    }
}
int main() {
 Node*node1= new Node(10);
 Node* head = node1;
 Node* tail=node1;
insertback(tail, 20);
insertback(tail, 30);

 insertAtAnyPosition(tail,head,4,22);
print(head);
cout<<"\nhead->"<<head->data<<" "<<endl;
cout<<"tail->"<<tail->data<<" "<<endl;
deleteNode(1,head);
print(head);
cout<<"\nhead->"<<head->data<<" "<<endl;
cout<<"tail->"<<tail->data<<" "<<endl;
    return 0;
}
