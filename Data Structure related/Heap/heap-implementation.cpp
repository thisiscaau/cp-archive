// binary heap implementation
#include<bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
struct heap{
    int arr[nmax];
    int n = 0;
    void insert(int x){
        n++;
        arr[n] = x;
        int child = n;
        while(child > 1 && arr[child/2]<arr[child]){
            swap(arr[child],arr[child/2]);
            child = child / 2;
        }
    }
    int pop(){
        int tmp = arr[1];
        swap(arr[n],arr[1]);
        n--;
        // pushing down
        int p = 1;
        while(arr[p]<max({arr[2*p],arr[2*p+1]})){
            // mid
            if (arr[p]>arr[2*p]&&arr[p]<arr[2*p+1]){
                swap(arr[p],arr[2*p+1]);
                p = 2*p+1;
            }
            else if (arr[p]<arr[2*p]&&arr[p]>arr[2*p+1]){
                swap(arr[p],arr[2*p]);
                p = 2*p;
            }
            else {
                // out of range
                if (arr[2*p]>arr[2*p+1]){
                    swap(arr[p],arr[2*p]);
                    p = 2*p;
                }
                else {
                    swap(arr[p],arr[2*p+1]);
                    p = 2*p+1;
                }
            }
        }
        return tmp;
    }
};
heap binary_heap;
signed main(){
    binary_heap.insert(1);
    binary_heap.insert(7);
    binary_heap.insert(3);
    binary_heap.insert(4);
    binary_heap.insert(99);
    for (int i = 1 ; i <= binary_heap.n ; i++){
        cout << binary_heap.arr[i] << " " ;
    }
}