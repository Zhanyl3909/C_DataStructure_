#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL;

//creation
void create(int A[], int n) { //where n is Array length
    int i;
    struct Node *tmp, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    
    last = first;
    
    for(i=1; i<n; i++) {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = A[i];
        tmp->next = NULL;
        
        last->next = tmp;
        last = tmp;
    }
    
}

void Display(struct Node *p) {  //where p is first;
    while(p!=NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int main() {
    int A[] = {21,0,3,2002,77,3,1};
    int len = (sizeof(A)/sizeof(int));
    create(A, len);
    Display(first);
    
    return 0;
}
