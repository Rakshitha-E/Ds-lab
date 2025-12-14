#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create(int value) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

struct node* insert_beg(struct node *head, int value) {
    struct node *newnode = create(value);
    newnode->next = head;
    return newnode;
}

void display(struct node *head) {
    struct node *t = head;
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

struct node* reverse_list(struct node *head) {
    struct node *prev = NULL, *cur = head, *next = NULL;
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

struct node* sort_list(struct node *head) {
    if(head == NULL) return head;
    int swapped;
    struct node *ptr, *last = NULL;
    do {
        swapped = 0;
        ptr = head;
        while(ptr->next != last) {
            if(ptr->data > ptr->next->data) {
                int t = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = t;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while(swapped);
    return head;
}

struct node* concat_lists(struct node *h1, struct node *h2) {
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    struct node *t = h1;
    while(t->next != NULL)
        t = t->next;
    t->next = h2;
    return h1;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;
    int m, n, val;

    printf("Enter m and n: ");
    scanf("%d %d", &m, &n);

    printf("Enter %d elements for List 1:\n", m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &val);
        head1 = insert_beg(head1, val);
    }

    printf("Enter %d elements for List 2:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        head2 = insert_beg(head2, val);
    }

    head1 = reverse_list(head1);
    head2 = sort_list(head2);

    printf("Final concatenated list:\n");
    display(concat_lists(head1, head2));

    return 0;
}
