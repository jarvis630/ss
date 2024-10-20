#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    int start,address,length;
    char input[10];
    FILE *inputfile,*outputfile;
    
    inputfile = fopen("input.txt","r");
    outputfile = fopen("output.txt","w");
    
    fscanf(inputfile,"%s",input);
    
    while(strcmp(input,"E") != 0){
        if(strcmp(input,"H") == 0){
            fscanf(inputfile,"%x",&start);
            fscanf(inputfile,"%d",&length);
            fscanf(inputfile,"%s",input);
        }
        
        else if(strcmp(input,"T") == 0){
            fscanf(inputfile,"%x",&address);
            fscanf(inputfile,"%s",input);
            
            fprintf(outputfile,"%x\t%c%c\n",address++,input[0],input[1]);
            fprintf(outputfile,"%x\t%c%c\n",address++,input[2],input[3]);
            fprintf(outputfile,"%x\t%c%c\n",address++,input[4],input[5]);
            
            fscanf(inputfile,"%s",input);
        }
        else{
            fprintf(outputfile,"%x\t%c%c\n",address++,input[0],input[1]);
            fprintf(outputfile,"%x\t%c%c\n",address++,input[2],input[3]);
            fprintf(outputfile,"%x\t%c%c\n",address++,input[4],input[5]);
            fscanf(inputfile,"%s",input);
        }
    }
    
    fclose(inputfile);
    fclose(outputfile);
    
    printf("PROGRAM FINISHED");
}
