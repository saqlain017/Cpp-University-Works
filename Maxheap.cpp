#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int Size = 0; // numbers

int L_child(int i)
{ // node k left child ka index return
    return (2 * i + 1);
}
int R_child(int i)
{ // node k right child ka index return
    return (2 * i + 2);
}
int parent(int i)
{ // node k parent ka index return
    return ((i - 1) / 2);
}

int* insert(int* arr, int val)
{ // value to be insert

    Size++;
    static int* ar = new int[Size];

    for (int j = 0; j < Size - 1; j++) {// storing all previous values in new array
        ar[j] = arr[j];
    }

    ar[Size - 1] = val;// storing new value

    for (int i = (Size - 1); i != 0 && ar[parent(i)] < ar[i];) { // i!=0--> i root node ko point nh kr rha AND child parent se greater h to swap hoga wrna nh
        swap(ar[i], ar[parent(i)]);
        i = parent(i); // it return index of parent node --> phr me usse check krnga wo sahi jaga h ya nh
    }

    return(ar);//size ko update krna h baar baar is liye size return krna zarori or inki size me store krnga main me agr aisa nh krge to size update srf function me hoga function k bahar value same rahegi (ya phr argument me size ka address pas kr k bhi kia ja sakta h phr return krne ki zarorat nh)
}

void max_heapify(int* arr, int index,int size)
{
    int left_child = L_child(index);//left child ka index
    int right_child = R_child(index);//right child ka index
    int largest = index;//jis ko neeche neeche le kar jaa rahe (e.g 9)

    if (left_child < size && arr[left_child] > arr[largest])// left child bara ho (e.g 9 se bara 75)
        largest = left_child;

    if (right_child < size && arr[right_child] > arr[largest])// right child bara ho left child se
        largest = right_child;

    if (largest != index)// agar child bara hogaya to largest men save hoga
    {
        swap(arr[index], arr[largest]);
        max_heapify(arr, largest, size);
    }
}

//void deletion(int* arr)// fazool hai
//{
//    if (Size == 0)
//    {
//        cout << "Heap is empty. Deletion not possible." << endl;
//        return;
//    }
//
//    // Replace the root node with the last element.
//    swap(arr[0], arr[Size - 1]);
//    Size--;
//
//    // Restore the max-heap property by calling max_heapify on the root node.
//    max_heapify(arr, 0, Size);
//}

void print(int* arr)
{
    for (int i = 0; i < Size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heap_sort(int *arr)
{
    if (Size == 0)// if array empty
    {
        cout << "Heap is empty." << endl;
        return;
    }

    for (int i = (Size - 1); i > 0; i--)// this loop is for deleting root node again and again
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i); // i is liye pass kia h qk size ek kam hojayega last index ko edit nh krnga me
        //step by step (debug)
        print(arr);
        cout<<endl;
        cout<<"---------------------------------"<<endl;
    }
}



int main()
{
    int* arr=NULL;
    int node = 0;
    int c;
    arr = insert(arr, 75);
    arr = insert(arr, 19);
    arr = insert(arr, 20);
    arr = insert(arr, 18);
    arr = insert(arr, 85);
    arr = insert(arr, 95);
    arr = insert(arr, 55);
    arr = insert(arr, 29);
    arr = insert(arr, 17);
    arr = insert(arr, 9);
    while (node != 20) {
        cout << "1: Insert, 2: Print, 3: Heap Sort :" << endl;
        cin >> node;
        if (node == 1) {
            cin >> c;
            arr = insert(arr, c);
        }
        if (node == 2) {
            print(arr);
        }
        if (node == 3) {
            heap_sort(arr);
        }
    }
}
