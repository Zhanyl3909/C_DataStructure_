#include <stdio.h>

//recursive factorial
int recFact(int n) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    else
        return recFact(n-1) * n;
}

//iterative factorial
int iterFact(int n) {
    int f = 1;
    for(int i=1; i<=n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    
    printf("%d ", recFact(5));
    printf("%d \n", iterFact(5));
    return 0;
}
