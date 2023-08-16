#include <stdio.h>
#include "../programs/calculator/atof.h"
#include "../programs/calculator/mytype.h"
#include "../programs/calculator/getop.h"
#include "../programs/calculator/stackDetail.h"

int main(){
    int type;
    double op2;
    char s[MAX];
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if(op2 != 0.0)
                push(fmod(pop(),op2));
            else
                printf("error: division by zero\n");
            break;
        
        default:
            break;
        }
    }
    
}