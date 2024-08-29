#include <stdio.h>
#include <string.h>
#include <unistd.h>

// void add_gadgets() {
//     asm("pop %rdi; ret;");
// }
void password_check(const char *stored_pword){
    char pword[64];
    printf("Password:");
    fflush(stdout);
    gets(pword);
    if (strcmp(stored_pword, pword) == 0) {
        printf("Password is correct!\n");
    } else {
        printf("Incorrect password!\n");
    }
}

char* reverse(char *str){
    int n = strlen(str);
    char tmp;
    for (int i = 0; i < n /2; i++){
        tmp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = tmp;
    }
    return str;
}

int sumFirst10Primes() {
    // Array of the first 10 prime numbers
    int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int sum = 0;
    // Loop to calculate the sum of the primes
    for (int i = 0; i < 10; i++) {
        sum += primes[i];
    }
    return sum;  // Return the calculated sum
}

int sumOfnums(int num1,int num2, int num3){
    int add = num1 + num2 + num3;
    return add;
}

void secret(char *pass) {
    printf("Password is: %s\n",pass);
    char *str = "Test";
    write(1, str, strlen(str));
}

void data_input(){
    char buf[64];
    printf("buffer:");
    fflush(stdout);
    gets(buf);
    secret(buf);
    //Reverse string - adding this to get more ROP gadgets
    buf[strcmp(buf, "\n")] = '\0';
    char* reversed = reverse(buf);
    printf("Reversed string: %s\n",reversed);
}

int main(){
    //add_gadgets();
    //data_input();
    //int num1 = 2;
    //int num2 = 3;
    //int num3 = 5;
    //int add = sumOfnums(num1,num2, num3);
    //printf("The sum of the numbers is: %d\n",add);
    //int sum = sumFirst10Primes();
    //printf("The sum of the first 10 primes is: %d\n",sum);
    char stored_pword[] = "abc123";
    password_check(stored_pword);
    return 0;
}