#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
};

void push(int x, Node** head_ref){
    Node* new_node = new Node;
    new_node->data = x;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insert(int x, Node* inode_ref){
    Node* new_node = new Node;
    new_node->data = x;
    new_node->next = inode_ref->next;
    inode_ref->next = new_node;
}

void append(int x, Node** head_ref){
    Node* new_node = new Node;
    Node* temp = *head_ref;

    new_node->data = x;
    new_node->next = NULL;

    if (temp == NULL){
        *head_ref = new_node;

    }
    else{
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<"->"<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}

void rprint(Node* head){
    Node* temp = head;
    if(temp->next != NULL){
    rprint(temp->next);
    cout<<"->"<<temp->data;
    }
    else{
        cout<<"->"<<temp->data;
    }
}

void reverse(Node** head_ref){
    Node* current = *head_ref;
    Node* previous = NULL;
    Node* temp_next = current;

    while(current != NULL){
        temp_next = current->next;
        current->next = previous;
        previous = current;
        current = temp_next;
    }
    *head_ref = previous;

}

void reverse_rec(Node** p_ref){
    Node* current = *p_ref;
    Node* rest = current->next;
    if(rest == NULL){
        return;
    }
    reverse_rec(&rest);
    Node* temp = current->next;
    current->next = NULL;
    temp->next = current;

    *p_ref = rest;
}

void deleteNode(int key, Node** head_ref){
    Node* current = *head_ref;
    if (key == current->data){
        *head_ref = current->next;
        return;
    }
    while((current->next)->data != key && current->next !=NULL){
        current = current->next;
    }

    if (current->next == NULL) return;

    current->next = (current->next)->next;

}

int main(){

    Node* head = NULL;
    int ch, x;
    int flag = 1;
    cout<<"-------LINKED LIST SIMULATOR-------"<<endl;
    cout<<"------------YOUR CHOICES-----------"<<endl;
    cout<<"Push : 1"<<endl;
    cout<<"Append : 2"<<endl;
    cout<<"Insertion : 3"<<endl;
    cout<<"Print : 4"<<endl;
    cout<<"Reverse Print : 5"<<endl;
    cout<<"Iteratively reverse a linked list : 6"<<endl;
    cout<<"Recursively reverse a linked list : 7"<<endl;
    cout<<"Delete : 8"<<endl;
    while (flag){
        cout<<"Choise : ";
        cin>>ch;
        switch(ch){
            case 1 :
                cout<<"Insert Number:";
                cin>>x;
                cout<<"Pushin...";
                push(x, &head);
                cout<<"Done!"<<endl;
                break;
            case 2 :
                cout<<"Insert Number:";
                cin>>x;
                cout<<"Appending...";
                append(x, &head);
                cout<<"Done!"<<endl;
                break;
            case 3 :
                break;
            case 4 :
                print(head);
                break;
            case 5 :
                rprint(head);
                cout<<endl;
                break;
            case 6 :
                reverse(&head);
                break;
            case 7 :
                reverse_rec(&head);
                break;
            case 8 :
                cout<<"Enter key to delete : ";
                cin>>x;
                cout<<"Deleting...";
                deleteNode(x,&head);
                cout<<"Done!"<<endl;
                break;
            default: flag = 0;
                break;
        }
    }

}

