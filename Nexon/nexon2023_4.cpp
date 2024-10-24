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
		// ���� ���������� ���� ���ذ���, �Ӱ谪�� �����ϴ� �ּҰ� ����
		// (���α׷��� ���뼱 ����)
		int sum = 0;

		while (left < right)
		{
			int mid = left + (right - left) / 2;
			sum = 0;

			// mid������ ���� �������� ��� ����
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