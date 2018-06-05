# Linked List

## Introduction to linked list

```c++
struct Node{
    int data;
    Node* next;
};
```



## Push

inserting element at the top of the list

```c++
void push(int x, Node** head_ref){
    Node* new_node = new Node;
    new_node->data = x;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
```



## Append

Inserting element at the last of the list

```c++
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
```



## Nth position insertion

Insert after nth element in the lined list

```c++
void insert(int x, Node* inode_ref){
    Node* new_node = new Node;
    new_node->data = x;
    new_node->next = inode_ref->next;
    inode_ref->next = new_node;
}
```



## Print

```c++
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<"->"<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}
```



## Reverse Print

```c++
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
```



## Iteratively reverse a linked list

```c++
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
```



### Recursively reverse a linked list

```c++
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
```

 

### Deleting a key

```c++
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
```



### Given only a pointer/reference to a node to be deleted in a singly linked list, how do you delete it?

```c++
    // Find next node using next pointer
    struct Node *temp  = node_ptr->next;

    // Copy data of next node to this node
    node_ptr->data  = temp->data;

    // Unlink next node
    node_ptr->next  = temp->next;

    // Delete next node
    free(temp);
```



### Swapping nodes (Without swapping data)

```c++
void swapNodes(struct Node **head_ref, int x, int y)
{
   // Nothing to do if x and y are same
   if (x == y) return;
 
   // Search for x (keep track of prevX and CurrX
   struct Node *prevX = NULL, *currX = *head_ref;
   while (currX && currX->data != x)
   {
       prevX = currX;
       currX = currX->next;
   }
 
   // Search for y (keep track of prevY and CurrY
   struct Node *prevY = NULL, *currY = *head_ref;
   while (currY && currY->data != y)
   {
       prevY = currY;
       currY = currY->next;
   }
 
   // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;
 
   // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currY;
   else // Else make y as new head
       *head_ref = currY;  
 
   // If y is not head of linked list
   if (prevY != NULL)
       prevY->next = currX;
   else  // Else make x as new head
       *head_ref = currX;
 
   // Swap next pointers
   struct Node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}
 
```



