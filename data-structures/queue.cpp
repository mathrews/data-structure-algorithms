/*
 * Implementation of a simple queue data structure in C++
 */

#include <iostream>
#include <deque>

class SimpleQueue {
public:
    // Adds an element to the back of the queue
    void enqueue(int element) {
        elements.push_back(element);
    }

    // Removes an element from the front of the queue
    void dequeue() {
        if (!elements.empty()) {
            elements.pop_front();
        }
    }

    // Checks if the queue is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Displays the elements of the queue
    void display() const {
        std::cout << "Queue elements: ";
        for (int elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

private:
    std::deque<int> elements;  // Container for queue elements
};

int main() {
    SimpleQueue myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);
    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}