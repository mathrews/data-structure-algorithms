/*
 * Implementation of a simple hash map data structure in C++
 */

#include <iostream>
#include <vector>
#include <list>
#include <utility>

class HashMap {
public:
    HashMap(size_t size) : table(size) {}

    // Inserts a key-value pair into the hash map
    void insert(int key, int value) {
        size_t index = hash(key);
        table[index].emplace_back(key, value);
    }

    // Retrieves a value by key from the hash map
    bool get(int key, int& value) const {
        size_t index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    // Removes a key-value pair from the hash map
    void remove(int key) {
        size_t index = hash(key);
        table[index].remove_if([key](const auto& pair) { return pair.first == key; });
    }

private:
    std::vector<std::list<std::pair<int, int>>> table;

    // Hash function to compute the index for a given key
    size_t hash(int key) const {
        return key % table.size();
    }
};

int main() {
    HashMap myMap(10);

    myMap.insert(1, 100);
    myMap.insert(2, 200);
    myMap.insert(3, 300);

    int value;
    if (myMap.get(2, value)) {
        std::cout << "Key 2 has value: " << value << std::endl;
    } else {
        std::cout << "Key 2 not found." << std::endl;
    }

    myMap.remove(2);
    if (myMap.get(2, value)) {
        std::cout << "Key 2 has value: " << value << std::endl;
    } else {
        std::cout << "Key 2 not found." << std::endl;
    }

    return 0;
}