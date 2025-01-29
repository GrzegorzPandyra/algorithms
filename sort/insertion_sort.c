
static void shift_array(int arr[], int startIdx, int endIdx){
    for(int i=endIdx; i>startIdx; i--){
        arr[i]=arr[i-1];
    }
}

static void insert(int data[], int idx){
    int tmp;
    for(int i=0; i<idx; i++){
        if(data[idx]<data[i]){
            tmp = data[idx];
            shift_array(data, i, idx);
            data[i] = tmp;
        }
    }
}

void insertion_sort(int data[], int data_len){
    for(int i=1; i<data_len; i++){
        insert(data, i);
    }
}