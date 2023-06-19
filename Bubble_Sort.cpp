#include <iostream>
using namespace std;

void printArray(int Array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << Array[i] << " ";
    }
}

void bubbleSort(int Array[], int n)
{
    int temp;
    // Loop for each pass
    for (int i = 0; i < n; i++)
    {
        // Loop for comparison at each pass
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int A[n];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Unsorted Array: ";
    printArray(A, n);

    cout << endl << "Sorted Array: ";
    bubbleSort(A, n);
    printArray(A, n);

    return 0;
}