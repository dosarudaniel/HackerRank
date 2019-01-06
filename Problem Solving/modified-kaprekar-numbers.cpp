#include <bits/stdc++.h>

using namespace std;

int digits(long n) {
    int nr = 0;
    while (n > 0) {
        nr++;
        n /= 10;
    }
    return nr;
}

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    bool flag = false;
    long sq, rv, lv;
    int d;
    string r, l;

    for (int i = p; i <= q; i++) {
        sq = (long)i * i; // be aware at negatives numbers here! solved with (long)
        string sqs = to_string(sq);
        d = digits(sq);
        if (d % 2 == 1) {
            sqs.insert(0, "0");
            d++;
        }

        r = sqs.substr(d / 2, d / 2);
        l = sqs.substr(0, d / 2);
        
        rv = stoi(r);
        lv = stoi(l);
        if (rv + lv == i) {
            cout << i << " ";
            flag = true;
        }
    }

    if (flag == false) {
        cout << "INVALID RANGE";
    }

}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
