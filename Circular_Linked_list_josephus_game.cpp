// lab8task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node() {
        next = NULL;
    }
    /*node(int data) {
        this->data = data;
        next = NULL;
    }*/
};
class list {
    node* head;
public:
    list() {
        head = NULL;
    }
    void insert(int ndata) {
        node* newnode = new node;
        if (!head) {
            head = newnode;
            newnode->data = ndata;
            newnode->next = head;
        }
        else {
            node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newnode;
            newnode->data = ndata;
            curr->next->next = head;
        }
    }
    void remove(int ndata) {
        if (!head) {
            cout << "Sorry! List is Empty" << endl;
        }
        else {
            node* prev = NULL;
            node* curr = head;
            while (curr && curr->data != ndata) {
                prev = curr;
                curr = curr->next;
            }
            if (curr)
            {
                if (prev)
                {
                    prev->next = curr->next;
                    delete curr;
                }
                else
                {
                    head = curr;
                    delete curr;
                }
            }
        }
    }
    void eliminiation(int times) {
        node* curr = head;
        while (head->next != head) {
            int index = 1;
            while (index != times) {
                curr = curr->next;
                index += 1;
            }
            remove(curr->next->data);
            cout << endl;
            display();
        }
}

    void display() {
        if (!head) {
            cout << "Sorry! List is Empty" << endl;
        }
        else {
            node* i = head;
            while (i->next != head) {
                cout << i->data << " ";
                i = i->next;
            }
        }
    }
};
int main()
{
    list l1;
    int i = 0;
    while(i < 7) {
        l1.insert(i);
        i += 1;
    }
    l1.display();
    l1.remove(4);
    cout << "Displaying after removal" << endl;
    l1.display();
    cout << endl;
    l1.eliminiation(2);
    cout << endl;
    l1.display();
    cout << "Congrats! person left above is the winner." << endl;
   
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
