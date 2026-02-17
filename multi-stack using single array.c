#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX] ,top1 = -1 ,top2=MAX;


void push_stack1(int value){
    if(top1==top2-1)
        printf("\n Stack-1 overflow .Cannot push into stack .!!\n");
        else{
            stack[++top1] = value;
            printf("\nPushed %d into stack-1 !!\n",value);
        }
    }
void push_stack2(int value){
    if(top1==top2-1)
        printf("\n Stack-2 overflow .Cannot push into stack .!!\n");
        else{
            stack[--top2] = value;
            printf("\nPushed %d into stack-2 !!\n",value);
        }
    }

    int pop_stack1(){
        if(top1==-1){
            printf("\nstack-1 underflow. Cannot pop from empty stack\n");
            return -1;
        }
        else{
            int val = stack[top1];
            top1--;
            return val;
        }
    }
    int pop_stack2(){
        if(top2==MAX){
            printf("\nstack-2 underflow. Cannot pop from empty stack\n");
            return -1;
        }
        else{
            int val = stack[top2];
            top2++;
            return val;
        }    
    }
    int display1(){
        if(top1==-1){
            printf("\nstack-1 is empty\n");
            return -1;
        }
        else{
            printf("\nstack-1 elements are: \n");
            for(int i=top1;i>=0;i--){
                printf("%d\t",stack[i]);
            }
        }

    }
    int display2(){
        if(top2==MAX){
            printf("\nstack-2 is empty\n");
            return -1;
        }
        else{
            printf("\nstack-1 elements are: \n");
            for(int i=top2;i<=MAX;i++){
                printf("%d\t",stack[i]);
            }
        }

    }
        
int main(){
    int choice,val,res,num;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter Stack Number(1-2):");
                scanf("%d",&num);
                printf("Enter value");
                scanf("%d",&val);
                if(num==1){
                    push_stack1(val);
                }
                else if(num==2){
                    push_stack2(val);
                }
                else
                    printf("\n Invalid stack number");
            break;
            case 2:
                printf("Enter Stack Number(1-2):");
                scanf("%d",&num);
                if(num==1){
                    pop_stack1();
                }
                else if(num==2){
                    pop_stack2();
                }
                else
                    printf("\n Invalid stack number");
                break;
            case 3:
                printf("Enter Stack Number(1-2):");
                scanf("%d",&num);
                if(num==1){
                    printf("%d",stack[top1]);
                }
                else if(num==2){
                    printf("%d",stack[top2]);
                }
                else
                    printf("\n Invalid stack number");
            break;
            case 4:
                printf("Enter Stack Number(1-2):");
                scanf("%d",&num);
                if(num==1){
                    display1();
                }
                else if(num==2){
                    display2();
                }
                else
                    printf("\n Invalid stack number");
            break;
            case 5:
                return 0;
            break;
            default:
                printf("\nInvalid stack number !!\n");
        }   
        printf("\n");      
    }
    return 0;
}
