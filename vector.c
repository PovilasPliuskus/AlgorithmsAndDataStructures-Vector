#include"vector.h"

bool isEmpty(vector v)
{
    if (v.headerNode == NULL) {
        return true;
    }
    return false;
}

void removeAllElements(vector *v)
{
    if (v->headerNode == NULL) {
        return;
    }
    else {
        Node *currentNode = v->headerNode;
        v->headerNode = NULL;

        while (currentNode != NULL) {
            Node *nextNode = currentNode->nextNode;
            free(currentNode);
            currentNode = nextNode;
        }
    }
}

void removeElementAt(vector *v, int index)
{
    int ammountOfElements = size(*v);
    if (ammountOfElements <= index || index < 0) {
        printf("%s %d\n", "Neegzistuoja joks elementas indekse", index);
        return;
    }
    else if (index == 0) {
        Node *nodeToDelete = v->headerNode;
        v->headerNode = v->headerNode->nextNode;
        free(nodeToDelete);
    }
    else {
        Node *previousNode = NULL;
        Node *currentNode = v->headerNode;
        int currentIndex = 0;
        while (currentIndex != index) {
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
            currentIndex++;
        }
        previousNode->nextNode = currentNode->nextNode;
        free(currentNode);
    }
}

void insertElementAt(vector *v, int number, int index)
{
    int ammountOfElements = size(*v);
    if (index > ammountOfElements || index < 0) {
        printf("%s %d %s\n", "Duotasis indeksas ", index, "nurodo neegzistuojanti elementa");
        return;
    }
    else {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->number = number;

        if (index == 0) {
            newNode->nextNode = NULL;
            v->headerNode = newNode;
        }
        else {
            Node *previousNode = NULL;
            Node *currentNode = v->headerNode;
            int currentIndex = 0;
            while (currentIndex != index) {
                previousNode = currentNode;
                currentNode = currentNode->nextNode;
                currentIndex++;
            }
            previousNode->nextNode = newNode;
            newNode->nextNode = currentNode;
        }
    }
}

void addElement(vector *v, int number)
{
    if (isEmpty(*v) == true) {
        v->headerNode = (Node*)malloc(sizeof(Node));
        v->headerNode->number = number;
        v->headerNode->nextNode = NULL;
    }
    else {
        Node *currentNode = v->headerNode;
        while (currentNode->nextNode != NULL) {
            currentNode = currentNode->nextNode;
        }
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->number = number;
        newNode->nextNode = NULL;
        currentNode->nextNode = newNode;
    }
}

void setElementAt(vector *v, int number, int index)
{
    int ammountOfElements = size(*v);
    if (index >= ammountOfElements || index < 0) {
        printf("%s %d\n", "Neegzistuoja joks elementas indekse", index);
        return;
    }
    else {
        Node *currentNode = v->headerNode;
        int currentIndex = 0;
        while (currentIndex != index) {
            currentNode = currentNode->nextNode;
            currentIndex++;
        }
        currentNode->number = number;
    }
}

int elementAt(vector v, int index)
{
    int ammountOfElements = size(v);
    if (index >= ammountOfElements || index < 0) {
        printf("%s %d\n", "Neegzistuoja joks elementas indekse", index);
        return 0;
    }
    else {
        Node *currentNode = v.headerNode;
        int currentIndex = 0;
        while (currentIndex != index) {
            currentNode = currentNode->nextNode;
            currentIndex++;
        }
        return currentNode->number;
    }
}

void printVector(vector v)
{
    if (v.headerNode == NULL) {
        printf("Vektorius yra tuscias\n");
        return;
    }
    while (v.headerNode != NULL) {
        printf("%d ", v.headerNode->number);
        v.headerNode = v.headerNode->nextNode;
    }
    printf("\n");
}

int size(vector v)
{
    if (v.headerNode == NULL) {
        return 0;
    }
    int ammountOfElements = 0;
    while (v.headerNode != NULL) {
        ammountOfElements++;
        v.headerNode = v.headerNode->nextNode;
    }
    return ammountOfElements;
}