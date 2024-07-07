void insert(int arr[], int i)
{
    for(int j=i;j>0;--j){
        if(arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
        }
        else{
            break;
        }
    }
}
void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;++i){
        insert(arr,i);
    }
}
