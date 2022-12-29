#include <stdio.h>


//count sum iteratively
int sumIterat(int n) {
    int sum = 0;
    int i = 0;
    
    for(i=0; i<=n; i++) {
        sum += i;
    }
    return sum;
}

//count sum recursively
int sumRec(int n) {
    if(n == 0)
        return 0;
    else
        return n*(n+1)/2;
}


int main() {
    printf("%d, %d\n", sumRec(5), sumIterat(5));
    
    return 0;
}
