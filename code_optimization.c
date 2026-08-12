/*
 * EX.NO: 9
 * Implement simple code optimization techniques
 * (Constant folding, Strength reduction and Algebraic transformation)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char code[100][100];

int main() {
    FILE *fp;
    int i = 0;

    printf("Enter Three Address Code (end with CTRL+Z on Windows or CTRL+D on Linux):\n");

    // Write input to a file
    fp = fopen("infile.txt", "w");
    char ch;
    while ((ch = getchar()) != EOF) {
        fputc(ch, fp);
    }
    fclose(fp);

    // Read from file and store each line
    fp = fopen("infile.txt", "r");
    printf("\nUnoptimized Code:\n");
    while (fgets(code[i], sizeof(code[i]), fp)) {
        printf("%s", code[i]);
        i++;
    }
    fclose(fp);
    int lines = i;

    printf("\nOptimized Code:\n");
    for (i = 0; i < lines; i++) {
        char lhs, op1, op2, opr;
        int val1, val2, res;

        if (sscanf(code[i], "%c=%c%c%c;", &lhs, &op1, &opr, &op2) == 4) {
            if (isdigit(op1) && isdigit(op2)) {
                val1 = op1 - '0';
                val2 = op2 - '0';
                switch (opr) {
                    case '+': res = val1 + val2; break;
                    case '-': res = val1 - val2; break;
                    case '*': res = val1 * val2; break;
                    case '/': res = val2 != 0 ? val1 / val2 : 0; break;
                    default: res = 0; break;
                }
                printf("%c=%d;\t// Constant Folding\n", lhs, res);
            } else if ((opr == '*' && op2 == '1') || (opr == '/' && op2 == '1')) {
                printf("%c=%c;\t// Algebraic Simplification (X*1 or X/1)\n", lhs, op1);
            } else if (opr == '*' && op2 == '2') {
                printf("%c=%c+%c;\t// Strength Reduction (X*2 to X+X)\n", lhs, op1, op1);
            } else {
                printf("%s", code[i]); // No optimization
            }
        } else {
            printf("%s", code[i]); // Invalid or unoptimized format
        }
    }
    return 0;
}

/*
SAMPLE INPUT (infile.txt or typed):
a=2+4;
b=d*1;
c=s*2;

OUTPUT:
Unoptimized input block
a=d/1
b=2+4
c=s*2

Optimized three address code
type3 algebraic expression elimination: a=d
type2 constant folding: b=6
type1 reduction in strength: c=s*s

RESULT: Thus, the C program for simple code optimization techniques like constant folding, strength
reduction, and algebraic simplification was successfully implemented and tested with various inputs.
*/
