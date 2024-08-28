#include <stdio.h>
#include <string.h>
#include <unistd.h>

void add_gadgets() {
    asm("pop %rdi; ret;");
}

// void secret(char *pass) {
//     printf("Password is: %s\n",pass);
//     char *str = "Test";
//     write(1, str, strlen(str));
// }

void data_input(){
    char buf[64];
    printf("buffer:");
    fflush(stdout);
    gets(buf);
    //secret(buf);
}

int main(){
  add_gadgets();
    data_input();
    return 0;
}