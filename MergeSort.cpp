#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void mergeSort(int *arr, int p, int r);
void merge(int p,int q, int r);

int main(void) {
    cout<<"How many elements do you want to sort?"<<endl;
    int N;
    cin>>N;
    int arr[N];
    
    
    for (int w =0; w<N; w++) {
        cout<<"Insert element"<<endl;
        cin>>arr[w];
    }
    
    mergeSort(arr, 0, N-1);
    for(int x = 0; x < N; x++)
    {
        cout << arr[x] << " ";
    }
    return 0;
}

void merge(int *arr, int p,int q,int r){
    int n1 = q - p + 2;
    int n2 = r - q + 1;
    int first[n1];
    int second[n2];

    int a = 0;
    for(int x = p; x <= q; x++){
        first[a] = arr[x];
        a++;
    }
    first[n1-1] = 99;
    
    int b = 0;
    for(int y = q + 1; y <= r; y++){
        second[b] = arr[y];
        b++;
    }
    second[n2-1] = 99;

    int j = 0;
    int i = 0;
    for (int k = p; k <= r; k++ ) {

        if(first[j] <= second[i]) {
            arr[k] = first[j];
            j++;
        } else {
            arr[k] = second[i];
            i++;
        }
    }
}

void mergeSort(int *arr, int p, int r) {

    if(p < r){

    int q = (p + r)/2;

    mergeSort(arr, p, q);
    int mid = q + 1;
    mergeSort(arr, mid, r);
    merge(arr, p, q, r);

    }
}

