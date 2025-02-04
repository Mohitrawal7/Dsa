//



#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    int i;
    for (i = 0; exp[i] != '\0'; ++i) {
        if (isdigit(exp[i])) push(exp[i] - '0');
        else {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[] = "231*+9-";
    printf("Postfix evaluation: %d\n", evaluatePostfix(exp));
    return 0;
}

