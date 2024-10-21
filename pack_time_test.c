//pack_time_test.c
//#define printf __mingw_printf

#include "make_struct.h"
#include <time.h>
/*
double timeTest1(struct test3 *a1){
    clock_t start = clock();
    int i;
    for (i = 0; i < 1; i++)
        initial_test3(a1);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}
double timeTest2(struct test3_pack *a2){
    clock_t start = clock();
    int i;
    for (i = 0; i < 1; i++)
        initial_test3_pack(a2);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}
*/

double timeTest1(struct test3 *a1) {
    clock_t start = clock();  
    int i;
    for (i = 0; i < 1000; i++)   
        initial_test3(a1);
    clock_t end = clock(); 
    return (double)(end - start) / CLOCKS_PER_SEC; 
}

double timeTest2(struct test3_pack *a2) {
    clock_t start = clock();  
    int i;
    for (i = 0; i < 1000; i++)   
        initial_test3_pack(a2);
    clock_t end = clock();  
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main(void){
    int i, j;
    struct test3 a1;
    initial_test3(&a1);
    output_test3(&a1);

    struct test3_pack a2;
    initial_test3_pack(&a2);
    output_test3_pack(&a2);

    printf("CLOCKS_PER_SEC=%d\n",CLOCKS_PER_SEC);
    printf("repeat 10000000 times\n");
    double temp1 = 0, temp2 = 0;
    for (i = 0; i < 1000; i++){
        temp1 += timeTest1(&a1);
        temp2 += timeTest2(&a2);
    }
    printf("nornal=%f\npack(1)=%f\n", temp1, temp2);



    printf("sizeof test1:%d\n", sizeof(struct test1));
    printf("sizeof test1_pack:%d\n", sizeof(struct test1_pack));

    printf("sizeof test2:%d\n", sizeof(struct test2));
    printf("sizeof test2_pack:%d\n", sizeof(struct test2_pack));

    printf("sizeof test3:%d\n", sizeof(a1));
    printf("sizeof test3_pack:%d\n", sizeof(a2));

    return 0;
}