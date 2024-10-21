//make_struct.c
#define printf __mingw_printf

#include "make_struct.h"
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
/*
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
*/

void initialize_random() {
    static int initialized = 0;
    if (!initialized) {
        srand(time());
        initialized = 1;
    }
}

void initial_test1(struct test1 *a){
    initialize_random();
    strcpy(a->c, "gargerahfdavddsvsdvfr");
    a->flo = rand() % 100 /10.0;
    usleep(1);
}
void initial_test2(struct test2 *a){
    initialize_random();
    int i;
    for (i = 0; i < 20; i++){
        initial_test1(&a->a1[i]);
    }
    a->flo = rand() % 100 /10.0;
    usleep(1);
}
void initial_test3(struct test3 *a){
    initialize_random();
    initial_test2(&a->a1);
    initial_test2(&a->a2);
    a->flo1 = (long double)((rand() % 100) /10.0);
    a->flo2 = (long double)((rand() % 100) /10.0);
    usleep(1);
}

void output_test1(struct test1 *a){
    printf("test1: c=%s, flo=%.2f\n", a->c, a->flo);
}
void output_test2(struct test2 *a){
    int i;
    for (i = 0; i < 20; i++){
        output_test1(&a->a1[i]);
    }
    printf("a->a->flo=%.2Lf,\n", a->flo);
}
void output_test3(struct test3 *a){
    output_test2(&a->a1);
    printf("a->flo1=%Lf,\n", a->flo1);
    output_test2(&a->a2);
    printf("a->flo2=%Lf,\n", a->flo2);
    printf("end\n\n");
}


void initial_test1_pack(struct test1_pack *a){
    initialize_random();
    strcpy(a->c, "gargerahfdavddsvsdvfr");
    a->flo = rand() % 100 /10.0;
    usleep(1);
}
void initial_test2_pack(struct test2_pack *a){
    initialize_random();
    int i;
    for (i = 0; i < 20; i++){
        initial_test1_pack(&a->a1[i]);
    }
    a->flo = rand() % 100 /10.0;
    usleep(1);
}
void initial_test3_pack(struct test3_pack *a){
    initialize_random();
    initial_test2_pack(&a->a1);
    initial_test2_pack(&a->a2);
    a->flo1 = (long double)((rand() % 100) /10.0);
    a->flo2 = (long double)((rand() % 100) /10.0);
    usleep(1);
}

void output_test1_pack(struct test1_pack *a){
    printf("test1: c=%s, flo=%.2f\n", a->c, a->flo);
}
void output_test2_pack(struct test2_pack *a){
    int i;
    for (i = 0; i < 20; i++){
        output_test1_pack(&a->a1[i]);
    }
    printf("a->a->flo=%.2Lf,\n", a->flo);
}
void output_test3_pack(struct test3_pack *a){
    output_test2_pack(&a->a1);
    printf("a->flo1=%Lf,\n", a->flo1);
    output_test2_pack(&a->a2);
    printf("a->flo2=%Lf,\n", a->flo2);
    printf("end\n\n");
}