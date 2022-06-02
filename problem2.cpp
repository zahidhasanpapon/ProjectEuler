#include <iostream>
using namespace std;

int main() {
  long long fib[] = {2, 0};
  int i = 0;
  long long summed = 0;

  while (fib[i] < 400000) {
    summed += fib[i];
    i = (i + 1) % 2;
    fib[i] = 4 * fib[(i + 1) % 2] + fib[i];
  }

  cout << summed << '\n';

  return 0;
}

// int main() {
//   long long fib3 = 2;
//   long long fib6 = 0;
//   long long result = 2;
//   long long summed = 0;

//   while (result < 4000000) {
//     summed += result;
//     result = (4 * fib3) + fib6;
//     fib6 = fib3;
//     fib3 = result;
//   }

//   cout << summed << '\n';

//   return 0;
// }

// int main() {
//   long long int fib1 = 1;
//   long long int fib2 = 1;
//   long long int result = 0;
//   long long int summed = 0;

//   while (result < 4000000) {
//     if ((result % 2) == 0) {
//       summed += result;
//     }

//     result = fib1 + fib2;
//     fib2 = fib1;
//     fib1 = result;
//   }

//   cout << "The result of all even numbered Fibonacci numbers less than 4m : "
//        << summed << '\n';

//   return 0;
// }