static void swap_by_idx(int arr[], int idx1, int idx2){
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

static void quick_sort_algo(int data[], int data_len){
    int pivot_idx = data_len-1;
    int swap_idx = -1;
    //check invalid data len
    if(data_len <= 1){
        return;
    }
    //run algo
    for(int i=0; i<data_len; i++){
        if(data[i] <= data[pivot_idx]){
            swap_idx++;
            if(i > swap_idx){
                swap_by_idx(data, swap_idx, i);
            }
        }
    }
    if(swap_idx > 0){
        quick_sort_algo(&data[0], swap_idx);
    }
    if((data_len-swap_idx-1) > 1){
        quick_sort_algo(&data[swap_idx+1], data_len-swap_idx-1);
    }
}


void quick_sort(int data[], int data_len){
    quick_sort_algo(data, data_len);
}