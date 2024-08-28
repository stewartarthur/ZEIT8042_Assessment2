// Vulnerable program for Assessment 2

// NX Enabled
// 64bit compiled

#include <stdio.h>
#include <string.h>

//Unused function
void secret(){
    printf("You found the secret!\n");
}

void data_input(){
    char language[50];
    printf("buffer:");
    fflush(stdout);
    gets(language);

    //printf("Thankyou, %s %s; age %s",firstname, lastname, age);  //modify?
    //printf("You entered: %s",language);
}

int main(){
    data_input();
    return 0;
}