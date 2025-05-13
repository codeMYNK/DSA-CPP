#include <iostream>
#include <queue>

using namespace std;

int main()
{

    priority_queue<int> pq; // maxHeap

    pq.push(2);
    pq.push(4);
    pq.push(7);
    pq.push(10);
    pq.push(1);

    cout << "The head of max heap is : " << pq.top() << endl;

    priority_queue<int, vector<int>, greater<int>> cq; // minHeap

    cq.push(28);
    cq.push(45);
    cq.push(65);
    cq.push(30);
    cq.push(7);

    cout << "The head of min heap is : " << cq.top() << endl;

    return 0;
}