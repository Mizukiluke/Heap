// Heap.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <ctime>
#include <iostream>
using namespace std;
class Heap
{
	vector<int> cont;
	int& itemAt(int i) {
		return cont[i - 1];
	}
	int count() {
		return (int)cont.size();
	}

	void exch(int i, int j) {
		int temp = itemAt(i);
		itemAt(i) = itemAt(j);
		itemAt(j) = temp;
	}

	void swim(int i) {
		while (i!=1)
		{
			int j = i >> 1;
			if (itemAt(j) > itemAt(i))
			{
				exch(i, j);
				i = j;
			}
			else
				break;
		}
	}

	void sink(int i) {
		while (true)
		{
			int l = i << 1, r = i << 1 | 1;
			int target = 0;
			if (l <= count())
			{
				if (itemAt(l) < itemAt(i))
					target = l;
				if (r <= count())
				{
					if (target)
					{
						if (itemAt(r) < itemAt(target))
							target = r;
					}
					else
					{
						if (itemAt(r) < itemAt(i))
							target = r;
					}
				}
			}
			if (target)
			{
				exch(i, target);
				i = target;
			}
			else
				break;
		}
	}

public:
	void insert(int v)
	{
		cont.push_back(v);
		swim(cont.size());
	}
	bool empty()
	{
		return count() == 0;
	}
	int peak() {
		return itemAt(1);
	}
	void deleteMin() {
		exch(1, count());
		cont.erase(cont.end() - 1);
		sink(1);
	}
};

int main()
{

	Heap heap;
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		int val = rand() % 20;
		cout << val << ' ';
		heap.insert(val);
	}
	cout << endl;
	cout << "Opt" << endl;
	while (heap.empty() == false)
	{
		cout << heap.peak() <<' ';
		heap.deleteMin();
	}
	cout << endl;
	return 0;
}