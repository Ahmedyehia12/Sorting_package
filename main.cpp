///@Authors : Ahmed Yehia (20210049), Nour Muhammad (20210428), Shahd Abdel-Moamen(20211053)

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
    ///@ Author: Shahd Abdel-Moamen
    ///Time complexity: best case: O(n) worst case:O(n^2) average case: O(n^2)
    template<typename T>
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
    ///@ Author: Shahd Abdel-Moamen
    ///Time complexity: best case: O(nLog(n)) worst case:O(nLog(n)) average case: O(nLog(n))
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
    template<typename T>
    ///@ Author: Nour Muhammad
    /// time complexity: best case: O(n^2), worst case: O(n^2), average case: O(n^2)
    void selectionSort(T arr[], int size) {
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
    template<typename T>
    int partition(T arr[], int lowerBound, int upperBound){
        T pivot = arr[lowerBound];
        int start = lowerBound;
        int end = upperBound;
        while(start<end){
            while(arr[start] <= pivot){
                start++;
            }
            while(arr[end] > pivot){
                end --;
            }
            if(start < end) {
                swap(arr[start], arr[end]);
            }
        }
        swap(arr[lowerBound], arr[end]);
        return end;
    }

    template<typename T>
    ///@ Author: Nour Muhammad
    /// time complexity: best case: O(n*logn), worst case: O(n^2), average case:  O(n*logn)
    void quickSort(T arr[], int lowerBound, int upperBound){
        if(lowerBound < upperBound){
            int location = partition(arr, lowerBound, upperBound);
            quickSort(arr, lowerBound, location -1);
            quickSort(arr, location + 1, upperBound);
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
        cout<<"Time taken by insertion sort function: "<<double(double(duration.count())/1000)<<" milliseconds"<<endl;
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
        cout<<"Time taken by count sort function: "<<double(double(duration.count())/1000)<<" milliseconds"<<endl;
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
        cout<<"Time taken by shell sort function: "<<double(double(duration.count())/1000)<<" milliseconds"<<endl;
    }
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
    template<typename T>
    void testSelectionSort(T arr[], int n) {
        auto start = high_resolution_clock::now();
        selectionSort(arr, n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<' ';
        }
        cout << endl;
        cout << "Time taken by selection sort: " << double(double(duration.count()) / 1000) << " milliseconds"<< endl;
    }
    template<typename T>
    void testQuickSort(T arr[], int n){
        auto start = high_resolution_clock::now();
        quickSort(arr, 0, n-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<' ';
        }
        cout << endl;
        cout << "Time taken by quicksort: " << double(double(duration.count()) / 1000) << " milliseconds"<< endl;
    }

};

int main(){
    Test t;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    generate_array(arr,n);
    cout<<"Array before sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    cout<<endl;
    cout<<"Array after sorting: ";
    t.test_insertionSort(arr,n);
    cout<<endl;
    cout<<"Array after sorting: ";
    t.test_countSort(arr,n);
    cout<<endl;
    cout<<"Array after sorting: ";
    t.test_shellSort(arr,n);
    cout<<endl;
    cout<<"Array after sorting: ";
    t.test_bubbleSort(arr,n);
    cout<<endl;
    cout<<"Array after sorting: ";
    t.test_mergeSort(arr,n);
    cout<<endl;
    cout<<"Array after sorting: ";
    t.testSelectionSort(arr,n);
    cout<<endl;
    cout<<"Array after sorting: ";
    t.testQuickSort(arr,n);
    cout<<endl;
    return 0;



}
