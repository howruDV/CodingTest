#include <vector>
#include <minmax.h>
using namespace std;

class Sol
{
public:
	int GetMaxTime(vector<int>& energy, int th)
	{
		int left = 0;
		int right = -1;

		// 0. read energy
		for (int it : energy)
		{
			right = max(right, it);
		}

		// 1. paramater search
		// 남은 에너지량의 합을 더해가며, 임계값을 만족하는 최소값 구함
		// (세로그래프 절취선 위쪽)
		int sum = 0;

		while (left < right)
		{
			int mid = left + (right - left) / 2;
			sum = 0;

			// mid값보다 높은 에너지를 모두 더함
			for (int it : energy)
			{
				if (it > mid)
				{
					sum += it - mid;
				}
			}

			if (sum > th)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		if (sum > th)
			return left - 1;
		return left;
	}
};