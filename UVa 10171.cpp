#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  while (scanf("%d", &n) && n) {
    int y[26][26], o[26][26];
    for (int a = 0; a < 26; a++) {
      for (int b = 0; b < 26; b++) {
        y[a][b] = o[a][b] = 1e7;
      }
    }
    for (int a = 0; a < 26; a++) {
      y[a][a] = o[a][a] = 0;
    }
    for (int i = 0; i < n; i++) {
      char age[9], dir[9], X[9], Y[9];
      int d;
      scanf("%s%s%s%s%d", age, dir, X, Y, &d);
      int a = *X - 'A', b = *Y - 'A';
      if (*dir == 'B') {
        if (*age == 'Y') {
          y[a][b] = min(y[a][b], d);
          y[b][a] = min(y[b][a], d);
        } else {
          o[a][b] = min(o[a][b], d);
          o[b][a] = min(o[b][a], d);
        }
      } else {
        if (*age == 'Y') {
          y[a][b] = min(y[a][b], d);
        } else {
          o[a][b] = min(o[a][b], d);
        }
      }
    }
    for (int k = 0; k < 26; k++) {
      for (int a = 0; a < 26; a++) {
        for (int b = 0; b < 26; b++) {
          y[a][b] = min(y[a][b], y[a][k] + y[k][b]);
          o[a][b] = min(o[a][b], o[a][k] + o[k][b]);
        }
      }
    }
    char X[9], Y[9];
    scanf("%s%s", X, Y);
    int a = *X - 'A', b = *Y - 'A', ans = 1e7;
    for (int meet = 0; meet < 26; meet++) {
      ans = min(ans, y[a][meet] + o[b][meet]);
    }
    if (ans == 1e7) {
      puts("You will never meet.");
    } else {
      printf("%d", ans);
      for (int meet = 0; meet < 26; meet++) {
        if (y[a][meet] + o[b][meet] == ans) {
          printf(" %c", meet + 'A');
        }
      }
      puts("");
    }
  }
  return 0;
}
