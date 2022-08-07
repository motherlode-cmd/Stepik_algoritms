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
  std::string command;
  int c;
  Stack_max stak;
  int n;
  std::cin>>n;
  for(int i = 0; i < n; i++) {
    std::cin>>command;
    if(command == "push") {
      std::cin>>c;
      stak.push(c);
    } else if(command == "pop") {
      stak.pop();
    } else if(command == "max") {
      printf("%d\n", stak.maxy());
    }
  }
  return 0;
}
