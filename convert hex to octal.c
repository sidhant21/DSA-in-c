// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
int octTodec(int n){
    int b =1;
    int dec=0;
    while(n!=0){
        dec=dec+(n%10)*b;
        n/=10;
        b=b*8;
    }
    return dec;
}
int decToBin(int dec){
    int b=1;
    int bin=0;
    while(dec!=0){
        bin=bin+(dec%2)*b;
        b=b*10;
        dec/=2;
    }
    return bin;

}
int main() {
    int n=0,dec=0;
    printf("Enter Octal Number:");
    scanf("%d",&n);
    printf("%d",decToBin(octTodec(n)));
    
    return 0;
}
