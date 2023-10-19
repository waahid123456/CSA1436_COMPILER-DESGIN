#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_NON_TERMINALS 3
#define NUM_TERMINALS 3
#define NUM_PRODUCTIONS 4

// Define the non-terminals, terminals, and productions
char nonTerminals[NUM_NON_TERMINALS] = {'S', 'A', 'B'};
char terminals[NUM_TERMINALS] = {'a', 'b', 'c'};
char productions[NUM_PRODUCTIONS][10] = {
    "S->aAb",
    "A->cA",
    "A->b",
    "B->cB"
};

// Define the SLR parsing table
char actionTable[6][3][10]; // Rows: States, Columns: Terminals, Items

// Initialize the action table with empty strings
void initializeActionTable() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            strcpy(actionTable[i][j], "");
        }
    }
}

// Add entries to the action table
void addToActionTable(int state, char terminal, const char *action) {
    int j = 0;
    while (terminals[j] != terminal) {
        j++;
    }

    strcpy(actionTable[state][j], action);
}

int main() {
    initializeActionTable();

    // Add entries to the action table based on the grammar rules
    addToActionTable(0, 'a', "S3");
    addToActionTable(0, 'c', "S4");
    addToActionTable(1, 'b', "R3");
    addToActionTable(2, 'b', "S2");
    addToActionTable(2, 'c', "S4");
    addToActionTable(3, 'a', "S3");
    addToActionTable(3, 'c', "S4");
    addToActionTable(4, 'b', "R2");
    addToActionTable(5, 'b', "R1");
    addToActionTable(5, 'c', "R1");

    // Display the SLR parsing table
    printf("SLR Parsing Action Table:\n");
    printf("     a        b        c\n");
    for (int i = 0; i < 6; i++) {
        printf("%d  ", i);
        for (int j = 0; j < 3; j++) {
            printf("%s  ", actionTable[i][j]);
        }
        printf("\n");
    }

    return 0;
}
