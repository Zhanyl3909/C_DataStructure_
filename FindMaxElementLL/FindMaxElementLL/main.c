#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL;

void create(int A[], int n) {
    int i;
    struct Node *tmp, *last;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    
    last = first;
    
    for(i=1; i<n; i++) {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->data = A[i];
        tmp->next = NULL;
        
        last->next = tmp;
        last = tmp;
    }
}

//finding max iteratively
int max(struct Node *p) {
    int m = -1;
    
    while(p!=NULL) {
        if(p->data > m)
            m = p->data;
            p = p->next;
        
    }
    return m;
}


//finding max recursively
int RecMax(struct Node *p) {
    int x = 0;
    if(p==NULL) return 0;
    
    x = RecMax(p->next);
    

    if(x > p->data)
        return x;
    else
        return p->data;
    
}

//finding max shorter code
int ShortRecMax(struct Node *p) {
    int x = 0;
    if(p==NULL) return 0;
    
    x = ShortRecMax(p->next);
    return x > p->data ? x : p->data;
    
}

int main() {

    int A[] = {34,6,3,57,23,99,0,32,54,5};
    int len = sizeof(A)/sizeof(int);
    create(A,len);
    

    printf("The MAX is %d\n\n", ShortRecMax(first));
    
    return 0;
}
