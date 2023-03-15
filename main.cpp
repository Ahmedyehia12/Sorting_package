#include<iostream>
#include<vector>
using namespace std;
namespace sortlib{
    template <typename T>
void insertionSort(T arr[],int n){
    for(int i=1,j;i<n;i++){
        int temp = arr[i];
        for(j=i;j>0&&temp<arr[j-1];j--){
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }}

    template <typename T>
    void countingSort (T arr[],int n){
        int max = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        vector<int>count(max+1,0);
        for(int i=0;i<n;i++){
            count[arr[i]]++;
        }
        for(int i=1;i<=max;i++){
            count[i] += count[i-1];
        }
        T result[n];
        for(int i=n-1;i>=0;i--){
            result[count[arr[i]]-1] = arr[i];
            count[arr[i]]--;
        }
        for(int i=0;i<n;i++){
            arr[i] = result[i];
        }
    }
    template<typename T>
    void shellSort(T arr[],int n){
        for(int gap = n/2;gap>0;gap/=2){
            for(int i=gap;i<n;i++){
                int temp = arr[i];
                int j;
                for(j=i;j>=gap && temp<arr[j-gap];j-=gap){
                    arr[j] = arr[j-gap];
                }
                arr[j] = temp;
            }
        }
    }
}
using namespace sortlib;
int main(){
    int arr[] = {4,1,3,4,3};
    countingSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    int arr2[] = {4,1,3,4,3};
    insertionSort(arr2,5);
    for(int i=0;i<5;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    int arr3[] = {4,1,3,4,3};
    shellSort(arr3,5);
    for(int i=0;i<5;i++){
        cout<<arr3[i]<<" ";
    }
    return 0;



}
