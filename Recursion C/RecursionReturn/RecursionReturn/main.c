#include <stdio.h>


//recursion function 1
void fun1(int i) {
    if(i > 0) {
        printf("%d ", i-1);
        fun1(i-1);
    }
}

//reversed recursion
void fun2(int n) {
    if(n > 0) {
        fun2(n-1);
        printf("%d ", n);
    }
}

int main() {
    
    int x = 3;
    fun1(x);
    printf("\n");
    fun2(x);
    printf("\n");
    
    return 0;
}
