/* Example code for Software Systems at Olin College.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node EmptyNode;

Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}

void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(Node **head) {
    int retval;
    Node *next_node;
    Node *first;

    

    if (*head == NULL) {
        return -1;
    }

    first = *head;
    next_node = (first)->next;
    retval = (first)->val;
    free(first);
    *head = next_node;

    return retval;
}

// Add a new element to the beginning of the list.
void push(Node **head, int val) {
    Node *node1 = make_node(val,*head);
    *head = node1;
}

// Remove the first element with the given value; return the number
// of nodes removed.
int remove_by_value(Node **head, int sVal) {
    if (*head == NULL) {
        return 0;
    } else if ((*head)->val == sVal) {
    	**head = *(*head)->next;
    	return 1;
    } else {
    	Node *next_node;
    	next_node = (*head)->next;
    	return remove_by_value(&next_node, sVal);
    }
}

// Remove the first element with the given value; return the number
// of nodes removed.
int remove_by_value2(Node **head, int sVal) {
	Node *prev = NULL;
    Node *current = *head;
    while (current != NULL){
        if (current->val == sVal){
        	if (prev == NULL) {
        		*head = current->next;
        	} else if (current->next != NULL){
                prev->next = current->next;
                prev = current;
                current = current->next;
            }
            else {
                prev->next = NULL;
                
            }
            return 1;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    return 0;
}

// Reverse the elements of the list without allocating new nodes.
void reverse(Node **head) {
    Node *prev = NULL;
    Node *current = *head;
    Node *next;

    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}


int main() {
    Node *test_list = make_node(1, NULL);
    test_list->next = make_node(2, NULL);
    test_list->next->next = make_node(3, NULL);
    test_list->next->next->next = make_node(4, NULL);
    test_list->next->next->next->next = make_node(5, NULL);
    test_list->next->next->next->next->next = make_node(6, NULL);
    test_list->next->next->next->next->next->next = make_node(7, NULL);
    test_list->next->next->next->next->next->next->next = make_node(8, NULL);

    int retval = pop(&test_list);
    //print_list(test_list);

    push(&test_list, retval+10);

    //remove_by_value(&test_list, 3);

    int x = remove_by_value2(&test_list, 7);
    printf("%d\n\n", x);
    print_list(test_list);

    int y = remove_by_value2(&test_list, 3);
    printf("\n\n%d\n\n", y);
    print_list(test_list);

    int z = remove_by_value2(&test_list, 11);
    printf("\n\n%d\n\n", z);


    reverse(&test_list);

    print_list(test_list);
}