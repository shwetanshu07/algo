#include <iostream>

void swap(int *arr, int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int pivotHelper(int *arr, int start, int end){
    // grabs a pivot and arranges the smaller elements to left and larger to right
    int pivot = arr[start];
    int swap_index = start;
    for(int i=start; i<end; i++){
        if(pivot > arr[i]){
            swap_index++;
            // swap the element at swap_index and i
            swap(arr, swap_index, i);
        }
    }
    // finally swap the pivot with element at swap_index
    swap(arr, start, swap_index);
    return swap_index;
}

void quickSort(int *arr, int start, int end){
    if(start>=end) return;
    int p = pivotHelper(arr, start, end);
    quickSort(arr, start, p);
    quickSort(arr, p+1, end);
}

int main(){
    int arr[] = {4, 8, 2, 1, 5, 7, 6, 3};
    int size = sizeof(arr)/sizeof(int);
    quickSort(arr, 0, size);

    std::cout<<"Sorted array: "<<std::endl;
    for(int i=0; i<size; i++) std::cout<<arr[i]<<" ";
    return 0;
}