#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

void traverse(Node* head) {
    while (head) {
        printf("%i", head->val);
        printf("%c", ' ');
        head = head->next;
    }
}

void insertHead(int value, Node** head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = *head;
    *head = newNode;
}

Node* getLast(Node* head) {
    Node* prev = head;
    head = head->next;
    while (head) {
        prev = head;
        head = head->next;
    }
    return prev;
}

void insertLast(int value, Node* head) {
    Node* last = getLast(head);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;
    last->next = newNode;
}

Node* get(int idx, Node* head) {
    if (idx < 0) return head;
    Node* current = head;
    for (int i = 0; current && i < idx; i++) current = current->next;
    return current;
}

int getVal(int idx, Node* head) {
    return get(idx, head)->val;
}

void insertAt(int idx, int value, Node** head) {
    if (idx == 0) {
        insertHead(value, head);
        return;
    }
    Node* curr = get(idx - 1, *head);
    Node* temp = curr->next;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = temp;
    curr->next = newNode;
}

int deleteHead(Node* head) {
    int val = head->val;
    *head = *head->next;
    return val;
}

int deleteAt(int idx, Node* head) {
    if (idx == 0) return deleteHead(head);
    Node* curr = get(idx - 1, head);
    int val = curr->next->val;
    curr->next = curr->next->next;
    return val;
}

int main() {
    Node* head = NULL;
    insertHead(1, &head);
    insertHead(10, &head);
    insertLast(100, head);
    insertAt(0, 50, &head);
    traverse(head);

    return 0;
}