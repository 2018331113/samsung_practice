#include<iostream>

using namespace std;

int binarySearch(int arr[], int target, int n){
    int start = 0;
    int end = n -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    return -1;
}

int minmaxElementFromRotatedArray(int arr[], int n, bool isMax){
    int start = 0;
    int end = n-1;
    //assuming there will be atleast 2 elements
    if(n<3){
        if(isMax){
            return max(arr[0], arr[1]);
        }
        return min(arr[0], arr[1]);
    }
    while(start<=end){
        int mid = (start+end)/2;
        if(isMax){
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }else{
            if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
                return mid;
            }
            else if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
    }

    return -1;
    
    
}

int floorOfArray(int arr[], int n, int target){
    int start = 0;
    int end = n-1;
    int floor = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==target){
            return arr[mid];
        }
        else if(arr[mid]<target){
            start = mid+1;
            floor = mid;
        }
        else{
            end = mid-1;
        }
    }

    return floor;
}


int main(){
    int arr[] = {1, 2, 3, 4,  6, 7, 8};
    int target = 5;
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = floorOfArray(arr, size, target);
    cout<<ans<<endl;
    return 0;
}