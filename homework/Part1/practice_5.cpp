#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll get_length(ll a) {
    ll length = 0;
    while (a) {
        a /= 10;
        length++;
    }
    return length;
}

ll get_value(ll a, ll i) {
    ll value;
    value = a % (ll) pow(10, i) / pow(10, i - 1);
    return value;
}

ll toDec(ll a) {
    ll val = 0;
    for (int i = 1; i <= get_length(a); i++) {
        val += get_value(a, i) * (ll) pow(2, i - 1);
    }
    return val;
}


int main() {
    int a;
    cout << "Please enter a binary number:" << endl;
    cin >> a;
    int dec = toDec(a);
    cout << "The decade number is: " << endl;
    cout << dec;
    return 0;

}