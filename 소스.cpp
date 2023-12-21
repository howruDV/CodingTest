#include <vector>
using namespace std;

int main()
{
	vector<int> v = { 1, 1 };

	for (int i = 0; i < v.size(); ++i)
	{
		v.push_back(i);
	}

	return 0;
}