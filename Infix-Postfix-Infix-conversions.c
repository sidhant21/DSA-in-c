#include <stdio.h> 
#include <string.h> 
#include <math.h> 
#include <ctype.h>  
#include <stdlib.h>

int precedence(char op){ 
    switch(op){ 
        case '+': 
        case '-': 
        return 1; 

        case '*': 
        case '/': 
        return 2; 

        case '^': 
        return 3; 

        default: 
        return 0;
    }
} 

char* conInfixToPostfix(char* infixExp){ 
    int len = strlen(infixExp), top = -1, x = 0;  
    char* postfix = (char*) malloc(len+1); 
    char operator[len]; 
    for(int i=0; i<len; i++){ 
        char ch = infixExp[i]; 
        if(isalnum(ch)) 
        postfix[x++] = ch;  
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){ 
            while(top != -1 && precedence(ch) <= precedence(operator[top]) && ch != '^'){ 
                postfix[x++] = operator[top--]; 
            }
            operator[++top] = ch;
        } 
        else if(ch == '(')
            operator[++top] = ch; 
            else if(ch == ')'){ 
                while(operator[top] != '('){ 
                   postfix[x++] = operator[top--];
                }
                top--;
            } 
        }

            while(top != -1){ 
                postfix[x++] = operator[top--]; 
            }
            postfix[x] = '\0'; 
                return postfix;
        
} 

char* InfixtoPrefix(char* infixExp){ 
    int len = strlen(infixExp);
    char rev[len+1];
    for(int i = 0; i < len; i++){
        rev[i] = infixExp[len - i - 1];
    }
    rev[len] = '\0';
    for(int i = 0; i < len; i++){
        if(rev[i] == '(')
            rev[i] = ')';
        else if(rev[i] == ')')
            rev[i] = '(';
    }
    char* postfix = conInfixToPostfix(rev);
    int plen = strlen(postfix);
    char* prefix = (char*) malloc(plen + 1);

    for(int i = 0; i < plen; i++){
        prefix[i] = postfix[plen - i - 1];
    }
    prefix[plen] = '\0';
    return prefix;
}
char* convertPostfixToInfix(char* postfixExp){
    int len = strlen(postfixExp), top = -1;
    char stack[100][100];
    for(int i=0; i<len;i++){
        char ch = postfixExp[i];
        if(isalnum(ch)){
            char str[] = {ch,'\0'};
            strcpy(stack[++top],str);
        }
        else if(ch =='+' || ch =='-' || ch =='*' || ch =='/' || ch =='^' ){
            char *s1 = stack[top--];
            char *s2 = stack[top--];
            char s3[100] = "" ;
            sprintf(s3, "(%s%c%s)",s2,ch,s1);
            strcpy(stack[++top],s3);
        }
    }
    char *infix = (char*) malloc(strlen(stack[top])+1);
    strcpy(infix, stack[top--]);
    return infix;
}
char* convertPrefixToInfix(char* prefixExp) {
    int len = strlen(prefixExp), top = -1;
    char stack[100][100];
    for (int i = len - 1; i >= 0; i--) {
        char ch = prefixExp[i];
        if (isalnum(ch)) {
            char str[2];
            str[0] = ch;
            str[1] = '\0';
            strcpy(stack[++top], str);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            char s1[100], s2[100];
            strcpy(s1, stack[top--]);
            strcpy(s2, stack[top--]);
            char s3[100]="";
            sprintf(s3, "(%s%c%s)", s1, ch, s2);
            strcpy(stack[++top], s3);
        }
    }
    char* infix = (char*)malloc(strlen(stack[top]) + 1);
    strcpy(infix, stack[top]);
    return infix;
}
int main(){  
    char expr[100];

    printf("Enter Infix Expression: ");
    gets(expr);
    char* postfix = conInfixToPostfix(expr);
    char* prefix = InfixtoPrefix(expr);

    printf("Postfix Expression: %s\n", postfix);
    printf("Prefix Expression: %s\n", prefix);
    printf("Enter Postfix Expression: ");
    gets(expr);
    printf("Infix Enpression = %s\n",convertPostfixToInfix(expr));
    printf("Enter Prefix Expression: ");
    gets(expr);
    printf("Infix Enpression = %s\n",convertPrefixToInfix(expr));
    return 0;
}
