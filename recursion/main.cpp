#include<iostream>
#include<vector>
using namespace std;


struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


//hypothesis is that heightOfTree(node) will return the height of the node from bottom   
int heightOfTree(node* root){
    // base condition
    if(root == NULL) return 0;

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    
    // induction
    return max(left, right) + 1;
}

int factorial(int n){
    // base condition
    if(n == 1 || n == 0) return 1;
    //hypothesis
    return n * factorial(n-1);
}

int fibonacci(int n){
    if(n == 0 || n == 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// * hypothesis is that insert(val, arr) will add the val at the correct posistion
// if there is no element in the array it will add the val in a arr and return
// if the value is larger than the last element of the array it will be added at the end
vector<int> insertElement(int val, vector<int> &arr){
    if(arr.size() == 0 || val> arr.back()){
        arr.push_back(val);
        return arr;
    }
    // ! induction is i will remove all the elements from back 
    // ! until the val is greater than the last element of the array 
    // ! or is the only element 
    // * making it the right position 
    int temp = arr.back();
    arr.pop_back();

    insertElement(val, arr);

    arr.push_back(temp);
    return arr;
}

// * hypothesis is that sort(arr) will return sorted array.
// if we decrease the length of the arr to 1 then it will return sorted array
vector<int> sortArray(vector<int> &arr){
    // base condition
    if(arr.size() == 1) return arr;
    
    int temp = arr.back();
    arr.pop_back();
    sortArray(arr);

    return insertElement(temp, arr);
}
int main(){
    vector<int> arr = {2,1,3,5,4};
    // int n;
    // cin>>n;
    // cout<<factorial(n)<<endl;
    // cout<<fibonacci(n);
    vector<int> result = sortArray(arr);
    for(auto i : result) cout<<i<<" ";
    return 0;
}