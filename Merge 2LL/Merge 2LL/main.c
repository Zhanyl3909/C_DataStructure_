
//
//  Created by Dzholchieva Zhanylai on 2022/12/11.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL,*second = NULL, *third = NULL;

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

//for second Linked List
void Create2(int A[], int n) {
    struct Node *last, *tmp;
    
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    
    last = second;
    
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



void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data < q->data) {
    third=last=p;
    p = p->next;
    third->next = NULL;
    } else {
    third=last=q;
    q = q->next;
    third->next = NULL;
    }
    
    while(p && q) {
    if(p->data < q->data) {
    last->next = p;
    last = p;
    p = p->next;
    last->next = NULL;
    } else {
    last->next = q;
    last = q;
    q = q->next;
    last->next = NULL;
    }
    if(p)last->next = p;
    if(q)last->next = q;
     }

}


int main() {
    
    int A[] = {0,4,7,10,45};
    int len = (sizeof(A)/sizeof(int));
    Create(A, len);
    
    int B[] = {1,5,9,12,50,55};
    int Blen = (sizeof(B)/sizeof(int));
    Create2(B, Blen);
  
    
    Merge(first, second);
    Display(third);
    

    
    return 0;
}


