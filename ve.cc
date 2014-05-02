#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main(void) {

    vector<vector<int> > a;
    vector<int> sc;
    int b, n, k, q, score;
    cout << "Enter n,k,q: ";
    cin >> n >> k >> q;

    for (int i = 0; i < q; ++i) {
        vector<int> vec;
        cout << "Enter numbers: ";
        for (int j = 0; j < k; ++j) {
            cin >> b;
            vec.push_back(b);
        }
        cout << "Enter score: ";
        cin >> score;
        sc.push_back(score);
        a.push_back(vec);
    }

    for (int l = 0; l < q; ++l) {
        cout << "[ ";
        for (int m = 0; m < k; ++m) {
            cout << a[l][m] << " ";
        }
        cout << "]\n";
    }
    for (int m = 0; m < k; m++) {
        int tem = 0, t = 0;
        int tcount, c = 1;
        int rep = 0;
        vector<int> junk;
        for (int i = 0; i < q; i++) {
            if (sc[i] == 0) {
                t = a[i][m];
                junk.push_back(t);
            }
        }
        for (int i = 0; i < q; i++) {
            for (int g = 0; g < junk.size(); g++) {
                tcount = 0;
                tem = a[i][m];
                tcount++;
                if (tem != junk[g]) {
                    for (int j = i + 1; j < q; j++) {
                        if (a[j][m] == tem) {
                            tcount++;
                            if (tcount > c) {
                                rep = tem;
                                c = tcount;
                            }
                        }
                    }
                }
            }
            cout << "\n Max repeating element is: \n " << rep;
        }
        return 0;
    }
}

