#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char label[10], operand[10], opcode[10];
    char code[10], mnemonic[10];
    int start, locctr;
    FILE *input, *optab, *output, *symtab;

    input = fopen ("input.txt", "r");
    optab = fopen ("optab.txt", "r");
    output = fopen ("output.txt", "w");
    symtab = fopen ("symtab.txt", "w");

    fscanf (input, "%s\t%s\t%s", label, opcode, operand);
    if (strcmp (opcode , "START") == 0) {
        locctr = atoi (operand);
        start = locctr;
        fprintf (output, "\t%s\t%s\t%s\n",label, opcode, operand);
        fscanf (input, "%s\t%s\t%s",label, opcode, operand);
    } else {
        locctr = 0;
        start = 0;
    }

    while (strcmp (opcode, "END") != 0) {
        fprintf (output, "%d\t",locctr);

        if (strcmp (label, "") != 0 && strcmp (label, "**") != 0) {
            fprintf (symtab, "%s\t%d\n",label, locctr);
        }

        fscanf (optab, "%s\t%s",code, mnemonic);
        while (strcmp (code, "END") != 0) {
            if (strcmp (code, opcode) == 0) {
                locctr += 3;
                break;
            }
            fscanf (optab, "%s\t%s",code, mnemonic);
        }

        if (strcmp (opcode, "WORD") == 0)
            locctr += 3;
        else if (strcmp (opcode, "RESW") == 0)
            locctr += (3 * atoi (operand));
        else if (strcmp (opcode, "RESB") == 0)
            locctr += atoi (operand);
        else if (strcmp (opcode, "BYTE") == 0)
              ++locctr;

        fprintf (output, "\t%s\t%s\t%s\n",label, opcode, operand);
        fscanf (input, "%s\t%s\t%s",label, opcode, operand);
    }

    fprintf (output, "%d\t%s\t%s\t%s\n",locctr,label, opcode, operand);
    printf("\nProgram Size : %d\n", locctr - start);

    fclose (input);
    fclose (optab);
    fclose (output);
    fclose (symtab);
}
