#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "sort/bubble_sort.h"
#include "sort/insertion_sort.h"
#include "sort/selection_sort.h"
#include "sort/quick_sort.h"
#include "sort/heap_sort_3r_pt.h"
#include "sort/merge_sort.h"
#include "sort/custom_sort.h"
#include "search/linear_search.h"
#include "search/binary.h"
#include "datasets/dataset_1.h"
#include "datasets/dataset_2.h"
#include "datasets/dataset_3.h"
#include "datasets/dataset_4.h"
#include "datasets/dataset_5.h"
#include "datasets/dataset_6.h"
#include "datasets/dataset_7.h"
#include "datasets/dataset_8.h"
#include "datasets/dataset_9.h"
//to run
typedef void (*sorting_func)(const int dataset[], int dataset_len);
typedef int (*search_func)(const int dataset[], int dataset_len, int val);

typedef struct {
    char name[20];
    sorting_func algo;
} sort_struct;

typedef struct {
    char name[20];
    search_func algo;
} search_struct;

const search_struct searching_algos[] = {
    {"linear_search",     linear_search}
};

const sort_struct sorting_algos[] = {
        // {"bubble_sort",     bubble_sort},
    // {"insertion_sort",  insertion_sort},
    // {"selection_sort",  selection_sort},
    // {"quick_sort",      quick_sort},
    // {"merge_sort",      merge_sort},
    // {"heap_sort_3rdpt", heap_sort_3r_pt},
    // {"custom_sort", custom_sort}
};

typedef struct dataset_metadata{
    const int* ds;
    const int size;
}dataset_metadata;

struct dataset_metadata dataset_list[] = {
    {dataset_1, sizeof(dataset_1)/sizeof(dataset_1[0])},
    {dataset_2, sizeof(dataset_2)/sizeof(dataset_2[0])},
    {dataset_3, sizeof(dataset_3)/sizeof(dataset_3[0])},
    {dataset_4, sizeof(dataset_4)/sizeof(dataset_4[0])},
    {dataset_5, sizeof(dataset_5)/sizeof(dataset_5[0])},
    {dataset_6, sizeof(dataset_6)/sizeof(dataset_6[0])},
    {dataset_7, sizeof(dataset_7)/sizeof(dataset_7[0])},
    {dataset_8, sizeof(dataset_8)/sizeof(dataset_8[0])},
    {dataset_9, sizeof(dataset_9)/sizeof(dataset_9[0])}
};

void print_dataset(int ds[], int ds_len){
    printf("[ ");
    for(int i=0; i<ds_len; i++){
        printf("%d ", ds[i]);
    }
    printf("]\n");
}

bool verify_sort(int ds[], int ds_len){
    bool result = true;
    for(int i=0; i<(ds_len-1); i++){
        if(ds[i] > ds[i+1]){
            result = false;
            break;
        }
    }
    if(result){
        printf("\tPASSED\t\n");
    } else {
        printf("\tFAILED\t\n");
        print_dataset(ds, ds_len);
    }
    return result;
}

void sort_by(sort_struct sort_struct, const int dataset[], int dataset_len){
    /* setup */
    int *local_data = malloc(dataset_len*sizeof(int));
    clock_t stop_clk;
    clock_t start_clk;
    if(local_data == NULL){
        printf("\tERROR: FAILED TO ALLOCATE MEMORY\n");
        return; 
    }
    memcpy(local_data, dataset, dataset_len*sizeof(int));
    printf("\t%s", sort_struct.name);
    start_clk = clock();

    /* Tested algorithm */
    sort_struct.algo(local_data, dataset_len);
    
    /* Clean-up */
    stop_clk = clock();
    double execution_time = (double)(stop_clk - start_clk)/CLOCKS_PER_SEC;
    printf("\t%f ", execution_time);
    verify_sort(local_data, dataset_len);
    // print_dataset(local_data, dataset_len);
    free(local_data);
}

int main(int argc, char **argv){
    printf("=== Algo main ===\n\n");

    for(int j=0; j<sizeof(dataset_list)/sizeof(dataset_list[0]); j++){
        printf("\nDataset #%d of size %d\n", j+1, dataset_list[j].size);
        for(int i=0; i<sizeof(sorting_algos)/sizeof(sorting_algos[0]); i++){
            sort_by(sorting_algos[i], dataset_list[j].ds, dataset_list[j].size);
        }
    }

    assert(0  == linear_search(dataset_list[0].ds, dataset_list[0].size, 0));
    assert(1  == linear_search(dataset_list[0].ds, dataset_list[0].size, 5));
    assert(6  == linear_search(dataset_list[0].ds, dataset_list[0].size, -201));
    assert(9  == linear_search(dataset_list[0].ds, dataset_list[0].size, 66));
    assert(2  == linear_search(dataset_list[0].ds, dataset_list[0].size, -1));
    assert(-1 == linear_search(dataset_list[0].ds, dataset_list[0].size, -512));
    assert(-1 == linear_search(dataset_list[0].ds, dataset_list[0].size, 7));

    assert(0  == binary_search(dataset_list[1].ds, dataset_list[1].size, 0));
    assert(1  == binary_search(dataset_list[1].ds, dataset_list[1].size, 1));
    assert(6  == binary_search(dataset_list[1].ds, dataset_list[1].size, 6));
    assert(9  == binary_search(dataset_list[1].ds, dataset_list[1].size, 9));
    assert(12 == binary_search(dataset_list[1].ds, dataset_list[1].size, 12));
    assert(-1 == binary_search(dataset_list[1].ds, dataset_list[1].size, -512));
    assert(-1 == binary_search(dataset_list[1].ds, dataset_list[1].size, 13));

    return 0;
}