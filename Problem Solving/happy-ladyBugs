#include <bits/stdc++.h>

using namespace std;
// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    int v[26];
    int underscores = 0;

    for (int i = 0; i < 26; i++) {
        v[i] = 0;
    }

    for (int i = 0; i < b.length(); i++) {
        if (b[i] == '_') {
            underscores++;
        } else {
            v[b[i] - 'A']++;
        }
    }

    if (underscores == 0) {
        if (b[0] != b[1] || b[b.length()-2] != b[b.length()-1]) {
            return "NO";
        }
        for (int i = 1; i < b.length() - 1; i++) {
            if (b[i] != b[i - 1] && b[i] != b[i + 1]) {
                return "NO";
            }
        }
    } else {
        for (int i = 0; i < 26; i++) {
            cout << v[i] << " ";
            if (v[i] == 1) {
                return "NO";
            }
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
