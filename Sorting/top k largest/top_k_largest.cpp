#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
  To find top K largest elements we could either do couple of thing
     a. sort the array and provide largest K elements from arr[n-k-1] to arr[n-1] O(nlogn)
     b. We could use the partition technique from quick sort O(n^2) -- worst case 

  The above techniques can be used for a static array, but for a streaming data we need to rely 
  on dynamic datastructures.  Since we are looking for largest K elements, first thing which comes
  to mind is a Heap.

  We could use a min heap, such that the top of the heap is always the minimum.  As we process
  the stream we are going to add the element which is greater than the top of the heap.

  Use a min heap to find the top K largest
  Use a max heap to find the K smallest 
*/

void select_top_k(const vector<int> &arr, int k) {
    
    priority_queue<int, vector<int>, std::greater<int>> pq;
    
    for(int x:arr) {
        if(pq.size() == k) {
            if (x > pq.top()) {
                pq.pop();
                pq.push(x);
            }
        } else {
            pq.push(x);
        }
    }
    
    // print the output here
    while(!pq.empty()) {
         cout << pq.top() << " ";
         pq.pop();
    }
    
    cout << endl;
}

int main(int argc, char const *argv[])
{
    
    vector<int> jj = { 54553, 201557, 858524, 95183, 665451, 314047, 875607, 596111, 952362};
    vector<int> t1 = {1,2,3,4,5,6,7};
    vector<int> t2 = {7,6,5,4,3,2,1};
    select_top_k(jj,3);
    select_top_k(t1,3);
    select_top_k(t2,3);

    return 0;
}