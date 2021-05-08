#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


struct NhanVien {
	int id;
	string name;
	string home_town;
};
struct Node {
	NhanVien data;
	Node* p_next;
};
struct List {
	Node* p_head;
	Node* p_tail;
};



Node* createNode(int id, string name, string home_town)
{
	Node* p = new Node;
	(*p).data.id = id;
	(*p).data.name = name;
	(*p).data.home_town = home_town;
	(*p).p_next = NULL;
	return p;
}

void addTail(List& L, NhanVien nv)
{
	Node* p = new Node;
	p = createNode(nv.id, nv.name, nv.home_town);
	L.p_tail->p_next = p;
	L.p_tail = p;
}

void readData(string filename, List& L)
{
	fstream fs;
	fs.open(filename, ios::in);
	if (fs)
	{
		int n;
		int id;
		string name, town;
		fs >> n;

		for (int i = 0; i < n; i++)
		{
			string data;
			getline(fs, data, '_');
			stringstream ss(data);
			ss >> id;

			getline(fs, data, '_');
			name = data;

			getline(fs, data, '\n');
			town = data;

			Node* nNode = createNode(id, name, town);
			if (i == 0)
			{
				L.p_head = nNode;
				L.p_tail = nNode;
			}
			else addTail(L, nNode->data);
		}
	}
	else cout << "can't open file to read!";
}

void removeById(List& L, int id)
{
	Node* index = L.p_head;
	Node* temp = new Node;
	if (id == L.p_head->data.id)
	{
		temp = L.p_head;
		L.p_head = L.p_head->p_next;
		delete temp;
	}
	else
		while (index->p_next != L.p_tail)
			if (index->p_next->data.id == id)
			{
				temp = index->p_next;
				index->p_next = index->p_next->p_next;
				delete temp;
				break;
			}
	if (id == L.p_tail->data.id)
	{
		temp = L.p_tail;
		index->p_next = NULL;
		L.p_tail = index;
		delete temp;
	}

}

void print(List L)
{
	Node *index = L.p_head;
	fstream fs;
	fs.open("123.txt", ios::out);
	while (index != NULL)
	{
		fs << "id: " << index->data.id << " Name: " << index->data.name << " HomeTown: " << index->data.home_town << endl;
		index = index->p_next;
	}

}

int main()
{
	List L;
	L.p_head = NULL;
	L.p_tail = NULL;
	string filename;
	cout << "input the file name to read: ";
	cin >> filename;

	readData(filename, L);

	int id;
	cout << "input the id to delete: ";
	cin >> id;
	removeById(L, id);

	print(L);

}
