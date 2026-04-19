#ifndef PLAYERREPOSITORY_H
#define PLAYERREPOSITORY_H

#include "Player.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// ===== CLASS 3: PlayerRepository (Template Class) =====
// DESIGN PATTERN: Repository Pattern with Templates
// Implemented by: Sandile Sibeko (220115085) & Mongiwethu Ncube (221152725)

template <typename T>
class PlayerRepository {
private:
    vector<T*> items;

public:
    void add(T* item) {
        if (item != nullptr) {
            items.push_back(item);
        }
    }

    void remove(int index) {
        if (index >= 0 && index < static_cast<int>(items.size())) {
            items.erase(items.begin() + index);
        }
    }

    T* get(int index) {
        if (index >= 0 && index < static_cast<int>(items.size())) {
            return items[index];
        }
        return nullptr;
    }

    // Const version for read-only access
    const T* get(int index) const {
        if (index >= 0 && index < static_cast<int>(items.size())) {
            return items[index];
        }
        return nullptr;
    }

    int getSize() const {
        return static_cast<int>(items.size());
    }

    vector<T*> getAll() const {
        return items;
    }

    void clear() {
        items.clear();
    }

    bool isEmpty() const {
        return items.empty();
    }

    // ===== LINEAR SEARCH ALGORITHM =====
    // Time Complexity: O(n)
    // Implemented by: Keamogetse Selebano (220068905)
    int linearSearchByName(const string& name) {
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i]->getName() == name) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    // ===== BUBBLE SORT ALGORITHM =====
    // Time Complexity: O(n^2)
    // Implemented by: Ndzulamo Michelle Yingwani (220122253)
    void bubbleSortBySkill() {
        int n = static_cast<int>(items.size());
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (items[j]->getSkill() < items[j + 1]->getSkill()) {
                    swap(items[j], items[j + 1]);
                }
            }
        }
    }

    // ===== QUICK SORT ALGORITHM =====
    // Time Complexity: O(n log n) average, O(n^2) worst
    // Implemented by: Hlonipho Nersely Bila (220080694)
    void quickSortByNumber(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSortByNumber(low, pi - 1);
            quickSortByNumber(pi + 1, high);
        }
    }

    int partition(int low, int high) {
        int pivot = items[high]->getNumber();
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (items[j]->getNumber() <= pivot) {
                i++;
                swap(items[i], items[j]);
            }
        }
        swap(items[i + 1], items[high]);
        return i + 1;
    }

    // ===== BINARY SEARCH ALGORITHM =====
    // Time Complexity: O(log n)
    // Requires sorted array by number (call quickSortByNumber first)
    int binarySearchByNumber(int number) {
        int left = 0;
        int right = static_cast<int>(items.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (items[mid]->getNumber() == number) {
                return mid;
            }

            if (items[mid]->getNumber() < number) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

#endif