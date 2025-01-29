
#include <stdio.h>

int linear_search(int data[], int data_len, int val){
    for(int i=0; i<data_len; i++){
        if(data[i] == val){
            return i;
        }
    }
    return -1;
}