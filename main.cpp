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

    };


    using namespace sortlib;

    int main() {
        srand(time(NULL));
        string dataType;
        int size;
        Test test;
        cout << "Enter the type of array you want: ";
        cin >> dataType;
        cout << "Enter the size of array: ";
        cin >> size;
        if (dataType == "string") {
            string arr[size];
            generateStringArray(arr, size);
            //place the test object and call the sort algorithm you want
            displayArray(arr, size);
        } else if (dataType == "int") {
            int arr[size];
            generate_array(arr, size, 1, 1000);
            test.testSelectionSort(arr, size);
            displayArray(arr, size);
        } else if (dataType == "double") {
            double arr[size];
            srand(0);
            generate_array(arr, size, 1, 100);
            //place the test object and call the sort algorithm you want
            displayArray(arr, size);
        } else if (dataType == "float") {
            float arr[size];
            generate_array(arr, size, 1, 100);
            //place the test object and call the sort algorithm you want
            displayArray(arr, size);
        } else if (dataType == "char") {
            char arr[size];
            generate_array(arr, size, 1, 100);
            //place the test object and call the sort algorithm you want
            displayArray(arr, size);
        }
    }