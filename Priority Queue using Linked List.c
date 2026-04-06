#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    int priority;
    struct Node* next;
};
struct Node* front = NULL, *rear = NULL;
void enqueue(int data, int priority){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
        printf("\n%d inserted in queue\n",data);
    else{
        newNode->data = data;
        newNode->priority = priority;
        newNode->next = NULL;
        if(rear==NULL)
            rear = newNode;
        else
            rear->next = newNode;
            rear = newNode;
        if(front == NULL)
            front = rear;
        printf("Element added in queue !!!\n");
    }
}

struct Node* getHighestPriority(){
    struct Node* curr = front, *prev = NULL, *temp = NULL;
    int max = 0;
    
    while (curr != NULL){
        if(curr->priority > max){
            max = curr->priority;
            temp = prev;
        }
        prev = curr;
        curr = curr->next;
    }
    
}

int dequeue(){
    if(front == NULL && rear == NULL)
        printf("Queue Underflow!!!\n");
    else if(front == rear){
        int val = front->data;
        front = rear = NULL;
        return val;
    }
    else{
        struct Node* temp = getHighestPriority();
        int val;
        if(temp == NULL){
            val = front->data;
            front = front->next; 
        }
        else{
            val = temp->next->data;
            temp->next = temp->next->next;
        }
        return val;
    }
}
int peek(){
    if(front == NULL && rear == NULL)
        printf("Queue Underflow!!1\n");
    else{
        struct Node* temp = getHighestPriority();
        int val;
        if(temp == NULL)
            val = front->data;
        else
            val = temp->next->data;
        return val;
    }
}
void display(){
    if(front == NULL && rear == NULL){
        printf("Queue is Empty!!!\n");
        return;
    }
    else{
        struct Node* temp = front;
        while(temp != NULL){
            printf("Priority : %d --> Value : %d ",temp->priority,temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
int main(){
    int choice,value;
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to insert : ");
                scanf("%d",&value);
                enqueue(value);
            break;
            case 2:{
            int deleted = dequeue();
                if (deleted != -1)
                    printf("Deleted element: %d\n", deleted);
                break;
            }
            case 3:{
                int top = peek();
                if(top != -1)
                    printf("Front element: %d\n", top);
                break;
            }
            case 4:
                display();
            break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!!!\n");
        }

    }
    return 0;
}
