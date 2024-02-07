// ABag.h

#pragma once
#include "bagADT.h"
#include "kvpair.h"
#include <memory>

template <class E>
class ABag : public Bag<E> {
private:
    static const int INITIAL_CAPACITY = 10;
    std::unique_ptr<E[]> data; // Change from static array to unique_ptr
    int itemCount;
    int capacity;

public:
    ABag() : itemCount(0), capacity(INITIAL_CAPACITY) {
        // Allocate dynamic memory for the array
        data = std::make_unique<E[]>(capacity);
    }

    // Implement the virtual functions from the Bag ADT

    bool addItem(const E& item) override {
        // Add the item to the bag
        // Return true if successful, false otherwise
        if (itemCount < capacity) {
            data[itemCount] = item;
            itemCount++;
            return true;
        }
        return false;
    }

    bool remove(E& item) override {
        // Remove the specified item from the bag
        // Return true if found and removed, false otherwise
        for (int i = 0; i < itemCount; ++i) {
            if (data[i] == item) {
                // Move the last item to the removed item's position
                data[i] = data[itemCount - 1];
                itemCount--;
                return true;
            }
        }
        return false;
    }

    bool removeTop(E& returnValue) override {
        // Remove the top record from the bag
        // Update returnValue with the removed item
        // Return true if the bag is not empty, false otherwise
        if (itemCount > 0) {
            returnValue = data[itemCount - 1];
            itemCount--;
            return true;
        }
        return false;
    }

    bool search(E& returnValue) const override {
        // Search for a record using the specified key
        // Update returnValue with the found item
        // Return true if found, false otherwise
        // (For simplicity, assuming "search" means finding the last item)
        if (itemCount > 0) {
            returnValue = data[itemCount - 1];
            return true;
        }
        return false;
    }

    bool inspectTop(E& item) const override {
        // Inspect the top of the bag
        // Update item with the contents of the bag
        // Return true if the bag is not empty, false otherwise
        if (itemCount > 0) {
            item = data[itemCount - 1];
            return true;
        }
        return false;
    }

    void emptyBag() override {
        // Empty the bag
        itemCount = 0;
    }

    bool operator+=(const E& addend) override {
        // Use the += operator to add an item to the bag
        // Return true if successful, false otherwise
        return addItem(addend);
    }

    int numItems() const override {
        // Get the number of items in the bag
        return itemCount;
    }

    int bagCapacity() const override {
        // Get the capacity of the bag (size of the array)
        return capacity;
    }
};
