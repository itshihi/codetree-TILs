#include <iostream>
using namespace std;




void heapify(int a[], int n, int idx){
    int largest = idx; // 최댓값을 갖는 노드의 인덱스
    int left_child = 2*idx;
    int right_child = 2*idx+1;

    if(n>=left_child && a[left_child]>a[largest]) largest = left_child;
    if(n>=right_child && a[right_child]>a[largest]) largest = right_child;

    // 만약 자식 노드 중 큰 값이 있다면(현재 노드가 최댓값이 아니라면) swap 후 아래로 내려가며 자식 노드 heapify
    if(largest != idx){ //
        swap(a[largest], a[idx]);
        heapify(a, n, largest);
    }

}

void heap_sort(int a[], int n){

    for(int i=n/2; i>=1; i--){
        heapify(a, n, i);
    }

    for(int i=n; i>=1; i--){
        
        swap(a[1],a[i]);
        heapify(a, i-1, 1);
    }

}

int main() {
    int n;
    int arr[n+1];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >>arr[i];
    }

    heap_sort(arr, n);

    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}