

void bubble_sort(int data[], int data_len){

    int swap = 0;
    for(int i=0; i<data_len; i++){
        for(int j=0; j<(data_len-i-1); j++){
            if(data[j] > data[j+1]){
                swap = data[j];
                data[j] = data[j+1];
                data[j+1] = swap;
            }
        }
    }
}