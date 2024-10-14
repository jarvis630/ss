#include <stdio.h>
#include <conio.h>
#include <string.h>

void main() {
    char input[10];
    int start, length, address;
    FILE *fp1, *fp2;
    
    clrscr();
    
    fp1 = fopen("input2.dat", "r");
    fp2 = fopen("out2.dat", "w");
    
    fscanf(fp1, "%s", input);
    
    while (strcmp(input, "E") != 0) {
        if (strcmp(input, "H") == 0) {
            fscanf(fp1, "%d", &start);
            fscanf(fp1, "%d", &length);
            fscanf(fp1, "%s", input);
        } else if (strcmp(input, "T") == 0) {
            fscanf(fp1, "%d", &address);
            fscanf(fp1, "%s", input);
            
            fprintf(fp2, "%d\t%c%c\n", address, input[0], input[1]);
            fprintf(fp2, "%d\t%c%c\n", (address + 1), input[2], input[3]);
            fprintf(fp2, "%d\t%c%c\n", (address + 2), input[4], input[5]);
            
            address += 3;
            fscanf(fp1, "%s", input);
        } else {
            fprintf(fp2, "%d\t%c%c\n", address, input[0], input[1]);
            fprintf(fp2, "%d\t%c%c\n", (address + 1), input[2], input[3]);
            fprintf(fp2, "%d\t%c%c\n", (address + 2), input[4], input[5]);
            
            address += 3;
            fscanf(fp1, "%s", input);
        }
    }
    
    fclose(fp1);
    fclose(fp2);
    
    printf("FINISHED");
    getch();
}


INPUT FILE
INPUT2.DAT
H 1000 232
T 1000 142033 483039 102036
T 2000 298300 230000 282030 302015
E
OUTPUT FILE
OUT2.DAT
1000	14
1001	20
1002	33
1003	48
1004	30
1005	39
1006	10
1007	20
1008	36
2000	29
2001	83
2002	00
2003	23
2004	00
2005	00
2006	28
2007	20
2008	30
2009	30
2010	20
2011	15
