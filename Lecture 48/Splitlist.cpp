#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void InsertAtHead(int d,Node* &head){
    if(head==NULL){
        Node* temp = new Node(d);
        head=temp;
        return;
    }
    Node*temp = new Node(d);
    temp->next = head;
    head = temp;
}
void print(Node* &head){       //For printing singly linked list
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int getLength(Node* head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void print2(Node* &head){     //For printing the circular linked list
    Node* temp=head;
    cout<<temp->data<<" ";
    temp=temp->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* splitList(Node* head){
    int length = getLength(head);
    int position;
    if(length%2==0){
        position=length/2;
    }
    else{
        position=(length/2)+1;
    }
    Node* temp=head;
    for(int i=1;i<position;i++){    //Takes temp to position
        temp=temp->next;
    }
    Node* sub_head=temp->next;
    temp->next=head;
    Node* temp2=sub_head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=sub_head;
    return sub_head;
}
int main(){
    cout<<"First"<<endl;
    Node* head1 = new Node(80);
    InsertAtHead(70,head1);
    InsertAtHead(60,head1);
    InsertAtHead(50,head1);
    InsertAtHead(40,head1);
    InsertAtHead(30,head1);
    InsertAtHead(20,head1);
    InsertAtHead(10,head1);
    print(head1);
    Node* head1B = splitList(head1);
    Node* head1A = head1;
    print2(head1A);
    print2(head1B);
    cout<<"Second"<<endl;
    Node* head2 = new Node(7);
    InsertAtHead(6,head2);
    InsertAtHead(5,head2);
    InsertAtHead(4,head2);
    InsertAtHead(3,head2);
    InsertAtHead(2,head2);
    InsertAtHead(1,head2);
    print(head2);
    Node* head2B = splitList(head2);
    Node* head2A = head2;
    print2(head2A);
    print2(head2B);
}