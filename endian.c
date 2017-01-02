#include <stdio.h>

#define __DEBUG__ 666

/* The macros of printing funtions. */
#ifdef __DEBUG__
#define printINT(x) printf("%s = %d\n", #x, (x));
#define printSTR(x) printf("%s = %s\n", #x, (x));
#else
#define printINT(x)
#define printSTR(x)
#endif
/* End macros */

int main(void) {
    printf("size of char:%ld\n", sizeof(char));
    printf("size of short int:%ld\n", sizeof(short int));
    printf("size of int:%ld\n", sizeof(int));
    printf("size of double:%ld\n", sizeof(double));

    union {
        short sh;
        unsigned char ch[2];
    }un;

    un.sh = 0x0102;

    printINT(un.sh);
    printINT(un.ch[0]);
    printINT(un.ch[1]);

    if( un.ch[0] == 2 && un.ch[1] == 1) {
        printf("Little endian\n");
    } else if( un.ch[0] == 1 && un.ch[1] == 2 ) {
        printf("Big endian\n");
    } else {
        printf("ch[0]: %d, ch[1]: %d\n", un.ch[0], un.ch[1]);
    }

    return 0;
}
