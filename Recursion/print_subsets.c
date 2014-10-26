#include <stdio.h>

int set[] = {1, 2, 3, 4, 5, 6};
#define LENGTH  sizeof(set) / sizeof(int)
int subset[LENGTH];

void subsets(int read, int write) {
    if (read == LENGTH) {
        for (int j = 0; j < write; ++j)
            printf("%d ", subset[j]);
        printf("\n");
        return;
    }

    subsets(read + 1, write); // Don't select

    subset[write++] = set[read++]; // Select
    subsets(read, write);
}

int main() {
    subsets(0, 0);
    return 0;
}

