// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX],top=-1;
int isEmpty(){
    return top ==-1;
}
int isFull(){
    return top== MAX-1;
}
void push(int value){
    if(isFull())
        printf("\nStack overflow");
    else{
        stack[++top]= value;
        printf("\n Pushed %d into the stack!!\n",value);
    }
}
int pop(){
    if(isEmpty())
        printf("\nStack is Empty");
    else{
        printf("\n Deleted %d ",stack[top]);
        top--;
    }
    
}
int peek(){
    if(isEmpty()){
        printf("\nStack is Empty");
        return -1;
    }
    else{
        return stack[top];
    }
}
void show(){
    if(isEmpty()){
        printf("\nStack is Empty");
    }
    else{
        for(int i=top; i>=0; i--){
            printf("%d\n",stack[i]);
        }
    }
    
}
int main() {
    int choice,val,res;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to insert\n");
                scanf("%d",&val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                show();
                break;
            case 5: 
                printf("Quiting...\n");
                return 0;
                break;
            
        }
    }
    
    return 0;
}
