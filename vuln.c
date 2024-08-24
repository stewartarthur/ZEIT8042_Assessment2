//Vulnerable program for Assessment 2

//Program to be compiled with one or more security features.
//exploit.py needs to be created to exploit this program vuln.c



#include <stdio.h>
#include <string.h>

void secret(){
    printf("You found the secret!\n");
}

void data_input(){
    char buf[12];
    gets(buf);
    printf("You entered: %s\n", buf);
}

int main(){
    data_input();
    return 0;
}