#include <bits/stdc++.h>

using namespace std;

int di[] = {-1,-1,-1,0,1,1,1};
int dj[] = {-1,0,1,0,-1,0,1};
// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int max = -1000;
    for (int i = 1; i < 5; i++) {
      for (int j = 1; j < 5; j++) {
        int sum = 0;
        for (int k = 0; k < 7; k++) {
            sum += arr[i+di[k]][j+dj[k]];
        }
        if (sum > max) {
            max = sum;
        }
      }
    }
    return max;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
