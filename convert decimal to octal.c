// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
int binToDec(int bin, int p){
    int n=0;
    while(bin!=0){
        n=n+(bin%10)*pow(2,p);
        p++;
        bin/=10;
    }
        return n;
}

int main() {
    int oct=0,n=0, bin=0;
    printf("Enter Number:");
    scanf("%d",&bin);
    int t = bin;
    int p=0;
    n=binToDec(bin,p);
    p=1;
    while(n!=0){
        oct=oct+(n%8)*p;
        n/=8;
        p*=10;
    }
    
    printf("%d",oct);
    return 0;
}
