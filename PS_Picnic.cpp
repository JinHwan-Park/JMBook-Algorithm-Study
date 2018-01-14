/****************************************
문제 : 소풍 (문제 ID:PICNIC. 난이도:하)
종만북 CH 06. 무식하게풀기 155pg
*****************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n=0,m=0;
vector<vector<bool>> areFriends(10, vector<bool>(10,false));

int countPairings(vector<bool> taken) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) return 1;
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main() {
	int count;
	vector<int> numofPairs;

	cin >> count;
	numofPairs.assign(count, 0);
	areFriends.assign(10, vector<bool>(10, false)); // areFriends 벡터 false로 초기화

	for (int i = 0; i < count; i++) {
		cin >> n >> m;
		for (int j = 0; j < m; j++) {
			int friend1, friend2;
			cin >> friend1 >> friend2;
			areFriends[friend1][friend2] = areFriends[friend2][friend1] = true;
		}
		numofPairs[i] = countPairings(vector<bool>(10, false));
	}

	for (int i = 0; i < count; i++)
		cout << numofPairs[i] << endl;

	return 0;
}
