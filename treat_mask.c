#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "treat_mask.h"
void reconvert(char*MSR) {
    char temp[37];
    strcpy(temp,"");
    for(int i=0;i<35;i++) {
        if(MSR[i]=='0') strcat(temp,"1");
        if(MSR[i]=='1') strcat(temp,"0");
        if(MSR[i]==' ') strcat(temp," ");
    }
    strcpy(MSR,temp);
}
void convert_decimal_mask(char*first_byte,char*second_byte,char*third_byte,char*last_byte,int first_bit,int second_bit,int third_bit,int last_bit) {
    calcul_byte(&first_bit,first_byte);
    calcul_byte(&second_bit,second_byte);
    calcul_byte(&third_bit,third_byte);
    calcul_byte(&last_bit,last_byte);
    printf("@ broadcast: %d.%d.%d.%d\n",first_bit,second_bit,third_bit,last_bit);
}
void cat_binary_mask(char*network,char*first_byte,char*second_byte,char*third_byte,char*last_byte) {
    sscanf(network,"%s %s %s %s",first_byte,second_byte,third_byte,last_byte);
}
void adressing_broadcast(char*network,char*IP,char*MSR) {
    strcpy(network,"");
    for(int i=0;i<35;i++) {
        if(strncmp(IP+i,MSR+i,1)==0 && IP[i]=='0') {
            strcat(network,"0");
        }
        else {
            if(strncmp(IP+i,MSR+i,1)==0 && IP[i]==' ') strcat(network," ");
            else strcat(network,"1");
        }
    }
}
void calcul_byte(int*first_bit,char*first_byte) {
    int temp_bit=0;
    for(int i=0;i<8;i++){
        if(first_byte[i]=='1') {
            temp_bit+=1*pow(2,7-i);
        }
        if(first_byte[i]=='0') {
            temp_bit=temp_bit;
        }
        //printf("%d\n",first_bit);
    }
    *first_bit=temp_bit;
}
void convert_decimal(char*first_byte,char*second_byte,char*third_byte,char*last_byte,int first_bit,int second_bit,int third_bit,int last_bit) {
    calcul_byte(&first_bit,first_byte);
    calcul_byte(&second_bit,second_byte);
    calcul_byte(&third_bit,third_byte);
    calcul_byte(&last_bit,last_byte);
    printf("@ network: %d.%d.%d.%d\n",first_bit,second_bit,third_bit,last_bit);
}
void cat_binary(char*network,char*first_byte,char*second_byte,char*third_byte,char*last_byte) {
    sscanf(network,"%s %s %s %s",first_byte,second_byte,third_byte,last_byte);
}
void adressing_network(char*network,char*IP,char*MSR) {
    for(int i=0;i<35;i++) {
        if(strncmp(IP+i,MSR+i,1)==0 && IP[i]=='1') {
            strcat(network,"1");
        }
        else {
            if(strncmp(IP+i,MSR+i,1)==0 && IP[i]==' ') strcat(network," ");
            else strcat(network,"0");
        }
    }    
}
void reverify_mask(char*MSR) {
    if(strstr(MSR,"01")!=NULL) {
        printf("INVALID NETMASK!!!\n");
        exit(1);
    }
}
void convert_binary(char*IP,int first_bit,int second_bit,int third_bit,int last_bit) {
    int bit;
    int suite;
    suite=first_bit;
    strcpy(IP,"");
    for (int i=7;i>=0;i--) {
        bit=suite/pow(2,i);
        suite=suite-bit*pow(2,i);
        if (bit==1) strcat(IP,"1");
        if (bit==0) strcat(IP,"0");
    }
    strcat(IP," ");
    suite=second_bit;
    for (int i=7;i>=0;i--) {
        bit=suite/pow(2,i);
        suite=suite-bit*pow(2,i);
        if (bit==1) strcat(IP,"1");
        if (bit==0) strcat(IP,"0");
    }
    strcat(IP," ");
    suite=third_bit;
    for (int i=7;i>=0;i--) {
        bit=suite/pow(2,i);
        suite=suite-bit*pow(2,i);
        if (bit==1) strcat(IP,"1");
        if (bit==0) strcat(IP,"0");
    }
    strcat(IP," ");
    suite=last_bit;
    for (int i=7;i>=0;i--) {
        bit=suite/pow(2,i);
        suite=suite-bit*pow(2,i);
        if (bit==1) strcat(IP,"1");
        if (bit==0) strcat(IP,"0");
    }
}
void input_netmask(char*netmask_string) {
    //fgets();
    //printf("\n");
    //lush(stdin);
    printf("Input the netmask:\n");
    printf("->");
    scanf("%s",netmask_string);
}
void verify_mask(int first_bitmask,int second_bitmask,int third_bitmask,int last_bitmask,char last_word,char class_indice){
    char response[50];
    if( last_word != '\0' ){
        strcpy(response,"invalid netmask!!!");
        printf("%s",response);
        exit(1);
    }
    if (class_indice == 'A') {
        if(first_bitmask != 255 ) {
            strcpy(response,"invalid netmask!!!");
            printf("%s",response);
            exit(1);
        }
    }
    if (class_indice == 'B') {
        if(first_bitmask != 255 || second_bitmask != 255) {
            strcpy(response,"invalid netmask!!!");
            printf("%s",response);
            exit(1);
        }
    }
    if (class_indice == 'C') {
        if(first_bitmask != 255 || second_bitmask != 255 || third_bitmask != 255) {
            strcpy(response,"invalid netmask!!!");
            printf("%s",response);
            exit(1);
        }
    }
}


