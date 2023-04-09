#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_node() {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    return new_node;
}
void add_pos(struct node **head, int pos) {
    struct node *new_node = create_node();
    if (pos == 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        struct node *p = *head;
        int count = 0;
        while (p != NULL && count < pos - 1) {
            p = p->next;
            count++;
        }
        if (p == NULL) {
            printf("position is not found");
        } else {
            new_node->next = p->next;
            p->next = new_node;
        }
    }
}

void add(struct node **head) {
    struct node *new_node = create_node();
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_node;
    }
}

void print(struct node *head) {
    struct node *r = head;
    while (r != NULL) {
        printf("%d ", r->data);
        r = r->next;
    }
}

void delete_node(struct node **head, int data) {
    struct node *p = *head;
    struct node *prev = NULL;

    while (p != NULL && p->data != data) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("the data is not found");
        return;
    }

    if (prev == NULL) {
        *head = p->next;
    } else {
        prev->next = p->next;
    }

    free(p);
}

void delete_node_pos(struct node **head, int pos) {
    struct node *p = *head;
    struct node *prev = NULL;
    int count = 0;

    while (p != NULL && count != pos) {
        
        prev = p;
        p = p->next;
        count++;
    }

    if (p == NULL) {
        printf("the position is not found");
        return;
    }

    if (prev == NULL) {
        *head = p->next;
    } else {
        prev->next = p->next;
    }

    free(p);
}
int main() {
    struct node *head = NULL;
    int i, n;
    printf("Enter the number of elements to add to the list: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        add(&head);
    }
    print(head);

    int m, data, pos;
    printf("\nChoose one of the following options:\n");
    printf("1. Delete a node by data.\n");
    printf("2. Delete a node by position.\n");
    printf("3. Add a node at a specific position.\n");
    scanf("%d", &m);

    if (m == 1) {
        printf("Enter the data to delete: ");
        scanf("%d", &data);
        delete_node(&head, data);
    } else if (m == 2) {
        printf("Enter the position of the node to delete: ");
        scanf("%d", &pos);
        delete_node_pos(&head, pos);
    } else if (m == 3) {
        printf("Enter the position to insert the node: ");
        scanf("%d", &pos);
        add_pos(&head, pos);
    } else {
        printf("position not found");
    }

    printf("the updated list is : ");
    print(head);

    return 0;
}

    