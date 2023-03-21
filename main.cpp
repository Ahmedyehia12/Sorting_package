#include<bits/stdc++.h>
using namespace std;
const int ch_MAX = 26;

namespace sortlib {
    template<typename T>
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
    void quickSort(T arr[], int lowerBound, int upperBound){
        if(lowerBound < upperBound){
            int location = partition(arr, lowerBound, upperBound);
            quickSort(arr, lowerBound, location -1);
            quickSort(arr, location + 1, upperBound);
        }
    }
}

    string randomString(int ch) {
        char alpha[ch_MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                              'h', 'i', 'j', 'k', 'l', 'm', 'n',
                              'o', 'p', 'q', 'r', 's', 't', 'u',
                              'v', 'w', 'x', 'y', 'z'};

        string result = "";
        for (int i = 0; i < ch; i++) {
            result = result + alpha[rand() % ch_MAX];
        }
        return result;
    }

    void generateStringArray(string arr[], int size) {
        for (int i = 0; i < size; ++i) {
            arr[i] = randomString(5);
        }
    }

    template<typename T>
    void generate_array(T arr[], int size, int low, int high) {
        if (typeid(T) == typeid(char)) {
            for (int i = 0; i < size; ++i) {
                arr[i] = rand() % 26 + 'a';
            }
        } else {
            for (int i = 0; i < size; i++) {
                T r = low + static_cast<T>(rand()) * static_cast<T>(high - low) / RAND_MAX;
                arr[i] = r;
            }
        }
    }

    template<typename T>
    void displayArray(T arr, int size) {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
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
            cout << endl;
            cout << "Time taken by selection sort: " << double(double(duration.count()) / 1000) << " milliseconds"<< endl;
        }

        template<typename T>
        void testQuickSort(T arr[], int n){
            auto start = high_resolution_clock::now();
            quickSort(arr, 0, n-1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << endl;
            cout << "Time taken by quicksort: " << double(double(duration.count()) / 1000) << " milliseconds"<< endl;
        }

    };


    using namespace sortlib;

    int main() {

    }