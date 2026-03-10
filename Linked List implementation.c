#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertInBeg(int data){
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Node inserted at beginning\n");
}
void insertAtEnd(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    printf("Node inserted at end\n");
}

void insertAtPosition(int data, int pos){
    if(pos < 0){
        printf("Invalid position!\n");
        return;
    }
    if(pos == 0){
        insertInBeg(data);
        return;
    }
    struct Node* temp = head;
    int i = 0;
    while(temp != NULL && i < pos-1){
        temp = temp->next;
        i++;
    }
    if(temp == NULL){
        printf("Invalid position!\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d\n", pos);
}
void deleteFromBeginning(){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from beginning\n");
}
void deleteFromEnd(){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
        printf("Node deleted from end\n");
        return;
    }
    struct Node* temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from end\n");
}
void deleteFromPosition(int pos){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    if(pos == 0){
        deleteFromBeginning();
        return;
    }
    struct Node* temp = head;
    int i = 0;
    while(temp != NULL && i < pos-1){
        temp = temp->next;
        i++;
    }
    if(temp == NULL || temp->next == NULL){
        printf("Invalid position!\n");
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Node deleted from position %d\n", pos);
}
void displayList(){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void searchElement(int data){
    struct Node* temp = head;
    int pos = 0;
    while(temp != NULL){
        if(temp->data == data){
            printf("Element %d found at position %d\n", data, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found\n");
}
int main(){
    int choice, data, pos;
    while(1){
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Search Element\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter data: ");
            scanf("%d",&data);
            insertInBeg(data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d",&data);
            insertAtEnd(data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d",&data);
            printf("Enter position: ");
            scanf("%d",&pos);
            insertAtPosition(data,pos);
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d",&pos);
            deleteFromPosition(pos);
            break;
        case 7:
            displayList();
            break;
        case 8:
            printf("Enter element to search: ");
            scanf("%d",&data);
            searchElement(data);
            break;

        case 9:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
