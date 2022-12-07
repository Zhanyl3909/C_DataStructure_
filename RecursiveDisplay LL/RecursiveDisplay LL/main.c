#include <stdio.h>
#include <stdlib.h>

//declare a struct
struct Node {
    int data;
    struct Node *next;
}*first = 0;

//create
void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for(i=1; i<n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


void Display (struct Node *p) {
    if(p!=NULL) {
        
        printf("%d ", p->data);
        Display(p->next);
       
    }
}


int main() {
    int A[] = {2,3,0,7,1,99};
    int len = (sizeof(A)/sizeof(int));
    
    create(A,len);
    Display(first);
    
    return 0;
}
