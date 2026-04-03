#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL)
        printf("Queue Overflow\n");
    else{
        temp->data = data;
        temp->next = NULL;
        if(rear == NULL)
            rear = front = temp;
        else{
            rear->next = temp;
            rear = temp;
        }
        printf("%d push into the queue\n",data);
    }
}

int dequeue(){
    if(front == NULL){
        printf("Queue Underflow!!!\n");
        return -1;
    }
    else{
        int val = front->data;
        front = front->next;
        if(front==NULL)
            rear = front;
        return val;
    }
}

int peek(){
    if(front == NULL){
        printf("Queue Underflow!!\n");
        return -1;
    }
    else{
        return front->data;
    }
}  

void show(){
    if(front == NULL && rear == NULL)
        printf("Queue is empty\n");
    else{
        struct Node* temp = front;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
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
                show();
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
