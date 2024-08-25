// Vulnerable program for Assessment 2

// Program to be compiled with one or more security features.
// exploit.py needs to be created to exploit this program vuln.c

// In the interest of focusing on the exploit and bypassing security
// features, perhaps remove the 2 x safe inputs and leave as a single bad?

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>   //needed?
//#include <unistd.h>   //needed?

// May not base the exploit on finding a hidden function.  Instead, spawn shell?
void secret(){
    printf("You found the secret!\n");
}

void data_input(){
    char firstname[64];  //remove?
    char lastname[64];   //remove?
    char age[12];
    printf("Enter your first name: ");  //remove?
    fgets(firstname, sizeof(firstname), stdin);  //remove?
    firstname[strcspn(firstname, "\n")] = '\0';  //remove?
    printf("Enter your last name: ");  //remove?
    fgets(lastname, sizeof(lastname), stdin);  //remove?
    lastname[strcspn(lastname, "\n")] = '\0';
    printf("Enter your age: ");
    gets(age);

    printf("Thankyou, %s %s; age %s",firstname, lastname, age);  //modify?
}

int main(){
    // online example - testing leaking addresses:
    void *self = dlopen(NULL, RTLD_NOW);
    // printf("stack   : %p\n", &argc);
    printf("system(): %p\n", dlsym(self, "system"));
    printf("gets(): %p\n", dlsym(self, "gets"));

    data_input();
    return 0;
}