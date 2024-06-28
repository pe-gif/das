#include <iostream>

struct node {
    int data;
    node* next = NULL;
    node* previous = NULL;
};

class doublelinklist {
private:
    node* front = NULL;
    node* rear = NULL;
    int size = 0;
public:
    void insert_front(int data) {
        node* ptr = new node;

        if (front == NULL) {
            rear = ptr;
        }
        else {
            ptr->next = front;
            front->previous = ptr;
        }
        size++;
        front = ptr;
        ptr->data = data;
    }
    void insert_rear(int data) {
        
    }
    int remove_front() {
        node* ptr = front;
        front = front->next;
        ptr->next = NULL;
        front->previous = NULL;
        size--;
        delete ptr;
        return 0;
    }
    int remove_rear(){
        return 0;
    }
    int list_size() {
        return size;
    }
    void make_empty() {

    }
    void display() {
        std::cout << "front: " << front->data << "\n";
        std::cout << "rear: " << rear->data << "\n";
    }
};





int main()
{
    doublelinklist list1;

    list1.insert_front(20);
    list1.insert_front(30);
    list1.insert_front(40);
    list1.insert_front(50);
    list1.remove_front();
    list1.display();
    std::cout << "The size of list: " << list1.list_size();
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
