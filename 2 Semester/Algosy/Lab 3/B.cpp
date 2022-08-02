#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
void MaxHeapify(long long *arr, int i, long long n)
{
    int largest, left, right;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if ((left < n) && (arr[left] > arr[i]))
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if ((right < n) && (arr[right] > arr[largest]))
    {
        largest = right;
    }
    if (largest != i)
    {
        int var = arr[i];
        arr[i] = arr[largest];
        arr[largest] = var;
        MaxHeapify(arr, largest, n);
    }
    else
    {
        return;
    }
}
void BuildMaxHeap(long long *arr, long long n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        MaxHeapify(arr, i, n);
    }
    return;
}
void HeapSort(long long *arr, long long n)
{
    BuildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        int var = arr[i];
        arr[i] = arr[0];
        arr[0] = var;
        MaxHeapify(arr, 0, i);
    }
    return;
}
int main(int argc, char *argv[])
{
    ifstream fcin("sort.in");
    long long n;
    fcin >> n;
    long long *arr = new long long[n];
    for (int i = 0; i < n; i++)
    {
        fcin >> arr[i];
    }
    HeapSort(arr, n);
    ofstream fout("sort.out");
    for (int i = 0; i < n; i++)
    {
        fout << arr[i] << " ";
    }
    fcin.close();
    fout.close();
    return 0;
}
