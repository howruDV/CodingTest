// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>
using namespace std;

int N;
int ans = 0;
vector<int> rowPlacedCol;

void solution(int row)
{
	// explore by row, from top to down
	if (row == N)
	{
		ans++;
		return;
	}

	// 1. find col
	for (int col = 0; col < N; ++col)
	{
		bool canPlace = true;
		rowPlacedCol[row] = col;

		// 2. check if it can be placed (about existing queens)
		for (int rec = 0; rec < row; ++rec)
		{
			if (rowPlacedCol[row] == rowPlacedCol[rec] || abs(rowPlacedCol[row] - rowPlacedCol[rec]) == row - rec)
			{
				canPlace = false;
				break;
			}
		}
		
		// 3. process next row
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