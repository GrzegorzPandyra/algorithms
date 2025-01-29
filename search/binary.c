
#include <stdio.h>

int binary_search(int data[], int data_len, int val){
    if(data_len < 1){
        return -1;
    }
    int result = 0;
    int mid = data_len/2;
    if(val == data[mid]){
        result = mid;
    } else if(val < data[mid]){
        result = binary_search(&data[0], mid, val);
    } else {
        result = binary_search(&data[mid+1], data_len-1-mid, val);
        result += (result==-1)?0:mid+1;
    }
    return result;
}