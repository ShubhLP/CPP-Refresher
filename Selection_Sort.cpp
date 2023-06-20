#include <iostream>
using namespace std;

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}

void selectionSort(int A[], int n)
{
    int index_of_min_element, temp;

    // Loop for passes
    for (int i = 0; i < n; i++)
    {
        index_of_min_element = i;

        // Loop for comparison at each pass
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                index_of_min_element = j; // if minimum element found, update the index
            }
        }

        // Swap the elements
        temp = A[i];
        A[i] = A[index_of_min_element];
        A[index_of_min_element] = temp;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int Array[n];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> Array[i];
    }

    cout << "Unsorted Array: ";
    printArray(Array, n);

    cout << "Sorted Array: ";
    selectionSort(Array, n);
    printArray(Array, n);
}