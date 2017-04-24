#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>

using namespace std;

int n, i, j, maxl, r, c;
string str[100];

int main()
{

    while(cin >> n) {
        maxl = 0;
        for(i = 0; i < n; i++) {
            cin >> str[i];
            if(str[i].length() > maxl)maxl = str[i].length();
        }
        sort(str, str + n);
        maxl += 2;
        c = floor(60 / (float)maxl);
        if(c == 0)c = 1;
        r = ceil(n / (float)c);
        cout << string(60, '-') << endl;
        for(i = 0; i < r; i++) {
            for(j = 0; j < c - 1; j++) {
                if(j * r + i >= n) break;
                cout << setw(maxl) << setiosflags(ios::left) << str[j * r + i];
            }
            cout << setw(maxl - 2) << setiosflags(ios::left) << str[(c - 1)*r + i] << endl;
        }
    }
}
