#include <bits/stdc++.h>
using namespace std;
namespace sortlib{
    template <typename T>
    ///@author: Ahmed Yehia
    /// time complexity:  best case: O(n) , worst case: O(n^2) , average case: O(n^2)
void insertionSort(T arr[],int n){
    for(int i=1,j;i<n;i++){
        int temp = arr[i];
        for(j=i;j>0&&temp<arr[j-1];j--){
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

    template <typename T>
    ///@ Author: Ahmed Yehia
    /// time complexity: O(n+k) , k is the range of the numbers
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
    ///@ Author: Ahmed Yehia
    /// time complexity:  best case: O(n) , worst case: O(n^1.5) , average case: O(n^2)
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
    void test_insertionSort(T arr[] , int n){
        auto start = high_resolution_clock::now();
        insertionSort(arr,n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        cout<<"Time taken by function: "<<double(double(duration.count())/1000)<<" milliseconds"<<endl;
    }
    template <typename T>
    void test_countSort(T arr[],int n){
        auto start = high_resolution_clock::now();
        countingSort(arr,n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        cout<<"Time taken by function: "<<double(double(duration.count())/1000)<<" milliseconds"<<endl;
    }

    template<typename T>
    void test_shellSort(T arr[],int n){
        auto start = high_resolution_clock::now();
        shellSort(arr,n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        cout<<"Time taken by function: "<<double(double(duration.count())/1000)<<" milliseconds"<<endl;
    }
};
int main(){


    int arr[50000];
    generate_array(arr,50000);
    Test test;
    test.test_countSort(arr,50000);



    return 0;



}
