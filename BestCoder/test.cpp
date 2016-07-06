#include <stdio.h>

int main(){
    int a[] = {1, 3, 5, 7, 9};
    int *p=a;
    p+=2;
    printf("%d\n", (*p)++);
    return 0;
}
