#ifndef TREAT_IP_H
#define TREAT_IP_H
void printing(char*response); //display
void input_ip(char*string);//input the ip
void treat_ip(char*string,int*first_bit,int*second_bit,int*third_bit,int*fourth_bit,char*last);//take the ip's elements
void verify_ip(int first_bit,int second_bit,int third_bit,int fourth_bit,char last,char*class_indice); //verify if the ip is valid
#endif
