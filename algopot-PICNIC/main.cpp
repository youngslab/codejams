#include <iostream>
#include <vector>

int table[10][10];
int picked[10];
int N;

int calculate(int f) {
  // base case - out of bound?
  if (f >= N)
    return 1;

  // already picked ?
  if (picked[f]) {
    return calculate(f + 1);
  }

  picked[f] = 1; // this friend have'nt been picked.

  auto result = 0;
  for (int i = f + 1; i < N; i++) {

    if (!table[f][i]) // frineds?
      continue;

    if (picked[i]) // already picked ?
      continue;

    picked[i] = 1;
    result += calculate(f + 1);
    picked[i] = 0;
  }
  picked[f] = 0;
  return result;
}

int main() {

  int c;
  std::cin >> c;
  for (int j = 0; j < c; j++) {

    // init table.
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        table[i][j] = 0;
      }
      picked[i] = false;
    }

    int m;
    std::cin >> N >> m;
    for (int i = 0; i < m; i++) {
      int a, b; // one pair of friends.
      std::cin >> a >> b;
      table[a][b] = 1;
      table[b][a] = 1;
    }

    std::cout << calculate(0) << std::endl;
  }
}
