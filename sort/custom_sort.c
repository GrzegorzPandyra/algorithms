void insert(int *data, int data_len, int val){
    for(int i=0; i<data_len; i++){
        if(val < data[i]){
            for(int j=data_len; j>i; j--){
                data[j]=data[j-1];
            }
            data[i] = val;
            return;
        }
    }
}

void custom_sort(int data[], int data_len){
    for(int i=1; i<data_len; i++){
        insert(data, i, data[i]);
    }
}