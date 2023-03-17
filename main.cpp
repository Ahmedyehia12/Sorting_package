#include <bits/stdc++.h>
using namespace std;
namespace sortlib {
    template <typename T>
    void BubbleSort(T *arr, int size) {
        for (int i = 0; i < size ; i++) {
            for (int j = i+1; j < size ; j++) {
                if (arr[j] < arr[i]){
                    swap( arr[i], arr[j]);
                }

            }
        }
    }
    template <typename T>
    void Merge(T arr[],int l, int r,int mid){
        T temp[r-l+1];
        int i = l;
        int j= mid+1;
        int k = 0;
        while (i <= mid && j <= r)
        {
            if (arr[i] < arr[j])
            {
                temp[k] = arr[i];
                i++;
            }
            else
            {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while (i <= mid)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        while (j <= r)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
        for (i = l; i <= r; i++)
        {
            arr[i] = temp[i-l];
        }
    }
    template <typename T>
    void MergeSort(T arr[], int l ,int r){
        int mid;
        if (l<r){
            mid=(l+r)/2;
            MergeSort(arr, l, mid);
            MergeSort(arr, mid+1, r);
            Merge(arr, l , r, mid);
        }
    }
}
template<typename T>
void generate_array(T arr[],int n){
    for(int i=0;i<n;i++){
        if(typeid(T) == typeid(char)){
            arr[i] = rand()%26 + 'a';
        }
        else
            arr[i] = rand()%1000;
    }

}
using namespace sortlib;
using namespace std::chrono;
class Test{
public:
    template <typename T>
    void test_bubbleSort(T arr[] , int n){
        auto start = high_resolution_clock::now();
        BubbleSort(arr,n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        cout<<"Time taken by bubble sort function: "<<double(double(duration.count())/1000)<<" milliseconds"<<endl;
    }
    template <typename T>
    void test_mergeSort(T arr[],int n){
        auto start = high_resolution_clock::now();
        MergeSort(arr,0,n-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        cout<<"Time taken by merge sort function: "<<double(double(duration.count())/1000)<<" milliseconds"<<endl;
    }
};
int main() {
    int arr[50000];
    generate_array(arr,50000);
    Test test;
    Test test2;
    test.test_bubbleSort(arr,50000);
    test2.test_mergeSort(arr,50000);


    return 0;
}
