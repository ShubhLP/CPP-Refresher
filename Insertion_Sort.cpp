#include <iostream>
using namespace std;

void printArray(int Array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << Array[i] << " ";
    }
    cout << "\n";
}

void insertionSort(int Array[], int n)
{
    int key, j;
    // Loop for passes
    for (int i = 0; i < n; i++)
    {
        key = Array[i];
        j = i - 1;

        // Loop for each pass for comparison between elements
        while (j >= 0 && key < Array[j])
        {
            Array[j + 1] = Array[j];
            j--;
        }
        Array[j + 1] = key;
    }
}

int main()
{
    int n;
    cout << "Enter the number of Elements in the Array: ";
    cin >> n;
    int A[n];

    cout << "Enter the elements of the Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Unsorted Array: ";
    printArray(A, n);
    cout << "Sorted Array: ";
    insertionSort(A, n);
    printArray(A, n);

    return 0;
}