/***************************************
���� : ������ ���� (���� ID:BOARD COVER. ���̵�:��)
������ CH 06. �����ϰ�Ǯ�� 159pg
****************************************/

#include <iostream>
#include <vector>
using namespace std;

//�־��� ĭ�� ���� �� �ִ� 4���� ���
//����� �����ϴ� �� ĭ�� ����� ��ġ (dy,dx)�� ���
// ��ǥ�� ���ó�� ������ �ȴ�
const int coverType[4][3][2] = {
	{ { 0,0 },{ 1,0 },{ 0,1 } },
	{ { 0,0 },{ 0,1 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,-1 } },
};

// board�� (y,x)�� type�� ������� ���ų�, ������ ����� ���ش�.
// detla = 1 �̸� ����, delta = -1 �̸� ������ ����� ���ش�.
// ���� ����� ����� ������ ���� ��� (������ ������ �����ų�, ��ġ�ų�, ���� ���� ���� ��) false�� ��ȯ�Ѵ�.
bool set(vector<vector<int>> &board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}

	return ok;
}

// board�� ��� �� ĭ�� ���� �� �ִ� ����� ���� ��ȯ�Ѵ�.
// board[i][j] = 1 �̹� ���� ĭ Ȥ�� ���� ĭ
// board[i][j] = 0 ���� ������ ���� ĭ
int cover(vector<vector<int>>& board) {
	// ���� ä���� ���� ĭ �� ���� ���� ���ʿ� �ִ� ĭ�� ã�´�.
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}

	// ���� ��� : ��� ĭ�� ä������ 1�� ��ȯ�Ѵ�.
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		// ���� board[y][x]�� type ���·� ���� �� ������ ��� ȣ���Ѵ�.
		if (set(board, y, x, type, 1))
			ret += cover(board);
		set(board, y, x, type, -1);
	}
	return ret;
}



int main() {
	int count;
	int dy, dx;
	char block;
	vector<int> numofResult;
	vector<vector<int>> board;

	cin >> count;
	numofResult.assign(count, 0);

	for (int i = 0; i < count; i++) {
		cin >> dy >> dx;
		board.assign(dy, vector<int>(dx, 0));
		for (int j = 0; j < dy; j++) {
			for (int k = 0; k < dx; k++) {
				cin >> block;
				switch (block) {
				case '#':
					board[j][k] = 1;
					break;
				case '.':
					board[j][k] = 0;
					break;
				default:
					cout << "�Һи��� input" << endl;
					return 0;
				}
			}
		}
		numofResult[i] = cover(board);
	}

	cout << endl;
	for (int i = 0; i < numofResult.size(); i++) {
		cout << numofResult[i] << endl;
	}
	
	return 0;
}