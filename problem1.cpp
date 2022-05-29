// #include <iostream>
// using namespace std;

// int main() {
//   int limit;
//   cin >> limit;
//   int sum = 0;
//   for (int i = 3; i < limit; i++) {
//     if (i % 3 == 0 || i % 5 == 0) {
//       sum += i;
//     }
//   }
//   cout << sum << '\n';

//   return 0;
// }
#include <iostream>
using namespace std;

int sumn(int n, int d) {
  n /= d;
  return d * n * (n + 1) / 2;
}

int main() {
  int limit;
  cout << "Enter an upper bound: ";
  cin >> limit;
  int a = 3, b = 5;
  int sum = sumn(limit - 1, a) + sumn(limit - 1, b) - sumn(limit - 1, a * b);
  cout << "Sum of multiples of " << a << " or " << b << " below " << limit
       << " = " << sum << '\n';
  return 0;
}

