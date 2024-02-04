// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>
using namespace std;

int N;
int ans = 0;
vector<int> rowPlacedCol;

void solution(int row)
{
	// row기준 위에서 아래로 탐색
	if (row == N)
	{
		ans++;
		return;
	}

	// col 범위
	for (int col = 0; col < N; ++col)
	{
		bool canPlace = true;
		rowPlacedCol[row] = col;

		// 진행가능(기존에 둔 퀸들) 확인
		for (int rec = 0; rec < row; ++rec)
		{
			if (rowPlacedCol[row] == rowPlacedCol[rec] || abs(rowPlacedCol[row] - rowPlacedCol[rec]) == row - rec)
			{
				canPlace = false;
				break;
			}
		}
		
		// 다음 진행
		if (canPlace)
			solution(row + 1);
	}
}

int main()
{
	cin >> N;
	rowPlacedCol.resize(N);

	solution(0);
	cout << ans;

	return 0;
}