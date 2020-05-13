#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class LinkNode {
public:
    int num;
    LinkNode* next;
    LinkNode(int a) : num(a), next(NULL) {}
};

void add(LinkNode* cur, int num) {
        LinkNode* new_node = new LinkNode(num);

        while (cur->next) {
            if (cur->num > num) {
                new_node->next = cur;
                cur = new_node;
                return;
            }
            cur = cur->next; 
        }

        // end of the list
        cur->next = new_node;

        return;
    }

void print_out(LinkNode* node) {
    while (node) {
        cout << node->num << " ";
        node = node->next;
    }
    endl(cout);
}

void unique(LinkNode* node) {
    LinkNode dummy(0);
    LinkNode* cur = &dummy;

    if (node == NULL) return;

    cur->next = node;
    cur = cur->next;
    node = node->next;

    while (node) {
        if (node->num != cur->num) {
            cur->next = node;
            cur = cur->next;
        }
        node = node->next;
    }
    return;
}

LinkNode* merge(LinkNode* l1, LinkNode* l2) {
    LinkNode dummy(0);
    LinkNode* cur = &dummy;

    while ((l1 != NULL) || (l2 != NULL)) {
        if (l1 == NULL) {
            cur->next = l2;
            l2 = l2->next;
        } else if (l2 == NULL) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            if (l1->num < l2->num) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
        }
        cur = cur->next;
    }

    cur->next = NULL;

    return dummy.next;
}

int main() {
    int n = 0;
    string input;
    unordered_map<int, LinkNode*> map;
    
    getline(cin,input);
    n = stoi(input);

    while (n--) {
        getline(cin, input);
        string cmd;
        string para1;
        string para2;
        int pos = 0;
        
        pos = input.find(' ');
        cmd = input.substr(0, pos);
        input = input.substr(pos + 1);

        pos = input.find(' ');
        if (pos == string::npos) {
            para1 = input;
        } else {
            para1 = input.substr(0, pos);
            input = input.substr(pos + 1);
            para2 = input;
        }
        
        if (cmd == "new") {
            int id1 = stoi(para1);
            map[id1] = NULL;
        } else if (cmd == "add") {
            int id1 = stoi(para1);
            int num = stoi(para2);
            if (map[id1] == NULL) map[id1] = new LinkNode(num);
            else add(map[id1], num);
        } else if (cmd == "merge") {
            int id1 = stoi(para1);
            int id2 = stoi(para2);
            map[id1] = merge(map[id1], map[id2]);
            map[id2] = NULL;
        } else if (cmd == "out") {
            int id1 = stoi(para1);
            print_out(map[id1]);
        } else if (cmd == "unique") {
            int id1 = stoi(para1);
            unique(map[id1]);
        } else {
            cout << "error cmd:" << cmd << endl;
        }
    }
}
