#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    int app = 0, *v;
    v = new int[s.length()+1];
    v[0] = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') {
            app++;
        }
        v[i+1] = app;
    }

    return (long) app * (n / s.length()) + v[n % s.length()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
