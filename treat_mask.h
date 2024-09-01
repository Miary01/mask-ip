#ifndef TREAT_MASK_H
#define TREAT_MASK_H
void input_netmask(char*netmask_string); //input the netmask
void verify_mask(int first_bitmask,int second_bitmask,int third_bitmask,int last_bitmask,char last_word,char class_indice);
void convert_binary(char*IP,int first_bit,int second_bit,int third_bit,int last_bit);
void adressing_network(char*network,char*IP,char*MSR);
void convert_decimal(char*first_byte,char*second_byte,char*third_byte,char*last_byte,int first_bit,int second_bit,int third_bit,int last_bit);
void convert_decimal_mask(char*first_byte,char*second_byte,char*third_byte,char*last_byte,int first_bit,int second_bit,int third_bit,int last_bit);
void reverify_mask(char*MSR);
void cat_binary(char*network,char*first_byte,char*second_byte,char*third_byte,char*last_byte);
void cat_binary_mask(char*network,char*first_byte,char*second_byte,char*third_byte,char*last_byte);
void calcul_byte(int*first_bit,char*first_byte);
void adressing_broadcast(char*network,char*IP,char*MSR);
void reconvert(char*MSR);
#endif
