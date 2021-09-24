#include <algorithm>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

int compute_closest_to_zero(vector<int> ts) {
  // Write your code here
  // To debug: cerr << "Debug messages..." << endl;
  if (ts.size() == 0) {
    return 0;
  }
  int ans = ts.front();
  for (auto it = ts.begin(); it != ts.end(); ++it) {
    if (abs(*it) < abs(ans)) {
      ans = *it;
    } else if (abs(*it) == abs(ans)) {
      ans = max(*it, ans);
    }
  }
  return ans;
}

/* Ignore and do not change the code below */
#pragma region
int main() {
  int n;
  cin >> n;
  cin.ignore();
  vector<int> ts{15, -7, 9, 14, 7, 12};
  // vector<int> ts{7, 5, 9, 1, 4};
  for (int i = 0; i < n; i++) {
    int ts_tmp;
    cin >> ts_tmp;
    ts.push_back(ts_tmp);
  }
  int std_out_fd = dup(1);
  dup2(2, 1);
  int solution = compute_closest_to_zero(ts);
  dup2(std_out_fd, 1);
  cout << solution << endl;

  return 0;
}
#pragma endregion
