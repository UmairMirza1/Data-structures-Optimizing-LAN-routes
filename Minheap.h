#pragma once
#include<iostream>
using namespace std;
template<class K, class V>
class Minheap
{
private:
	struct Node {
		K key;
		V value;

		Node() {}

		bool operator<(const Node& other) {
			return value < other.value;
		}

		bool operator>(const Node& other) {
			return value > other.value;
		}
	};

private:
	Node* h;
	int msize;
	int hsize;

public:
	Minheap()
	{
	}
	Minheap(Node* ar1, int size)
	{
		this->hsize = 0;
		this->msize = size;
		this->h = new Node[msize];
		for (int i = 0; i < size; i++)
		{
			this->insert(ar1[i].key, ar1[i].value);
		}
	}
	Minheap(int s)
	{
		this->msize = s;
		this->h = new Node[msize];
		hsize = 0;
	}
	bool insert(const K& key, const V& v)
	{
		if (hsize > msize)
		{
			return false;
		}
		Node toInsert;
		toInsert.key = key;
		toInsert.value = v;
		h[hsize] = toInsert;
		int i = hsize;
		while (i > 1 && h[i].key < h[i / 2].key)
		{
			swap(h[i], h[i / 2]);
			i = i / 2;
		}
		hsize++;
	}

	const K& getMinKey() {
		return h[0].key;
	}

	const V& getMinValue() {
		return h[0].value;
	}

	void extractmin()
	{
		V a = h[0].value;
		swap(h[hsize], h[0]);
		hsize--;
		Heapify(0);
	}

	void update(const K& key, const V& value) {
		int index = 0;
		search(key, index);

		Node toInsert;
		toInsert.key = key;
		toInsert.value = value;

		h[index] = toInsert;

		decreasekey(index);
	}

	bool search(const K& key, int& index) {
		for (int i = 1; i <= hsize; i++)
		{
			if (h[i].key == key)
			{
				index = i;
				return true;
			}
		}
		return false;
	}

	bool search(const K& key, V& value)
	{
		int index = 0;
		if (search(key, index)) {
			value = h[index].value;
			return true;
		}
		else
			return false;
	}

	void decreasekey(int index)
	{
		while (index >= 1 && h[index] < h[index / 2])
		{
			swap(h[index], h[index / 2]);
			index = index / 2;
		}

	}

	void Heapify(int i)
	{
		int min = i;
		if (2 * i <= this->hsize && h[min] > h[2 * i])
		{
			min = 2 * i;
		}
		if (2 * i + 1 <= hsize && h[min] > h[2 * i + 1])
		{
			min = 2 * i + 1;
		}
		if (min != i)
		{
			swap(h[i], h[min]);
			Heapify(min);
		}
	}

	bool isEmpty() {
		return hsize == 0;
	}

	~Minheap()
	{
		if (hsize != 0)
		{
			delete[] h;
			h = nullptr;
		}
		else
		{
			h = nullptr;
		}
	}
	void print()
	{
		if (hsize == 0)
		{
			cout << "No elements" << endl;
		}
		else
		{
			for (int i = 1; i <= hsize; i++)
			{
				cout << h[i].value << " ";
			}
			cout << endl;
		}
	}

};
