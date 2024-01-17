#include <bits/stdc++.h>

#include <string.h>

using namespace std;

int main(){

    int arr[] = {2,1,5,0,4,6};

    int c1 =INT_MAX;
    int c2 = INT_MAX;
    int c3 = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i< n; i++){
        if(arr[i]<=c1){
            c1 = arr[i];
        }else if(arr[i]<=c2){
            c2 = arr[i];
        }else{
            c3 = arr[i];
        }
    }

    cout<<c1<<" "<<c2<<" "<<c3;

    return 0;
}