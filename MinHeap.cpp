#include <iostream>
#include <cstdlib>
using namespace std;

int HeapSize = 0;

int LeftChildIndex(int index) {
    return (2 * index + 1);
}

int RightChildIndex(int index) {
    return (2 * index + 2);
}

int ParentIndex(int index) {
    return ((index - 1) / 2);
}

void PrintHeap(int *heap) {
    for (int i = 0; i < HeapSize; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int* InsertElement(int *heap, int value) {
    HeapSize++;
    int* updatedHeap = new int[HeapSize];

    for (int i = 0; i < HeapSize - 1; i++) {
        updatedHeap[i] = heap[i];
    }

    updatedHeap[HeapSize - 1] = value;

    for (int i = (HeapSize - 1); i != 0 && updatedHeap[ParentIndex(i)] > updatedHeap[i];) {
        swap(updatedHeap[i], updatedHeap[ParentIndex(i)]);
        i = ParentIndex(i);
    }
    return updatedHeap;
}

void MinHeapify(int *heap, int index, int size) {
    int leftChild = LeftChildIndex(index);
    int rightChild = RightChildIndex(index);
    int smallest = index;
    if (leftChild < size && heap[leftChild] < heap[smallest])
        smallest = leftChild;

    if (rightChild < size && heap[rightChild] < heap[smallest])
        smallest = rightChild;

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        MinHeapify(heap, smallest, size);
    }
}

void DeleteRoot(int *heap) {
    if (HeapSize == 0) {
        cout << "Heap is empty. Deletion not possible." << endl;
        return;
    }

    swap(heap[0], heap[HeapSize - 1]);
    HeapSize--;

    MinHeapify(heap, 0, HeapSize);
}

void HeapSort(int *heap) {
    if (HeapSize == 0) {
        cout << "Heap is empty. Sorting not possible." << endl;
        return;
    }
    for (int i = (HeapSize - 1); i > 0; i--) {
        swap(heap[0], heap[i]);
        MinHeapify(heap, 0, i);
    }
}

int main() {
    int* heap = NULL;
    int choice = 0;
    int value;
    heap = InsertElement(heap, 75);
    heap = InsertElement(heap, 19);
    heap = InsertElement(heap, 20);
    heap = InsertElement(heap, 18);
    heap = InsertElement(heap, 85);
    heap = InsertElement(heap, 95);
    heap = InsertElement(heap, 55);
    heap = InsertElement(heap, 29);
    heap = InsertElement(heap, 17);
    heap = InsertElement(heap, 9);
    
    while (choice != 7) {
        cout << "1. Insert element, 2. Delete root, 3. Print heap, 4. Sort heap, 5. Exit" << endl;
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to InsertElement: ";
                cin >> value;
                heap = InsertElement(heap, value);
                break;
            case 2:
                DeleteRoot(heap);
                break;
            case 3:
                PrintHeap(heap);
                break;
            case 4:
                HeapSort(heap);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }
    delete[] heap;
    return 0;
}

