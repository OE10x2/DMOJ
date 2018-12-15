#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

char input[27];

int main(){
  scanf("%s", input);
  if (strlen(input) <= 2){
    ll number = atoi(input);
    if (number > 16){
        printf("999999998\n");
        return 0;
    }
    if (number % 2 == 0){
      ll result = 2 * (pow(10, number/2) - 1);
      printf("%lld\n", result % 1000000000);
    }else{
      ll result = pow(10, floor(number/2)) * 11 - 2;
      printf("%lld\n", result % 1000000000);
    }
  }else printf("999999998\n");
  return 0;
}
