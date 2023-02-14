#include<stdio.h>
#include"vector.h"

int main()
{
    vector v;
    v.headerNode = NULL;

    vector v2;
    v2.headerNode = NULL;

    addElement(&v, 1);
    addElement(&v, 2);
    addElement(&v, 3);
    addElement(&v, 4);

    addElement(&v2, 5);
    addElement(&v2, 6);
    addElement(&v2, 7);
    addElement(&v2, 8);
    addElement(&v2, 9);

    printVector(v);
    printVector(v2);

    removeAllElements(&v);
    printVector(v);

    removeElementAt(&v2, 2);
    printVector(v2);

    insertElementAt(&v, 47, 0);
    printVector(v);

    insertElementAt(&v2, 88, 3);
    printVector(v2);

    printf("%s %d\n", "Vektoriaus v dydis:", size(v));
    printf("%s %d\n", "Vektoriaus v2 dydis:", size(v2));
}