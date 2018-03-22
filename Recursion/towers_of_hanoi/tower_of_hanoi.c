/******************************************************************************
 *
 *  Solve the Hanoi Towers problem
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int *createStack(int size) {
    unsigned int *stack = malloc(sizeof(int) * (size + 1));    
    stack[0] = 0;
    return stack;
}

void push(unsigned int *stack, unsigned int value) {
    stack[0]++;
    stack[stack[0]] = value;
}

char pop(unsigned int *stack) {
    if (stack[0] == 0)
        return 0;
    return stack[stack[0]--];
}

int size(unsigned int *stack) {
    return stack[0];
}
    
void printGame(unsigned int **game) {
    printf("[");
    int tower_size = size(game[0]);
    for (int j = 1; j <= tower_size; ++j)
        printf("%u ", game[0][j]);            
    printf("\n[");
    tower_size = size(game[1]);
    for (int j = 1; j <= tower_size; ++j)
        printf("%u ", game[1][j]);            
    printf("\n[");
    tower_size = size(game[2]);
    for (int j = 1; j <= tower_size; ++j)
        printf("%u ", game[2][j]);            
    printf("\n\n");
}

typedef struct Move {
    struct Move *before;
    int from, to;
    struct Move *after;
} Move;

Move *moveTower(int n, int from, int to) {
    Move *solution = malloc(sizeof(Move));
    solution->from = from;
    solution->to = to;

    if (n == 1) {
        solution->before = NULL;
        solution->after = NULL;
    } else {
        solution->before = moveTower(n - 1, from, 6 - from - to);
        solution->after = moveTower(n - 1, 6 - from - to, to);
    }

    return solution;
}

void runSolution(unsigned int **game, Move *move) {
    static int i = 0;
    if (move->before != NULL)
        runSolution(game, move->before);
    push(game[move->to - 1], pop(game[move->from - 1]));
    printf("%d:\n", ++i);
    printGame(game);
    if (move->after != NULL)
        runSolution(game, move->after);
}

void hanoiTowers(int n) {
    Move *solution = moveTower(n, 1, 3);
    unsigned int *game[3];
    game[0] = createStack(n);    
    game[1] = createStack(n);    
    game[2] = createStack(n);    
    for(int i = 0; i < n; ++i)
        push(game[0],  n - i);
    printf("Solution:\n");
    printGame(game);
    runSolution(game, solution);
    free(game[0]);
    free(game[1]);
    free(game[2]);
    free(solution);
}

int main(int argc, char **argv) {
    hanoiTowers(atoi(argv[1]));
    return 0;
} 
