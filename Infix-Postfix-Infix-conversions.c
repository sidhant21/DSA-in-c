#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int precedence(char op){
    switch(op){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void reverse(char *exp){
    int i=0, j=strlen(exp)-1;
    while(i<j){
        char temp=exp[i];
        exp[i]=exp[j];
        exp[j]=temp;
        i++; j--;
    }
}

char* convertinfixtopostfix(char* infixexp){
    int len = strlen(infixexp), top=-1, x=0;
    char* postfix=(char*)malloc(len+1);
    char operator[len];

    for(int i=0;i<len;i++){
        char ch=infixexp[i];

        if(isalnum(ch)){
            postfix[x++] = ch;
        }
        else if(ch=='('){
            operator[++top]=ch;
        }
        else if(ch==')'){
            while(top!=-1 && operator[top]!='(')
                postfix[x++]=operator[top--];
            top--; 
        }
        else{
            while(top!=-1 && precedence(ch)<=precedence(operator[top]) && operator[top]!='(')
                postfix[x++]=operator[top--];
            operator[++top]=ch;
        }
    }

    while(top!=-1)
        postfix[x++]=operator[top--];

    postfix[x]='\0';
    return postfix;
}

char* convertinfixtoprefix(char* infixexp){
    int len=strlen(infixexp);

    char temp[len+1];
    strcpy(temp,infixexp);
    reverse(temp);

    for(int i=0;i<len;i++){
        if(temp[i]=='(')
            temp[i]=')';
        else if(temp[i]==')')
            temp[i]='(';
    }

    char* postfix = convertinfixtopostfix(temp);
    reverse(postfix);

    return postfix;
}

char* convertpostfixtoinfix(char* postfixexp){
    int len = strlen(postfixexp), top=-1;
    char stack[100][100];

    for(int i=0;i<len;i++){
        char ch = postfixexp[i];

        if(isalnum(ch)){
            stack[++top][0]=ch;
            stack[top][1]='\0';
        }
        else{
            char s1[100], s2[100];
            strcpy(s1, stack[top--]);
            strcpy(s2, stack[top--]);

            sprintf(stack[++top], "(%s%c%s)", s2, ch, s1);
        }
    }

    char *infix=(char*)malloc(strlen(stack[top])+1);
    strcpy(infix, stack[top]);
    return infix;
}

char* convertPrefixToInfix(char* prefixExp){
    int len = strlen(prefixExp);
    int top = -1;
    char stack[100][100];
    for(int i=len-1;i>=0;i++){
        char ch = prefixExp[i]; 
        if(isalnum(ch)){
            char str[] = {ch, '\0'};
            strcpy(stack[++top],str);
        }
        else{
            char s1[100], s2[100];
            strcpy(s1, stack[top--]);
            strcpy(s2, stack[top--]);

            sprintf(stack[++top], "(%s%c%s)", s2, ch, s1);
        }
    }
    char *infix=(char*)malloc(strlen(stack[top])+1);
    
}

int main(){
    char infix[100];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    char* postfix = convertinfixtopostfix(infix);
    printf("Postfix Expression: %s\n", postfix);

    char* prefix = convertinfixtoprefix(infix);
    printf("Prefix Expression: %s\n", prefix);

    char expr[100];
    printf("Enter Postfix Expression to convert to Infix: ");
    scanf("%s", expr);

    printf("Infix expression = %s\n", convertpostfixtoinfix(expr));

    return 0;
}
