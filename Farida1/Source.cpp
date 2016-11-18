#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

//ITERATIVE
long long iter(vector<long long>);

int main() {
	long long t, m, coin;
	vector<long long> coins;
	cin >> t;	//t - number of test cases
	cin.ignore();	//dump newline character left by cin
	int C = 1;		//test case number
	
	while (t--) {
		
		cin >> m;		//number of monsters
		coins.push_back(0);
		
		while (m--) {
			cin >> coin;
			coins.push_back(coin);
		}
		
		//Print 'Case C: X'		starting with 1 NOT 0
		cout << "Case " << C << ": " << iter(coins) << endl;	//prints the max to collect
		C++;		//increment test case number

		coins.clear();		//clear coins vector
	}
	
	return 0;
}
long long iter(vector<long long> coins) {
	vector <long long> dp;
	int n = coins.size();
	dp.resize(n, 0);
	dp[1] = coins[1];

	for (int i = 2; i < n; i++) {
		dp[i] = max(coins[i] + dp[i - 2], dp[i - 1]);
	}
	
	return dp[n-1];
}