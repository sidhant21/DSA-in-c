#include <stdio.h>
#define MAX 100
int list[MAX];
int n=0;
void insertInBeg(int value){
    if(n==MAX){
        printf("List is Full !!!\n");
        return;
    }
    for(int i=n;i<0;i--){
        list[i]=list[i-1];
    }
    list[0] = value;
    n++;
    printf("Element Inserted!!!\n");
}


void insertAtEnd(int value){
    if(n==MAX){
        printf("List is Full !!!\n");
        return;
    }
    list[n++]=value;
    printf("Element Inserted!!!\n");
}


void insertAtPos(int pos,int value){
    if(n==MAX){
        printf("List is Full !!!\n");
        return;
    }
    if(pos>=n){
        printf("Invalid Position");
    }
    for(int i=n-1;i>=pos;i--){
        list[i+1]=list[i];
    }
    list[pos]=value;
    n++;
    printf("Element Inserted!!!\n");
}
void delFromBeg(){
    if(n==0){
        printf("List is Empty !!!\n");
        return;
    }
    for(int i=0;i<n-1;i++){
        list[i]=list[i+1];
        return;
    }
    n--;
    printf("Element Deleted!!!\n");
}

void delFromEnd(){
    if(n==0){
        printf("List is Empty !!!\n");
        return;
    }
    n--;
}
void delFromPos(int pos){
    if(n==0){
        printf("List is Empty !!!\n");
        return;
    }
    for(int i=pos;i<n-1;i++){
        list[i]=list[i+1];
        return;
    }
    n--;
    printf("Element Deleted!!!\n");
}
void displayList(){
    if(n==0){
        printf("List is empty!!!\n");
        return;
    }
    for(int i=0;i<n;i++){
        printf("%d\t",list[i]);
    }
    printf("\n");
}
int main() {
    while(1){
        int ch,data,pos;
        printf("1. Insert in Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at any Position\n");
        printf("4. Delete from Beginning \n");
        printf("5. Delete from End \n");
        printf("6. Delete from given Position\n");
        printf("7. Display List\n");
        printf("8. Search Element in List\n");
        printf("9. Update Element in List\n");
        printf("10. Sort Element in List\n");
        printf("11 Exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf("Enter Data: ");
                scanf("%d",&data);
                insertInBeg(data);
                break;
            case 2: 
                printf("Enter Data: ");
                scanf("%d",&data);
                insertAtEnd(data);
                break;
            case 3: 
                printf("Enter Data: ");
                scanf("%d",&data);
                printf("Enter Position: ");
                scanf("%d",&pos);
                insertAtPos(pos,data);
                break;
            case 4:
                delFromBeg();
                break;
            case 5: 
                delFromEnd();
                break;
            case 6: 
                printf("Enter Position: ");
                scanf("%d",&pos);
                delFromPos(pos);
                break;
            case 7:
                displayList();
                break;
            case 8: 
                break;
            case 9: 
                break;
            case 10: 
                break;
            case 11: 
                break;
            default:
                printf("Invalid Choice!!!\n");
        }
    }
    return 0;
}
