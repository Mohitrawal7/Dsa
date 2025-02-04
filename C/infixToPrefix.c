//



#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return -1;
    else return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1;
}

void reverse(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; ++i) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    reverse(infix);
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) prefix[k++] = c;
        else if (c == ')') push(c);
        else if (c == '(') {
            while (top != -1 && stack[top] != ')')
                prefix[k++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) > precedence(c))
                prefix[k++] = pop();
            push(c);
        }
    }
    while (top != -1)
        prefix[k++] = pop();
    prefix[k] = '\0';
    reverse(prefix);
}

int main() {
    char infix[] = "A+(B*J-(D/E$F)*G)*H";
    char prefix[SIZE];
    infixToPrefix(infix, prefix);
    printf("Infix: %s\n", infix);
    printf("Prefix: %s\n", prefix);
    return 0;
}
