/*
 * Implementation of a simple set data structure in C++
 */

#include <iostream>
#include <vector>
#include <algorithm>

class SimpleSet {
public:
    // Adds an element to the set
    void add(int element) {
        if (!contains(element)) {
            elements.push_back(element);
        }
    }

    // Removes an element from the set
    void remove(int element) {
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }

    // Checks if the set contains an element
    bool contains(int element) const {
        return std::find(elements.begin(), elements.end(), element) != elements.end();
    }

    // Displays the elements of the set
    void display() const {
        std::cout << "Set elements: ";
        for (int elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> elements;  // Container for set elements
};

int main() {
    SimpleSet mySet;

    mySet.add(5);
    mySet.add(10);
    mySet.add(15);
    mySet.display();

    mySet.remove(10);
    mySet.display();

    std::cout << "Contains 5? " << (mySet.contains(5) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 10? " << (mySet.contains(10) ? "Yes" : "No") << std::endl;

    return 0;
}