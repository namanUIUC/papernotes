#include <iostream>
using namespace std;

// Doubly Linked List

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* getNewNode(int x){
    Node* new_node = new Node;
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
void push(int x, Node** head_ref){
    Node* newNode = getNewNode(x);
    if (*head_ref == NULL){
        *head_ref = newNode;
        return;
    }
    (*head_ref)->prev = newNode;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<"->"<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    Node* head = NULL;
    int count,x;
    cout<<"Enter number of elements you want to enter:"<<endl;
    cin>>count;
    for(int i=0; i<count; i++){
        cout<<"Insert Number:"<<endl;
        cin>>x;
        // push(x, &head);
        push(x, &head);
        cout<<"Linked List"<<endl;
        print(head);
    }
    // reverse(&head);
    // print(head);
    // rprint(head);
    // reverse_rec(&head);
    print(head);
}
