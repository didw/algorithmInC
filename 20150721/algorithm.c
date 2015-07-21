#include "algorithm.h"

#include <stdio.h>

void __display(struct node *temp, int(*a)[10],
    int *row, int *col)
{
    if (temp == 0)
        return;
    ++(*row);
    __display(temp->left, a, row, col);
    a[*row][(*col)++] = temp->data;
    __display(temp->right, a, row, col);
    --(*row);
    return;
}

void display(struct node *temp)
{
    int a[10][10] = { 0, };
    int row = -1;
    int col = 0;
    int i, j;

    __display(temp, a, &row, &col);
    system("cls");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (a[i][j] != 0)
                printf("%4d", a[i][j]);
            else
                printf("%4c", ' ');
        }
        printf("\n");
    }
    getchar();
}
