#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int val;
    scanf("%d",&val);
    int startIdx = 0;
    int endIdx = n-1;
    while(startIdx <= endIdx){
        int mid = startIdx + (endIdx - startIdx)/2;
        if(val == arr[mid]){
            printf("%d found in array",val);
            return 0;
        }
        else if(val < arr[mid])
            endIdx = mid - 1;
        else
            startIdx = mid + 1;
    }
    printf("%d not found in array",val);
    return 0;
}
