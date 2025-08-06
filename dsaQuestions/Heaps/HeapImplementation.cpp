#include<iostream>
using namespace std;


class heap{
    public:
        int size;
        int arr[100];

        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int x){
            size++;

            arr[size] = x;

            int index = size - 1;

            while(index > 1){
                int parent = index / 2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    break;
                }
            }
        }

        int delete(){
            arr[1] = arr[size];

            size--;

            int index = 1;
            while(index <= size){
                int largest = i;
                int left = 2*i;
                int right = 2*i + 1;

                if(left <= size && arr[largest] < arr[left]){
                    largest = left;
                }
                if(right <= size && arr[largest] < arr[right]){
                    largest = right;
                }
                if(largest != index){
                    swap(arr[largest], arr[index]);
                    index = largest;
                }
                else{
                    break;
                }
            }
        } 
        void heapify(int arr[], int i, int n){
            while(index <= size){
                int largest = i;
                int left = 2*i;
                int right = 2*i + 1;

                if(left <= n && arr[largest] < arr[left]){
                    largest = left;
                }
                if(right <= n && arr[largest] < arr[right]){
                    largest = right;
                }
                if(largest != index){
                    swap(arr[largest], arr[index]);
                    heapify(arr, largest, n);
                }
                else{
                    break;
                }
        }  
        void buildMaxHeap(int arr[], int n){
            for(int i = n/2 -1; i >= 0; i--){
                heapify(arr, i , n);
            }
        } 

        void heapSort(int arr[], int n){
            for(int i = n/2 -1; i >= 0; i--){
                heapify(arr, i , n);
            }

            int size = n;

            while(size > 1){
                swap(arr[1], arr[size]);

                size--;

                heapify(arr, size, 0);
            }
        }
};