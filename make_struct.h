//make_struct.h

#ifndef MAKE_STRUCT_H
#define MAKE_STRUCT_H


#include<stdio.h>



struct test1{
    char c[50];
    float flo;
};
struct test2{
    struct test1 a1[20];
    long double flo;
};
struct test3{
    struct test2 a1;
    long double flo1;
    struct test2 a2;
    long double flo2;
};

#pragma pack(1)
struct test1_pack{
    char c[50];
    float flo;
};
struct test2_pack{
    struct test1_pack a1[20];
    long double flo;
};
struct test3_pack{
    struct test2_pack a1;
    long double flo1;
    struct test2_pack a2;
    long double flo2;
};
#pragma pack()

void initial_test1(struct test1 *a);
void initial_test2(struct test2 *a);
void initial_test3(struct test3 *a);
void output_test1(struct test1 *a);
void output_test2(struct test2 *a);
void output_test3(struct test3 *a);

void initial_test1_pack(struct test1_pack *a);
void initial_test2_pack(struct test2_pack *a);
void initial_test3_pack(struct test3_pack *a);
void output_test1_pack(struct test1_pack *a);
void output_test2_pack(struct test2_pack *a);
void output_test3_pack(struct test3_pack *a);
#endif