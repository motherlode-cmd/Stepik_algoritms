 
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <string>
//using namespace std;


class CustomStack {

public:
    CustomStack() {
        array = (int*)malloc(100001 * sizeof(int));
        size = 0;
    };
    ~CustomStack() {
        // if(mHead != NULL) {
        //     if (mHead->mData != NULL) {
        //         free(mHead->mData);
        //     }
        //     free(mHead);
        // }
    }
    void push(int tag) {
        array[size] = (int)tag;
        size++;
    }
    void pop() {
      size--;
    }
    int top() {
      return array[size - 1];
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
};


int main() {
  std::string txt;
  std::string text = "";
  while(getline(std::cin, txt)) {
    text = text + txt;
  }
  CustomStack stak;
  //cout<<"\n["<<text<<"]";
  //printf("here");
  int i = 0;
  int ans = 1;
  while(i < text.length()) { // text[i] != '\0'
    if(stak.empty() && (text[i] == '(' || text[i] == '{' || text[i] == '[' )) {
      stak.push(i);
    } else if(stak.empty() && (text[i] == ']' || text[i] == '}' || text[i] == ')')) {
      //stak.push(i);
      ans = i + 1;
      printf("%d", ans);
      return 0;
    }
     else if(text[i] == ')' && text[stak.top()] == '(' || text[i] == ']' && text[stak.top()] == '[' || text[i] == '}' && text[stak.top()] == '{') {
      stak.pop();
    } else if(text[i] == '(' || text[i] == '{' || text[i] == '[') {
      stak.push(i);
    } else if(text[i] == ']' || text[i] == '}' || text[i] == ')'){
      //stak.push(text[i]);
      ans = i+1;
      printf("%d", ans);
      return 0;
    }
    i++;
  }
  if(stak.empty()) {
    printf("Success");
  } else {
   printf("%d", stak.top() + 1);
  }
  return 0;
}
