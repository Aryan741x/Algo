int select(int arr[], int i,int n)
{
    int min=1e9;
    int point=i;
    for(int k=i;k<n;++k){
        if(min>arr[k]){
            min=arr[k];
            point=k;
        }
    }
    return point;
}
 
void selectionSort(int arr[], int n)
{
   for(int i=0;i<n;++i){
       int index=select(arr,i,n);
       swap(arr[i],arr[index]);
   }
}
