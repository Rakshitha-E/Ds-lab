#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

struct node* create(int value) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void insert_begin(int value) {
    struct node *newnode = create(value);
    newnode->next = head;
    head = newnode;
}

void delete_begin() {
    if (head == NULL) {
        printf("Deletion not possible\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("Deletion not possible\n");
        return;
    }

    // only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    // more than one node
    struct node *curr = head;
    while (curr->next->next != NULL)
        curr = curr->next;

    // curr->next is last node
    free(curr->next);
    curr->next = NULL;
}

int count() {
    int c = 0;
    struct node *t = head;
    while (t) {
        c++;
        t = t->next;
    }
    return c;
}

void delete_pos(int pos) {
    int n = count();
    if (pos < 1 || pos > n) {
        printf("Deletion not possible\n");
        return;
    }

    if (pos == 1) {
        delete_begin();
        return;
    }

    struct node *curr = head;
    for (int i = 1; i < pos - 1; i++)
        curr = curr->next;

    struct node *del = curr->next;
    curr->next = del->next;
    free(del);
}

void delete_key(int key) {
    if (!head) {
        printf("List empty\n");
        return;
    }

    if (head->data == key) {
        delete_begin();
        return;
    }

    struct node *curr = head;
    while (curr->next && curr->next->data != key)
        curr = curr->next;

    if (!curr->next) {
        printf("Element not found\n");
        return;
    }

    struct node *del = curr->next;
    curr->next = del->next;
    free(del);
}

void display() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct node *t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main() {
    int ch, value, pos, key;

    do {
        printf("\n1.Insert begin\n2.Delete begin\n3.Delete end\n4.Delete position\n5.Delete key\n6.Display\n7.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: scanf("%d", &value); insert_begin(value); break;
            case 2: delete_begin(); break;
            case 3: delete_end(); break;
            case 4: scanf("%d", &pos); delete_pos(pos); break;
            case 5: scanf("%d", &key); delete_key(key); break;
            case 6: display(); break;
            case 7: break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 7);

    return 0;
}
