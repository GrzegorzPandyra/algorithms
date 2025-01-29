#include <stdio.h>
#include <string.h>
#include <malloc.h>

void merge_sort(int data[], int data_len){
    if(data_len <= 1){
        return;
    }
    int split_idx = data_len/2;
    merge_sort(&data[0], split_idx);
    merge_sort(&data[split_idx], data_len-split_idx);
    int workset[data_len];
    int l_idx = 0, r_idx = split_idx;
    memcpy(workset, (int*) data, 4*data_len);
    for(int i = 0; i < data_len; i++){
        if(((workset[l_idx] < workset[r_idx]) && (l_idx < split_idx)) || (r_idx == data_len)) {
            data[i] = workset[l_idx];
            l_idx++;
        } else {
            data[i] = workset[r_idx];
            r_idx++;
        }
    }
}