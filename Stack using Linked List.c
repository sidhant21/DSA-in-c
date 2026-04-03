//Dynamic Stack
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL)
        printf("Stack Overflow\n");
    else{
        temp->data = data;
        temp->next = top;
        top = temp;
        printf("%d push into the stack!!!\n",data);
        return;
    }
}

int pop(){
    if(top==NULL){
        printf("Stack Underflow !!!\n");
        return -1;
    }
    else{
        int val = top->data;
        top = top->next;
        return val;
    }
    return 0;
}

int peek(){
    if(top == NULL){
        printf("Stack Underflow !!!\n");
        return -1;
    }
    else{
        return top->data;
    }
}

void show(){
    if(top==NULL)
        printf("Stack is Empty!!!\n");
    else{
        struct Node* temp = top;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        
    }
}

int main(){
    int choice, data, res;
    while(1){
        printf("Stack Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                res = pop();
                if(res != -1)
                    printf("\n%d pop from stack.\n", res);
                break;
            case 3:
                res = peek();
                if(res != -1)
                    printf("\n%d peek from stack.\n", res);
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice...\n");
        }
        printf("\n");
    }
    return 0;
}
