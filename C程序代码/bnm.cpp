#include <bits/stdc++.h>
#define maxn 1005
using namespace std;

string inv;

int main() {
	cin>>inv;
	for (int i = 0; i < inv.size(); i++) {
		inv[i] -= 5;
		if (inv[i]<'@') inv[i] += 27;
		if (inv[i] == 64) inv[i] = ' ';
		printf("%c", inv[i]);
	}
	return 0;
}
