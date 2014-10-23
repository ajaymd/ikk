/******************************************************************************
 *
 *  Make an expression that evaluates to k
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evaluateExpression(const char *digits, int length, const char *operators) {
    int result = 0;
    int multiplication = 0;
    int factor;

    for(int i = 0; ; ++i) {
        int operand = digits[i] - '0';
        while(i < length - 1 && operators[i] == '\0')
            operand = 10 * operand + digits[++i] - '0';

        if (multiplication) { 
            operand *= factor;
            multiplication = 0;
        }

        if (i == length - 1) {
            result += operand;
            break;
        }

        if (operators[i] == '+') {
            result += operand;
            continue;
        }
            
        multiplication = 1;
        factor = operand;
    }

    return result;
}

void expressionRecursion(const char *digits, int length, char *operators, int write, int k) {
    if (write == length - 1) {
        if (evaluateExpression(digits, length, operators) != k)
            return;

        int i;
        for(i = 0; i < length - 1; ++i)
            printf("%c%c", digits[i], operators[i]);
        printf("%c=%d\n", digits[i], k);
        return;
    }
    
    operators[write] = '*';
    expressionRecursion(digits, length, operators, write + 1, k);
    operators[write] = '+';
    expressionRecursion(digits, length, operators, write + 1, k);
    operators[write] = '\0';
    expressionRecursion(digits, length, operators, write + 1, k);
}

void expression(const char *digits, int length, int k) {
    char *operators = malloc((length - 1) * sizeof(char));
    expressionRecursion(digits, length, operators, 0, k);
    free(operators);
}

typedef struct {
    int k;
    const char *digits;
} TestCase;

TestCase tests[] = {
    {1, "2"},
    {2, "2"},
    {24, "222"},
    {8, "222"},
    {6, "222"},
    {14, "1234"},
    {222, "222"}
};  

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        printf("------------------ %s -> %d -------------------\n",
            tests[i].digits, tests[i].k);
        expression(tests[i].digits, strlen(tests[i].digits), tests[i].k);
    }
    return 0;
} 
