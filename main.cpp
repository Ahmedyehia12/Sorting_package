#include<bits/stdc++.h>
using namespace std;


namespace sortlib {
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

    using namespace std::chrono;
    using namespace sortlib;

    class Test {
    public:
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


int main() {

}