//
//  RadixSort.cpp
//  algorithms
//
//  Created by francisc munteanu on 30/04/16.
//  Copyright © 2016 francisc munteanu. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    
    int n;
    cout<<"Insert how many numbers to sort" << endl;
    cin>>n;
    
    vector<int>arr(n);
    
    int max = 0;
    for(int i = 0; i < n; i++){
        cout<<"Insert a number" << endl;
        cin>>arr[i];
        
        if(max<arr[i]) max = arr[i];
    }
    
    // find max number of digits
    int maxDigits = 0;
    while(max){
        maxDigits++;
        max /= 10;
    }
    
    // buckets for sorting
    vector<queue<int>> buckets(10);
    
    int divide = 10;
    while(maxDigits){
        for(int i = 0; i < n; i++){
            int modResult = arr[i] % divide;
            int div = divide / 10;
            int bucketIndex = modResult / div;
            buckets[bucketIndex].push(arr[i]);
        }
        maxDigits--;
        divide *=10;
        
        // rearrange array from queue
        int x = 0;
        for(int i = 0; i < 10; i++){
            while(!buckets[i].empty()){
                arr[x] = buckets[i].front();
                buckets[i].pop();
                x++;
            }
        }
    }
    
    // print sorted elements
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}

