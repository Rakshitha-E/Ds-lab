#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *stack_top = NULL;
struct node *queue_front = NULL;
struct node *queue_rear = NULL;

void push(int value) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->next = stack_top;
    stack_top = new;
}

int pop() {
    if(stack_top == NULL) return -1;
    struct node *t = stack_top;
    int v = t->data;
    stack_top = stack_top->next;
    free(t);
    return v;
}

void display_stack() {
    struct node *t = stack_top;
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void enqueue(int value) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;

    if(queue_rear == NULL) {
        queue_front = new;
        queue_rear = new;
    } else {
        queue_rear->next = new;
        queue_rear = new;
    }
}

int dequeue() {
    if(queue_front == NULL) return -1;
    struct node *t = queue_front;
    int v = t->data;
    queue_front = queue_front->next;
    if(queue_front == NULL) queue_rear = NULL;
    free(t);
    return v;
}

void display_queue() {
    struct node *t = queue_front;
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int op, val;

    while(1) {
        printf("\n1.Push\n2.Pop\n3.Display Stack\n4.Enqueue\n5.Dequeue\n6.Display Queue\n7.Exit\n");
        scanf("%d", &op);

        if(op == 7) break;

        switch(op) {
            case 1: scanf("%d", &val); push(val); break;
            case 2: printf("%d\n", pop()); break;
            case 3: display_stack(); break;
            case 4: scanf("%d", &val); enqueue(val); break;
            case 5: printf("%d\n", dequeue()); break;
            case 6: display_queue(); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

