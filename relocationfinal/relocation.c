#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char *bitmask, char * bits);

void main() {
    char input[20], bitmask[20], bits[20], head_name[20];
    int start, opcode, head_start, tlen, address, addr, actual_address;
    FILE *in, *out;

    in = fopen("input.txt","r");
    out = fopen("output.txt", "w");

    printf("\nEnter the actual starting address : ");
    scanf("%x",&start);

    while(fscanf(in, "%s", input) == 1 && strcmp(input, "END") != 0) {
        if (strcmp(input, "H") == 0) {
            fscanf(in, "%s %x %x", head_name, &head_start, &tlen);
        }
        else if (strcmp(input, "T") == 0) {
            fscanf(in, "%x %x %s", &address, &tlen, bitmask);
            address += start;
            convert(bitmask, bits);

            for (int i = 0; i < tlen; i++) {
                fscanf(in, "%x %x", &opcode, &addr);
                char relocbit = bits[i];
                actual_address = (relocbit == '0')? addr : addr + start;

                fprintf(out, "%06x\t%02x%04x\n", address, opcode, actual_address);
                address += 3;
            }
        }
    }

    printf("\nFinished loading");
    fclose(in);
    fclose(out);
}

void convert(char *bitmask, char *bits) {
    bits[0] = '\0';

    for (int i = 0; bitmask[i] != '\0'; i++) {
        switch(bitmask[i]) {
            case '0' : 
                strcat(bits, "0000");
                break;
            case '1' :
                strcat(bits, "0001");
                break;
            case '2' :
                strcat(bits, "0010");
                break;
            case '3' :
                strcat(bits, "0011");
                break;
            case '4' :
                strcat(bits, "0100");
                break;
            case '5' :
                strcat(bits, "0101");
                break;
            case '6' :
                strcat(bits, "0110");
                break;
            case '7' : 
                strcat(bits, "0111");
                break;
            case '8' :
                strcat(bits, "1000");
                break;
            case '9' :
                strcat(bits, "1001");
                break;
            case 'A' : 
                strcat(bits, "1010");
                break;
            case 'B' :
                strcat(bits, "1011");
                break;
            case 'C' :
                strcat(bits, "1100");
                break;
            case 'D' :
                strcat(bits, "1101");
                break;
            case 'E' :
                strcat(bits, "1110");
                break;
            case 'F' :
                strcat(bits, "1111");
                break;
            default :
                printf("\nInvalid hex value");
                exit(0);
        }
    }
}
