//Vulnerable program for Assessment 2

//Program to be compiled with one or more security features.
//exploit.py needs to be created to exploit this program vuln.c



#include <stdio.h>
#include <string.h>

void secret(){
    printf("You found the secret!\n");
}

void data_input(){
    char firstname[64];
    char lastname[64];
    char age[12];
    printf("Enter your first name: ");
    fgets(firstname, sizeof(firstname), stdin);
    firstname[strcspn(firstname, "\n")] = '\0';
    printf("Enter your last name: ");
    fgets(lastname, sizeof(lastname), stdin);
    lastname[strcspn(lastname, "\n")] = '\0';
    printf("Enter your age: ");
    gets(age);

    printf("Thankyou, %s %s; age %s",firstname, lastname, age);
}

int main(){
    data_input();
    return 0;
}