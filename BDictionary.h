// BDictionary.h

#pragma once
#include "dictionaryADT.h"
#include "ABag.h"

template <class Key, class E>
class BDictionary : public Dictionary<Key, E> {
private:
    ABag<KVpair<Key, E>> dictionaryBag;

public:
    // Constructors, destructor, and other member functions
    BDictionary(int capacity) {
        // Initialize the bag with the specified capacity
        //dictionaryBag.setCapacity(capacity);
    }

    ~BDictionary() {
        // Destructor, if needed
    }

    // Implement the virtual functions from the Dictionary ADT

    void clear() override {
        // Clear the dictionary
        dictionaryBag.emptyBag();
    }

    bool insert(const Key& k, const E& e) override {
        // Insert a record into the dictionary
        // Return true if successful, false otherwise
        KVpair<Key, E> record(k, e);
        return dictionaryBag += record;
    }

    bool remove(const Key& k, E& rtnVal) override {
        // Remove a record from the dictionary using the key
        // Update rtnVal with the removed item
        // Return true if found and removed, false otherwise
        KVpair<Key, E> record;
        record.setKey(k);
        if (dictionaryBag.search(record)) {
            dictionaryBag.remove(record);
            rtnVal = record.value();
            return true;
        }
        return false;
    }

    bool removeAny(E& returnValue) override {
        // Remove any record from the dictionary (in this case the top record)
        // Update returnValue with the removed item
        // Return true if successful, false otherwise 
        KVpair<Key, E> record;
        if (dictionaryBag.removeTop(record)) {
            returnValue = record.value();
            return true;
        }
        return false;
    }

    bool find(const Key& k, E& returnValue) const override {
        // Find a record in the dictionary using the key
        // Update returnValue with the found item
        // Return true if found, false otherwise
        KVpair<Key, E> record;
        record.setKey(k);
        if (dictionaryBag.search(record)) {
            returnValue = record.value();
            return true;
        }
        return false;
    }

    int size() const override {
        // Get the number of records in the dictionary
        return dictionaryBag.numItems();
    }
};
