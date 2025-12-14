#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

int count() {
    int c = 0;
    struct node *temp = head;
    while(temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

struct node* create(int value) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void insert_begin(int value) {
    struct node *newnode = create(value);
    newnode->next = head;
    head = newnode;
}

void insert_end(int value) {
    struct node *newnode = create(value);
    if(head == NULL) {
        head = newnode;
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void insert_pos(int value, int pos) {
    int n = count();
    if(pos < 1 || pos > n + 1) {
        printf("Insertion not possible\n");
        return;
    }
    if(pos == 1) {
        insert_begin(value);
        return;
    }
    struct node *newnode = create(value);
    struct node *temp = head;
    for(int i = 1; i < pos - 1; i++)
        temp = temp->next;
    newnode->next = temp->next;
    temp->next = newnode;
}

void display() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch, pos, value;
    do {
        printf("\n1.Insert begin\n2.Insert end\n3.Insert position\n4.Display\n5.Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_begin(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_pos(value, pos);
                break;

            case 4:
                display();
                break;

            case 5:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(ch != 5);

    return 0;
}
