#include <stdio.h>


//static variable
int staticFunc(int a) {
    static int x = 0;
    
    if(a > 0) {
        x++;
        return staticFunc(a-1) + x;
    }
    return 0;
}

//global variable in recursion

int main() {

     int r;
     r = staticFunc(5);
     printf("%d\n",r);

     r=staticFunc(5);
     printf("%d\n",r);

    
    return 0;
}
