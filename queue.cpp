#include <iostream>
using namespace std;
/*
 * implement queue using linked list
 * enqueue from the back and dequeue from the front
 * both must be operated with time complexity O(1)
 */
struct Node {
	int data;
	Node* next;
	Node(int x): data(x), next(NULL) {}
};

class Queue {
public:
	Node* front;
	Node* rear;
	Queue() {
		front = rear = NULL;
	}
	void enqueue(int i) {
		Node* n = new Node(i);
		n->next = NULL;
		if(!front && !rear) front = rear = n;
		else {
			rear->next = n;
			rear = n;
		}
	}
	
	void dequeue() {
		front = front->next;
	}
	
	void display() {
		if(!front && !rear) cout << "empty queue";
		else {
			Node* tmp = front;
			while(tmp) {
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
		}
	}
	
	void peek() {
		cout << front->data;
	}
};

int main() {
	Queue q;
    q.enqueue(5);
    q.enqueue(0);
    q.enqueue(-3);
    q.display();
    q.dequeue();
    q.peek();
    return 0;
}
