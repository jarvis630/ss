#include <stdio.h>                                                                                                                                                                                 relocation_loader.c                                                                                                                                                                                                          #include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert(const char *hex, char *binary);

int main() {
    char input[10], pn[5], bitmask[12], bit[50];
    int start, address, opcode, addr, actualadd, tlen;
    FILE *fp1, *fp2;

    printf("Enter the actual starting address (in hex): ");
    scanf("%x", &start);

    fp1 = fopen("RLIN.txt", "r");
    fp2 = fopen("RLOUT.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fprintf(fp2, "...........\n");
    fprintf(fp2, " ADDRESS\tCONTENT\n");
    fprintf(fp2, ".......... \n");

    while (fscanf(fp1, "%s", input) == 1 && strcmp(input, "E") != 0) {
        if (strcmp(input, "H") == 0) {
            fscanf(fp1, "%s %x %x", pn, &address, &tlen);
            printf("Header: %s, Address: %06x, Length: %d\n", pn, address, tlen);
        } else if (strcmp(input, "T") == 0) {
            fscanf(fp1, "%x %x %s", &address, &tlen, bitmask);
            address += start;  // Relocate address
            printf("Text record at address: %06x, Length: %d, Bitmask: %s\n", address, tlen, bitmask);
            convert(bitmask, bit);

            for (int i = 0; i < tlen / 3; i++) {
                fscanf(fp1, "%x", &opcode);
                fscanf(fp1, "%x", &addr);
                char relocbit = bit[i];
                actualadd = (relocbit == '0') ? addr : addr + start;
                fprintf(fp2, "%06x\t\t%02x%04x\n", address, opcode, actualadd);
                address += 3;
            }
        }
    }

    fprintf(fp2, ".......... \n");
    fclose(fp1);
    fclose(fp2);

    printf("\nContents of output file (RLOUT.txt):\n");
    fp2 = fopen("RLOUT.txt", "r");
    if (fp2 == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    char ch;
    while ((ch = fgetc(fp2)) != EOF) {
        putchar(ch);
    }
    fclose(fp2);

    return EXIT_SUCCESS;
}

