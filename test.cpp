#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<string>
using namespace std;
//
//struct SinhVien
//{
//	int id;
//	double score;
//	string name;	
//};
//
//struct Node
//{
//	SinhVien sv;
//	Node* pNext;
//};
//
//struct List
//{
//	Node* pHead;
//	Node* pTail;
//};
//
//Node* createNode(SinhVien sv)
//{
//	Node* a = new Node;
//	(*a).sv.id = sv.id;
//	(*a).sv.name = sv.name;
//	(*a).sv.score = sv.score;
//	(*a).pNext = NULL;
//	return a;
//}
//
//void addTail(List& L, Node* p)
//{
//	L.pTail->pNext = p;
//	L.pTail = p;
//}
//
//void readData(string filename, List &L)
//{
//	SinhVien sv;
//	string data;
//	int n;
//	fstream fs;
//	fs.open(filename, ios::in);
//	if (!fs)
//	{
//		cout << "can't open " << filename << endl;
//		return;
//	}
//
//	fs >> n;
//	fs.ignore();
//	for (int i = 0; i < n; i++)
//	{
//		getline(fs, data, '-');
//		stringstream ss(data);
//		ss >> sv.id;
//		ss.str("");
//		ss.clear();
//		getline(fs, data, '-');
//		ss << data;
//		ss >> sv.score;
//		getline(fs, data, '\n');
//		sv.name = data;
//		Node* pCur = createNode(sv);
//		if (i == 0)
//		{
//			L.pHead = pCur;
//			L.pTail = pCur;
//		}
//			else
//				addTail(L, pCur);
//	}
//}
//
//
//void printData(List L)
//{
//	Node* p = L.pHead;
//	while (p != NULL)
//	{
//		cout << p->sv.id << " ";
//		cout << p->sv.score << " ";
//		cout << p->sv.name << " ";
//		cout << endl;
//		p = p->pNext;
//	}
//}
//
//int main()
//{
//	List L;
//	readData("input.txt", L);
//	printData(L);
//}

int count(int n, int m)
{
	if (n < m)
		return 0;
	for (int i = m; i < n / 2; i++)
	{
		if (n - i >= m)
			return 1 + count(n - i, m);
	}
}

int main()
{
	int x;
	x = count(5, 2);
	cout << x;
}