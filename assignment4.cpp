//write a function template for selection sort that inputs, sorts and outputs ana integer array
// and a float array

#include<iostream>
using namespace std;


template <class T> void selectionSort(T a[], int n){
    for(int i=0;i<n-1;i++){

        int min_ind=i,j=0;
        for(j=i+1;j<n;j++){
            if(a[min_ind]>a[j]){
                min_ind=j;
            }
        }

        if(min_ind!=i){
            swap(a[min_ind],a[i]);
        }
    }
}

int main(){
    cout<<"Enter number of digit";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    selectionSort(a,n);

    cout<<"sorted array: "<<endl;

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";

    }
}
