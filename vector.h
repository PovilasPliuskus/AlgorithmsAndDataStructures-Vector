#ifndef VECTOR_H
#define VECTOR_H

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct vector vector;
typedef struct Node Node;

struct vector {
    Node *headerNode;
};

struct Node {
    int number;
    Node *nextNode;
};

bool isEmpty(vector v);
void removeAllElements(vector *v);
void removeElementAt(vector *v, int index);
void insertElementAt(vector *v, int number, int index);
void addElement(vector *v, int number);
void setElementAt(vector *v, int number, int index);
int elementAt(vector v, int index);
void printVector(vector v);
int size(vector v);

#endif