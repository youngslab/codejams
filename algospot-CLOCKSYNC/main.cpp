#include <iostream>

#define INF 987654321

int cs[16];

int switchs[10];

int connected[10][5] = {{0, 1, 2, INF, INF},   {3, 7, 9, 11, INF},
                        {4, 10, 14, 15, INF},  {0, 4, 5, 6, 7},
                        {6, 7, 8, 10, 12},     {0, 2, 14, 15, INF},
                        {3, 14, 15, INF, INF}, {4, 5, 7, 14, 15},
                        {1, 2, 3, 4, 5},       {3, 4, 5, 9, 13}};

void revert(int sw) {
  switchs[sw]--;
  for (int i = 0; i < 5; i++) {
    int clock = connected[sw][i];
    if (clock == INF)
      continue;
    cs[clock] -= 3;
    if (cs[clock] == 0)
      cs[clock] = 12;
  }
}

void mark(int sw) {
  switchs[sw]++;
  for (int i = 0; i < 5; i++) {
    int clock = connected[sw][i];
    if (clock == INF)
      break;
    cs[clock] += 3;
    if (cs[clock] == 15) {
      cs[clock] = 3;
    }
  }
}

bool is_all_12() {
  for (int i = 0; i < 12; i++) {
    if (cs[i] != 12)
      return false;
  }
  return true;
}

int count_switch() {
  int count = 0;
  for (int i = 0; i < 10; i++) {
    count += switchs[i];
  }
  std::cout << std::endl;
  return count;
}

int min(int x, int y) { return x < y ? x : y; }

int calculate(int k) {
  if (is_all_12()) {
    return count_switch();
  }

  if (k >= 10) {
    return INF;
  }

  int result = INF;

  for (int i = 0; i < 4; i++) {
    if (i != 0)
      mark(k);

    result = min(result, calculate(k + 1));
  }
  revert(k);
  revert(k);
  revert(k);
  return result;
}

int main() {
  int c = 0;
  std::cin >> c;

  for (int i = 0; i < c; i++) {
    for (int j = 0; j < 10; j++) {
      switchs[j] = 0;
    }
    for (int j = 0; j < 16; j++) {
      std::cin >> cs[j];
    }

    int result = calculate(0);
    if (result == INF) {
      result = -1;
    }
    std::cout << result << std::endl;
  }
}
