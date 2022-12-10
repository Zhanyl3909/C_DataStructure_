#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL;

//create function
void Create(int A[], int n) {
    struct Node *last, *tmp;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    
    last = first;
    
    for(int i=1; i<n; i++) {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = A[i];
        tmp->next = NULL;
        
        last->next = tmp;
        last = tmp;
    }
}

//display function
void Display(struct Node *p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n\n");
}

//count fucntion
int Count(struct Node *p) {
    int count = 0;
    while(p) {
        count++;
        p = p->next;
    }
    return count;
}

//Delete function
int Delete(struct Node *p, int pos) {
    int x = -1;  //returning number
    struct Node *q = NULL;
    
    if(pos < 1 || pos > Count(first))   //checking for edge
        return -1;
    
    if(pos == 1) {       //deleting first
        p = first;      //p is temporary
        x = first->data;
        first = first->next;
        free(p);   //deleting p from ll
    }
    else {
        for(int i=0; i<pos-1; i++) {
            q = p;  //p is pointing to a deleting pos, and q is before than
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
    return x;
}
    
    


int main() {
    
    int A[] = {10,20,30,40,50};
    int len = (sizeof(A)/sizeof(int));
    
    Create(A, len);
    Delete(first, 0);
    Display(first);
//    printf("len : %d ", Count(first));
    
    return 0;
}
