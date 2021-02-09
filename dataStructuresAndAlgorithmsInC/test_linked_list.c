#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//printf("A\n");

typedef struct node_s {
    int val;
    struct node_s *next;
} node_t;

node_t * new_node(int val) {
    node_t *new_node_p;
    new_node_p = (node_t *) malloc(sizeof(node_t));
    new_node_p->val = val;
    new_node_p->next = NULL;

    return new_node_p;
}

void new_tail(node_t *node_p, int val) {
    int i;
    node_t *cur_node_p = node_p;


    while(cur_node_p->next != NULL) {
        cur_node_p = cur_node_p->next;
    }

    cur_node_p->next = new_node(val);
}

void new_head(node_t **node_p, int val) {
    node_t *new_node_p;
    new_node_p = new_node(val);

    new_node_p->next = *node_p;
    *node_p = new_node_p;
}

void print_linked_list(node_t *node_p) {
    while(node_p->next != NULL) {
        printf("%d\n", node_p->val);
        node_p = node_p->next;
    }
    printf("%d\n\n", node_p->val);
}

void delete_node(node_t *node_p, int node_num) { // if no node, does nothing and prints
    int i;
    node_t *prev_node_p;
    node_t *cur_node_p;
    cur_node_p = node_p;
    prev_node_p = cur_node_p;

    for(i=1; i<node_num; i++) {
        if (cur_node_p->next == NULL && i!=node_num-1) {
            printf("That node doesn't exist!");
            break;
        }
        prev_node_p = cur_node_p;
        cur_node_p = cur_node_p->next;
    }

    prev_node_p->next = cur_node_p->next;
    free(cur_node_p);
    print_linked_list(node_p);
}

void reverse_linked_list(node_t **node) {
    node_t *tmp1, *tmp2, *tmp3;
    tmp1 = *node;
    tmp2 = NULL;
    tmp3 = NULL;

    while(tmp1->next != NULL) {
        tmp2 = tmp1;
        tmp1 = tmp1->next;
        if(tmp2 != NULL) {
            tmp2->next = tmp3;
        }
        tmp3 = tmp2;
    }
    tmp1->next = tmp2;

    *node = tmp1;
    return;
}


int main(int argc, char** argv) {
    node_t *node_p = new_node(55);
    print_linked_list(node_p);
    new_head(&node_p, 44);
    print_linked_list(node_p);
    new_head(&node_p, 33);
    print_linked_list(node_p);
    new_tail(node_p, 66);
    print_linked_list(node_p);
    new_tail(node_p, 77);
    print_linked_list(node_p);
    new_head(&node_p, 123456);
    print_linked_list(node_p);
    new_head(&node_p, 22);
    print_linked_list(node_p);
    delete_node(node_p, 2);
    print_linked_list(node_p);

    reverse_linked_list(&node_p);
    print_linked_list(node_p);


    return 0;
}
