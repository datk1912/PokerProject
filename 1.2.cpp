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

Node* createNode(int id, string name, string home_town) {
    Node* a = new Node;
    (*a).data.id = id;
    (*a).data.name = name;
    (*a).data.home_town = home_town;
    (*a).p_next = NULL;
    return a;
}
void printList(List ds) {
    Node* cur;
    cur = ds.p_head;
    while (cur != ds.p_tail) {
        cout << cur->data.id << endl;
        cout << cur->data.name << endl;
        cout << cur->data.home_town << endl;
        cur = cur->p_next;
    }
    cout << cur->data.id << endl;
    cout << cur->data.name << endl;
    cout << cur->data.home_town << endl;
}
void addBack(List &ds, Node* a) {
    ds.p_tail->p_next = a;
    ds.p_tail = a;
}

void input(int &n, List& ds) {
    fstream file;
    int id;
    string name;
    string homeTown;
    file.open("Dulieu.txt", ios::in);
    if (file) {
        file >> n;
        file.ignore();
        for (int i = 0;i < n;i++){
            string data;
            getline(file, data,'_');
            stringstream ss(data);
            ss >> id;
            getline(file, data, '_');
            name = data;
            getline(file, data, '\n');
            homeTown = data;
            Node* nNode = createNode(id, name, homeTown);
            if (i == 0) {
                ds.p_head = nNode;
                ds.p_tail = nNode;
            }
            else addBack(ds, nNode);
        }
    }
    else {
        cout << "Can't open file Dulieu.txt";
        return;
    }
}
void delFromId(List &ds, int id) {
    while (ds.p_head->data.id == id) ds.p_head = ds.p_head->p_next;
    Node* cur;
    cur = ds.p_head;
    Node* preNode = ds.p_head;
    while (cur != ds.p_tail) {
        if (cur->data.id == id) preNode->p_next = cur->p_next;
        preNode = cur;
        cur = cur->p_next;
    }
    if (ds.p_tail->data.id == id) {
        ds.p_tail = preNode;
        preNode->p_next = NULL;
    }
}
int main() {
    int n;
    List ds;
    input(n, ds);
    delFromId(ds, 13);
    printList(ds);
    return 1;
}
