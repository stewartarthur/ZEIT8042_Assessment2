#include <stdio.h>
#include <string.h>

#define STDIN 0

void memLeak() {
    char buf[64];
    scanf("%s", buf);
    printf(buf);
}

void vulnFunc() __attribute__((optimize("-fno-stack-protector")));
void vulnFunc() {
    char buf[64];
    //read(STDIN, buf, 64);
    scanf("%s", buf);
    printf(buf);
    //gets(buf);
}

int main(int argc, char* argv[]) {

    setbuf(stdout, NULL);
    printf("echo> ");
    memLeak();
    printf("\n");
    printf("read> ");
    vulnFunc();

    printf("\ndone.\n");

    return 0;

}