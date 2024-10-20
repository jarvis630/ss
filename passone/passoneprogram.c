#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char label[10],opcode[10],operand[10];
    char code[10],mnemonic[10];
    int start,locctr;
    FILE *input,*output,*optab,*symtab;
    
    input = fopen("input.txt","r");
    optab = fopen("optab.txt","r");
    output = fopen("output.txt","w");
    symtab = fopen("symtab.txt","w");
    
    fscanf(input,"%s\t%s\t%s",label,opcode,operand);
    if(strcmp(opcode,"START") == 0){
        start = atoi(operand);
        locctr = start;
        fprintf(output,"\t%s\t%s\t%s\n",label,opcode,operand);
        fscanf(input,"%s\t%s\t%s",label,opcode,operand);
    }
    else{
        start = locctr = 0;
    }
    while(strcmp (opcode,"END") != 0){
        fprintf(output,"%d\t",locctr);
        
        if(strcmp(label,"") !=0 && strcmp(label,"**") != 0){
            fprintf(symtab,"%s\t%d\n",label,locctr);
        }
        
        fscanf(optab,"%s\t%s",code,mnemonic);
        while(strcmp(code,"END") != 0){
            if(strcmp(opcode,code) == 0){
                locctr += 3;
            }
            fscanf(optab,"%s\t%s",code,mnemonic);
        }
        
        if(strcmp(opcode,"WORD") == 0){
            locctr += 3;
        }
        else if(strcmp(opcode,"RESW") == 0){
            locctr += 3*atoi(operand);
        }
        else if(strcmp(opcode,"RESB") == 0){
            locctr += atoi(operand);
        }
        else if(strcmp(opcode,"BYTE") == 0){
            ++locctr;
        }
        
        fprintf(output,"\t%s\t%s\t%s\n",label,opcode,operand);
        fscanf(input,"%s\t%s\t%s",label,opcode,operand);
    }
    fprintf(output,"\t%s\t%s\t%s",label,opcode,operand);
    printf("\nProgram size is %d",locctr - start);
    
    fclose (input);
    fclose (optab);
    fclose (output);
    fclose (symtab);

}






