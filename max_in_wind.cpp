#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <string>
//using namespace std;
class Stack_max {

public:
    Stack_max() {
        array = (int*)malloc(100001 * sizeof(int));
        max = (int*)malloc(100001 * sizeof(int));
        size = 0;
    };
    ~Stack_max() {
        // if(mHead != NULL) {
        //     if (mHead->mData != NULL) {
        //         free(mHead->mData);
        //     }
        //     free(mHead);
        // }
    }
    int maxy() {
      return max[size-1];
    }
    void push(int tag) {
        array[size] = tag;
        if(tag > max[size-1]) {
          max[size] = tag;
        } else {
          max[size] = max[size - 1];
        }
        size++;
    }
    int get_size() {
      return size;
    }
    void pop() {
         size--;
    }
    int top() {
      return array[size-1];
    }
    bool empty() {
        if (size == 0) {
            return true;
        } else {
          return false;
        }
    }

  // методы push, pop, size, empty, top + конструкторы, деструктор
private:
  // поля класса, к которым не должно быть доступа извне
protected:  // в этом блоке должен быть указатель на голову
    int* array;
    int* max;
    int size;
};


int main() {
  int n,m;
  scanf("%d", &n);
  Stack_max stak1;
  Stack_max stak2;
  int* a = (int*)malloc(n * sizeof(int));
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
  for(int i = 0; i < n; i++) {
    if(stak1.get_size() == m && stak2.get_size() == 0) {
      for(int j = 0; j < m; j++) {
        stak2.push(stak1.top());
        stak1.pop();
      }
    }
    if(stak1.get_size() + stak2.get_size() == m){
      int max = stak1.maxy() > stak2.maxy() ? stak1.maxy() : stak2.maxy();
      printf("%d ", max); 
    }
    stak1.push(a[i]);
    if(stak2.get_size() != 0) {
      stak2.pop();
    }
  }
  if(stak1.get_size() + stak2.get_size() == m){
      int max = stak1.maxy() > stak2.maxy() ? stak1.maxy() : stak2.maxy();
      printf("%d ", max); 
    }
  return 0;
}
