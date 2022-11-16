#ifndef MAP_H
#define MAP_H
#include <iostream>
using namespace std;

template <class keyType, class valType> class Entry {
public:
  keyType key;
  valType value;
};

template <class keyType, class valType> class ListNode {
public:
  Entry<keyType, valType> *entryExample;
  ListNode *next, *prev;
};

template <class keyType, class valType> class Map {
private:
  ListNode<keyType, valType> *front, *rear;
  int count;

public:
  Map() {
    count = 0;
    front = NULL;
    rear = NULL;
  };
  // Performs an insertion of "n" items from dataArray
  // into the priority queue
  Map(int *dataArray, int n) {
    count = 0;
    front = NULL;
    rear = NULL;
    for (int i = 0; i < n; i++) {
      put(dataArray[i]);
    }
  };
  ~Map(void) { cout << "\nMap has been deconstructed.\n"; };
  bool isEmpty() {
    if (size() == 0)
      return true;
    else
      return false;
  };
  int size() { return count; };
  // inserts a piece of data into the priority queue
  void put(keyType key, valType value) {
    ListNode<keyType, valType> *itr = front->next;
    while (itr->next != rear) {
      if ((itr->entryExample)->key == key) {
        (itr->entryExample)->value = value;
        return;
      }
      itr = itr->next;
    }
    // entry with the same key doesn not exist
    // new to create a new node
    Entry<keyType, valType> *newEntry = new Entry<keyType, valType>();
    newEntry->key = key;
    newEntry->value = value;

    ListNode<keyType, valType> *newNode = new ListNode<keyType, valType>();
    newNode->entryExample = newEntry;

    ListNode<keyType, valType> *lastNode = rear->prev;

    newNode->prev = lastNode;
    newNode->next = rear;
    lastNode->next = newNode;
    rear->prev = newNode;
    count++;
  };
};
#endif