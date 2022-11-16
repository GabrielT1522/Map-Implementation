#include <iostream>
#include "Map.h"

using namespace std;
int main(){

  Map<string, string> myMap;
  cout << "myMap.size(): " << myMap.size() << endl;
  cout << "myMap.isEmpty(): " << myMap.isEmpty() << endl;
  myMap.put("Test1", "Hello");
  myMap.put("Test2", "Bye");
  cout << "myMap.size(): " << myMap.size() << endl;
  cout << "myMap.isEmpty(): " << myMap.isEmpty() << endl;
  return 0;
}