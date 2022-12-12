#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*top = NULL;

//push function
void push(int x) {
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    
    if(t==NULL)
        printf("Stack is Full");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

//pop function
int pop( )
{
    int x = -1;
    struct Node *t;
    
    if(top == NULL) {
        printf("Stack is Empty");
    } else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

//Display function
void Display( ) {
    struct Node *p;
    p = top;
    while(p!=NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {

    push(10);
    push(20);
    push(30);

    Display();
    printf("Pop: %d\n", pop());

    return 0;
}
