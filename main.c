#include "treat_ip.h"
#include <stdio.h>
#include "treat_mask.h"
#define LENGTH 50
int main(){
    ///variables
    char internet_protocol[LENGTH];
    char netmask_string[LENGTH];
    char IP[37];
    char MSR[37];
    char network[37];
    int first_bit=256;
    int second_bit=256;
    int third_bit=256;
    int last_bit=256;
    char last_word='\0';
    char class_indice;
    int first_bitmask;
    int second_bitmask;
    int third_bitmask;
    int last_bitmask;
    char first_byte[9];
    char second_byte[9];
    char third_byte[9];
    char last_byte[9];
    ///traitement ip
    input_ip(internet_protocol);
    treat_ip(internet_protocol,&first_bit,&second_bit,&third_bit,&last_bit,&last_word);
    verify_ip(first_bit,second_bit,third_bit,last_bit,last_word,&class_indice);
    //traitement mask
    input_netmask(netmask_string);
    treat_ip(netmask_string,&first_bitmask,&second_bitmask,&third_bitmask,&last_bitmask,&last_word);
    verify_mask(first_bitmask,second_bitmask,third_bitmask,last_bitmask,last_word,class_indice);
    ///l'adresse de diffusion et l'adresse reseau
    //CONVERTION en binaire
    convert_binary(IP,first_bit,second_bit,third_bit,last_bit);
    convert_binary(MSR,first_bitmask,second_bitmask,third_bitmask,last_bitmask);
    reverify_mask(MSR);
    //adresse reseau
    adressing_network(network,IP,MSR);
    cat_binary(network,first_byte,second_byte,third_byte,last_byte);
    convert_decimal(first_byte,second_byte,third_byte,last_byte,first_bit,second_bit,third_bit,last_bit);
    ///adresse de diffusion
    reconvert(MSR);
    adressing_broadcast(network,IP,MSR);
    cat_binary_mask(network,first_byte,second_byte,third_byte,last_byte);
    convert_decimal_mask(first_byte,second_byte,third_byte,last_byte,first_bit,second_bit,third_bit,last_bit);
    return 0;
}
