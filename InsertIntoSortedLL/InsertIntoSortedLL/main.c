#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first,*second,*third = NULL;


//create fucntion
void create(int A[], int n) {
    int i;
    struct Node *last, *tmp;
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

//display fucntion
void Display(struct Node *p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n\n");
}

//insert into Sorted linked list
void SortedLL(struct Node *p, int x) {
    struct Node *t, *q = NULL;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if(first == NULL) {
        first = t;
    }
    else {
        while(p && p->data < x) {
            q = p;
            p = p->next;
        }
        if(p == first) {  //if value less than first
            t->next = first;
            first = t;
        }
        else {
            t->next= q->next;
            q->next = t;
        }
       
    }
}

int main() {
    int A[] = {10,20,30,40,50};
    int len = (sizeof(A)/sizeof(int));
    
    create(A,len);
    
    SortedLL(first, 44);
    
    Display(first);
    
    return 0;
}



