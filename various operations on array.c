#include <stdio.h>
#define MAX 100
int list[MAX];
int n=0;
void insertInBeg(int value){
    if(n==MAX){
        printf("\nList is Full !!!\n");
        return;
    }
    for(int i=n;i>0;i--){
        list[i]=list[i-1];
    }
    list[0] = value;
    n++;
    printf("\nElement Inserted!!!\n");
}


void insertAtEnd(int value){
    if(n==MAX){
        printf("\nList is Full !!!\n");
        return;
    }
    list[n++]=value;
    printf("\nElement Inserted!!!\n");
}


void insertAtPos(int pos,int value){
    if(n==MAX){
        printf("\nList is Full !!!\n");
        return;
    }
    if(pos>=n){
        printf("\nInvalid Position");
    }
    for(int i=n-1;i>=pos;i--){
        list[i+1]=list[i];
    }
    list[pos]=value;
    n++;
    printf("\nElement Inserted!!!\n");
}
void delFromBeg(){
    if(n==0){
        printf("\nList is Empty !!!\n");
        return;
    }
    for(int i=0;i<n-1;i++){
        list[i]=list[i+1];
        return;
    }
    n--;
    printf("\nElement Deleted!!!\n");
}

void delFromEnd(){
    if(n==0){
        printf("\nList is Empty !!!\n");
        return;
    }
    n--;
}
void delFromPos(int pos){
    if(n==0){
        printf("\nList is Empty !!!\n");
        return;
    }
    for(int i=pos;i<n-1;i++){
        list[i]=list[i+1];
        return;
    }
    n--;
    printf("\nElement Deleted!!!\n");
}
void displayList(){
    if(n==0){
        printf("\nList is empty!!!\n");
        return;
    }
    for(int i=0;i<n;i++){
        printf("%d\t",list[i]);
    }
    printf("\n");
}

int search(int value){
    for(int i=0;i<n;i++){
        if(list[i]==value){
            return i;
        }
    }
    return -1;
}
void update(int pos,int val){
    list[pos] = val;
}

void sort(){
    if(n==0){
        printf("\nList is Empty\n");
        return;
    }
    for(int i=0; i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(list[j]>list[j+1]){
                list[j]=list[j]+list[j+1];
                list[j+1]=list[j]-list[j+1];
                list[j]=list[j]-list[j+1];
            }
        }
    }
    printf("\nList is sorted\n");
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
        printf("11 Exit\n\n");
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
                printf("Enter Value to search: ");
                scanf("%d",&data);
                int i = search(data);
                if(i!=-1){
                    printf("Element found at index %d\n");
                }
                else{
                    printf("Element Not Found\n");
                }
                break;
            case 9: 
                printf("Enter Position: ");
                scanf("%d",&pos);
                printf("Enter Value: ");
                scanf("%d",&data);
                update(pos,data);
                break;
            case 10: 
                sort();
                break;
            case 11: 
                printf("Quiting...\n");
                return 0;
                break;
            default:
                printf("Invalid Choice!!!\n");
        }
    }
    return 0;
}
