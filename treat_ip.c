#include <stdio.h>
#include "treat_ip.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
void printing(char*response){
        for(int i=0;i<strlen(response);i++) {
            putchar(response[i]);
            fflush(stdout);
            usleep(100000);
        }
        printf("\n");
}
void input_ip(char*string){
    system("clear");
    printf("Input the ip:\n");
    printf("->");
    scanf("%[^\n]",string);
}
void treat_ip(char*string,int*first_bit,int*second_bit,int*third_bit,int*fourth_bit,char*last){
    sscanf(string,"%d.%d.%d.%d%c",first_bit,second_bit,third_bit,fourth_bit,last);
}
void verify_ip(int first_bit,int second_bit,int third_bit,int fourth_bit,char last,char*class_indice){
    char response[50];
    if(first_bit>255 || first_bit<0 ||second_bit>255 || second_bit<0  ||third_bit>255 || third_bit<0 || fourth_bit>255 || fourth_bit<0 || last != '\0' ){
        strcpy(response,"invalid ip!!!");
        printing(response);
        exit(1);
    }
    else {
        if(first_bit < 128){
            strcpy(response,"your ip is in the class A!!!");
            printf("%s\n",response);
            *class_indice='A';
            if (first_bit !=10) {
                printf("Public IP\n");
                exit(1);
            }
        } 
        if(first_bit >= 128 && first_bit<192){
            strcpy(response,"your ip is in the class B!!!");
            printf("%s\n",response);
            *class_indice='B';
            if (first_bit !=172) {
                printf("Public IP\n");
                exit(1);
            }
            else {
                if(second_bit<16 || second_bit>31){
                        printf("Public IP\n");
                        exit(1);
                }
            }
        } 
        if(first_bit >= 192 && first_bit<224){
            strcpy(response,"your ip is in the class C!!!");
            printf("%s\n",response);
             *class_indice='C';
            if (first_bit !=192 && second_bit !=168) {
                printf("Public IP\n");
                exit(1);
            }
        } 
          if(first_bit >= 224 && first_bit<240){
            strcpy(response,"your ip is in the class D!!!");
            printing(response);
            exit(1);
        } 
        if(first_bit >= 240){
            strcpy(response,"your ip is in the class C!!!");
            printing(response);
            exit(1);
        } 
    }
}
