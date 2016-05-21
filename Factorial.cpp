#include <iostream>
#include <math.h>

using namespace std;

#define MAX 200;

int result[MAX];

int result_size;

void multiply(int x){
    int carry = 0;
    for(int i = 0; i < result_size; i++){
        int prod = result[i] * x + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }
    
    while(carry){
        result[result_size] = carry % 10;
        carry = carry / 10;
        result_size++;
    }
}
void factorial(int n){
    result[0] = 1;
    result_size = 1;
    
    for(int x = 2; x <= n; x++){
        multiply(x);
    }
    
    // print in reverse order
    for(int a = result_size; 0 <= a; a--){
        cout << result[a];
    }
    cout<< endl;
}

int main(){
    int n;
    cout<<"Insert a number"<< endl;
    cin>>n;
    
    factorial(n);
}