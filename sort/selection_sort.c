static void swap_by_idx(int arr[], int idx1, int idx2){
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

static int find_min_idx(int data[], int data_len){
    int min_idx = 0;
    for(int i=1; i<data_len; i++){
        if(data[min_idx]>data[i]){
            min_idx = i;
        }
    }
    return min_idx;
}

void selection_sort(int data[], int data_len){
    int min_idx = 0;
    for(int i=0; i<data_len; i++){
        min_idx = i+find_min_idx(data+i, data_len-i);
        swap_by_idx(data, i, min_idx);
    }
}