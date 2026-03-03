#include <stdio.h>
#define MAX 100
int queue[MAX],front=-1, rear=-1;
int isFull(){
    return rear == MAX-1;
}
int isEmpty(){
    return front == -1;
}
void enqueue(int data){
    if(isFull){
        printf("Queue Overflow!!!\n");
        return;
    }
    queue[++rear]=data;
    if(front == -1)
        front = rear;
    printf("\n%d inserted in queue\n",data);
}
int dequeue(){
    if(isEmpty()){
        printf("\nQueue Underflow!\n");
        return;
    }
    //next is also removes the first element from queue
    int val=queue[front++];
    if(front>rear)
        front = rear = -1;
    return val;
}
void display(){
    if(isEmpty()){
        printf("\nQueue is Empty!\n");
        return;
    }
    for(int i=front; i<=rear; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main(){
    int ch,val;
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            
        break;
        case 4:
            dequeue();
            break;
        case 5:
            enqueue(val);
            break;
        default:
            break;
        }
    }
}
