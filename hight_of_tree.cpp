#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <string>
//using namespace std;

int main() {
  int n;
  std::cin>>n;
  int* a = (int*)malloc(n * sizeof(int));
  for(int i = 0; i < n; i++) {
    std::cin>>a[i];
  }
  int max = 0;
  int temo = 0;
  int temp;
  for(int i = 0; i < n; i++) {
    temo = 1;
    temp = a[i];
    while(temp != -1) {
      temp = a[temp];
      temo++;
    }
    if(temo > max) {
      max = temo;
    }
  }
  printf("%d\n", max);
  return 0;
}
