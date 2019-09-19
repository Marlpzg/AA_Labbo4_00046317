#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>

using namespace std;


void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++){
    
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int T, N;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", &N);
        int arr[N];

        for(int j = 0; j < N; j++){
            scanf("%d", &arr[j]);
        }

        int n = sizeof(arr) / sizeof(arr[0]);
        quickSort(arr, 0, n - 1);
        int currMult = 2;
        for(int i = 0; i < n; i++){

            if(arr[i] >= currMult){

                currMult+=2;
            
            }
            
        }
        printf("%d\n", currMult);

    }
    return 0;
}