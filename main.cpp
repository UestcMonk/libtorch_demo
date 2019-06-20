#include <iostream>

#include <torch/script.h>
#include <ATen/ATen.h>

#include <iostream>
#include <memory>
#include <vector>
#include <set>
using namespace std;
//using namespace at;

void run(vector<vector<int>>& ret, vector<int>& nums, vector<int> cur, int cc)
{
	int size = nums.size() - 1;
	if (cc == size)
	{
		cur.push_back(nums[cc]);
		ret.push_back(cur);
		// cur.pop_back();
		return;
	}
	set<int> s;
	for (int i = cc; i <= size; ++i)
	{
		if (s.count(nums[i]) != 0)continue;
		s.insert(nums[i]);
		// vector<int> tmp = cur;
		cur.push_back(nums[i]);
		ret.push_back(cur);
		if (i < size)
			run(ret, nums, cur, i + 1);
		cur.pop_back();
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> ret;
	int size = nums.size();
	vector<int> tmp;
	run(ret, nums, tmp, 0);
	//vector<int> tmp;
	//for (int i = 0; i <= size; ++i)
	//{
	//	tmp.push_back(nums[i]);
	//	ret.push_back(tmp);
	//	run(ret, nums, tmp, i + 1);
	//	tmp.pop_back();
	//}
	ret.push_back({});
	ret.push_back(nums);
	return ret;
}
bool myfunction(pair<int, int> map1, pair<int, int> map2)
{
	return (map1.second < map2.second);
}//��������
int __gcd(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
#define CUR 0x01
#define LATER 0x02
void setZeroes(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] & CUR == 0)
			{
				for (int k = 0; k < n; k++)
				{
					matrix[i][k] |= LATER;
				}
				for (int k = 0; k < m; k++)
				{
					matrix[k][j] |= LATER;
				}
			}

		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] & LATER != 0)
			{
				matrix[i][j] = 0;
			}
		}
	}
}

struct ListNode {
	     int val;
	     ListNode *next;
	     ListNode(int x) : val(x), next(NULL) {}
};

int main()
{

	ListNode *head = array2list({1,2,3,4,5});
	rotateRight(head,2);
	vector<vector<int>> a = { {1,1,1},{1,0,1},{1,1,1} };
	setZeroes(a);


	//vector<vector<int>> a = { {1,2,3},{3,2,1} };
	//vector<vector<int>> b = a;

	//b[0][0] = 10;
	//unordered_map<int, int> map;
	//map[1] += 1;
	//for (int i = 0; i < 5; ++i)
	//{
	//	map[i] = i;
	//}
	//int gcd = __gcd(0, 20);
	//sort(map.begin(), map.end(), [=](std::pair<int, int>& a, std::pair<int, int>& b) { return a.second < b.second; });
	//auto it = map.begin();
	//int cc = it->second;
	//int c = map[1];
	//set<int>  key;
	//key.insert(1);
	//key.insert(1);
	//key.insert(2);
	//for (int k : key)
	//{
	//	
	//	cout << k <<":"<< key.count(k)<< endl;
	//}

	//

	vector<int> nums = { 1,2,2 };
	string S = "a1b2";
	//subsetsWithDup(nums);
   /* at::Tensor a = at::ones({ 2,2 }, at::kInt);
    std::cout << a << "\n";*/

    std::cout << "ok\n";
    std::cout << "Hello, World!" << std::endl;
    return 0;
}