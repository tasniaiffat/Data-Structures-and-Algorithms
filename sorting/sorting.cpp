#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define range 100


int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i==(n-1))cout<<endl;
        else cout<<' ';
    }
}
void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}

void bubbleSort(int arr[],int n){
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped=false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false)break;
    }
}//n^2,inplace,stable

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        if(minindex!=i){
            swap(arr[i],arr[minindex]);
        }
    }
}

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int key = i;
        int j=i;

        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }

}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (leftArr[i]  <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l, int r){
    
  int m;
  if(l<r){
    m=(l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    
    merge(arr,l,m,r);
  }
  else return;
}

int hoare_partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
 
    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);
 
        // If two pointers met.
        if (i >= j)
            return j;
 
        swap(arr[i], arr[j]);
    }
}

// int hoare_partition(int arr[],int low,int high){

//     int pivot = arr[low];
//     int i = low-1, j = high+1;
//     while(1){
//         do{
//             i++;
//         }while(arr[i]< pivot);

//         do{
//             j--;
//         }while(arr[j]>pivot);

//         //if(i>=j) return j;
//         swap(&arr[i],&arr[j]);
//         if(i>=j) return j;
//     }
// }


int partition(int arr[], int low, int high)
{

   int pivot = arr[high];
   int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
  int pi;
  if (low < high)
  {
    pi = hoare_partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}


int main(){
    fastio
    int arr[]={64,34,25,12,22,11,90};
    int n=sizeof(arr)/sizeof(arr[0]);

    //bubbleSort(arr,n);
    //selectionSort(arr,n);
    //insertionSort(arr,n);

    // int l=0,r=n-1;
    // mergeSort(arr,l,r);

    int lo=0,hi=n-1;
    //quickSort(arr,lo,hi);//hoare partition not fixed yet

    printArr(arr,n);
    return 0;
}