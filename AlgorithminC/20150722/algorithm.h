#ifndef ALGORITHM_H_
#define ALGORITHM_H_
// 헤더파일의 중복 포함을 막기위한 매크로 기법 : include guard ; #pragma once
// Objective C / Java / C# : import 키워드는 중복 방지 기능을 포함하고 있다.

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#define sleep(x) Sleep((x) * 1000)
#else
#include <unistd.h>
#endif

static clock_t start;
static clock_t end;

static void start_timer()
{
    printf(">> start_timer\n");
    start = clock();
}

static void end_timer()
{
    end = clock();
    printf(">> elapsed : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}

static void swap(int* a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void print_array(int* data, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%5d", data[i]);
        if ((i + 1) % 10 == 0)
            putchar('\n');
    }
}

static int* random_data_100;
static int* random_data_10000;
static int* random_data_100000;
static int* random_data_1000000;
static int* random_data_10000000;

static int* sorted_data_100;
static int* sorted_data_10000;
static int* sorted_data_100000;
static int* sorted_data_1000000;
static int* sorted_data_10000000;

static int* reverse_data_100;
static int* reverse_data_10000;
static int* reverse_data_100000;
static int* reverse_data_1000000;
static int* reverse_data_10000000;



static void prepare_sorted_data(int* data, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        data[i] = i + 1;
    }
}

static void prepare_random_data(int* data, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        data[i] = rand() % n;
    }
}

static void prepare_reverse_data(int* data, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        data[i] = n - i;
    }
}


static void prepare_sample_datas()
{
    srand((unsigned int)time(0));

    sorted_data_100 = (int*)malloc(sizeof(int) * 100);
    sorted_data_10000 = (int*)malloc(sizeof(int) * 10000);
    sorted_data_100000 = (int*)malloc(sizeof(int) * 100000);
    sorted_data_1000000 = (int*)malloc(sizeof(int) * 1000000);
    sorted_data_10000000 = (int*)malloc(sizeof(int) * 10000000);



    random_data_100 = (int*)malloc(sizeof(int) * 100);
    random_data_10000 = (int*)malloc(sizeof(int) * 10000);
    random_data_100000 = (int*)malloc(sizeof(int) * 100000);
    random_data_1000000 = (int*)malloc(sizeof(int) * 1000000);
    random_data_10000000 = (int*)malloc(sizeof(int) * 10000000);


    reverse_data_100 = (int*)malloc(sizeof(int) * 100);
    reverse_data_10000 = (int*)malloc(sizeof(int) * 10000);
    reverse_data_100000 = (int*)malloc(sizeof(int) * 100000);
    reverse_data_1000000 = (int*)malloc(sizeof(int) * 1000000);
    reverse_data_10000000 = (int*)malloc(sizeof(int) * 10000000);


    prepare_sorted_data(sorted_data_100, 100);
    prepare_sorted_data(sorted_data_10000, 10000);
    prepare_sorted_data(sorted_data_100000, 100000);
    prepare_sorted_data(sorted_data_1000000, 1000000);
    prepare_sorted_data(sorted_data_10000000, 10000000);


    prepare_random_data(random_data_100, 100);
    prepare_random_data(random_data_10000, 10000);
    prepare_random_data(random_data_100000, 100000);
    prepare_random_data(random_data_1000000, 1000000);
    prepare_random_data(random_data_10000000, 10000000);

    prepare_reverse_data(reverse_data_100, 100);
    prepare_reverse_data(reverse_data_10000, 10000);
    prepare_reverse_data(reverse_data_100000, 100000);
    prepare_reverse_data(reverse_data_1000000, 1000000);
    prepare_reverse_data(reverse_data_10000000, 10000000);

}

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void __display(struct node *temp, int(*a)[10],
    int *row, int *col);
void display(struct node *temp);

#endif