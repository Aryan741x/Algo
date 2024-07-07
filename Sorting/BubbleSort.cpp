void bubbleSort(int arr[], int n) {
    for(int i=0;i<n;++i){
        bool r=false;
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                r=true;
            }
        }
        if(!r)break;
    }
}
