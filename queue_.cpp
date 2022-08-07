#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <string>
//using namespace std;
class Queue_ {

public:
    Queue_() {
        array = (int*)malloc(100001 * sizeof(int));
        start = 0;
        size = 0;
    };
    void push_back(int tag) {
        array[start + size] = tag;
        size++;
    }
    int get_size() {
      return size;
    }
    void pop_back() {
        size--;
    }
    void pop_front() {
      start++;
      size--;
    }
    int front() {
      return array[start];
    }
    int back() {
      return array[start+size-1];
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
    int size;
    int start;
};


int main() {
  Queue_ stak1;
  int buff_size, n;
  int time_in, time_work;
  scanf("%d %d", &buff_size, &n);
  for(int i = 0; i < n; i++) {
      scanf("%d %d", &time_in, &time_work);
      if(stak1.empty()) {
        stak1.push_back(time_in + time_work);
        printf("%d\n", time_in);
      } else if(stak1.get_size() < buff_size){
        time_in = time_in > stak1.back() ? time_in : stak1.back();
        stak1.push_back(time_in + time_work);
        printf("%d\n", time_in);
      } else if(stak1.front() <= time_in) {
        stak1.pop_front();
        time_in = time_in > stak1.back() ? time_in : stak1.back();
        stak1.push_back(time_in + time_work);
        printf("%d\n", time_in);
      } else {
        printf("-1\n");
      }

  }
  return 0;
}
