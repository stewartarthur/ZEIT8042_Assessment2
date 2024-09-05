#include <stdio.h>
#include <string.h>
#define STDIN 0

// program stage one, leak the canary to continue the exploit
void canaryLeak() {
    char buf[64];
    scanf("%s", buf);
    printf(buf);
}

void getShell() {
    char buf[64];
    //scanf("%s", buf);
    //printf(buf);
    read(STDIN, buf, 256);
}

int main(int argc, char* argv[]) {
    setbuf(stdout, NULL);     // unbufferred output, ready to print
    printf("canaryLeak:");    // print canaryLeak: to the terminal
    canaryLeak();             // call the function canaryLeak()
    printf("\n");             // go to a new line
    printf("getShell:");      // print getShell: to the terminal
    getShell();               // call the function getShell()
    return 0;                 // return 0 to indicate the program executued successfully
}