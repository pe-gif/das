#include <iostream>
using namespace std;
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
 front->data = data;
 }
 void insert_rear(int data) {
 node* ptr = new node;
 if (rear == NULL) {
 front = ptr;
 }
 else {
 ptr->previous = rear;
 rear->next = ptr;
 }
 size++;
 rear = ptr;
 rear->data = data;
 }
 int remove_front() {
 if (front == NULL) {
 return 0;
 }
 else {
 node* ptr = front;
 if(front == rear){
 front = NULL;
 rear = NULL;
 }else{
 front = front->next;
 ptr->next = NULL;
 front->previous = NULL;
 }
 ptr = NULL;
 size--;
 delete ptr;
 return 0;
 }
 }
 int remove_rear() {
 if (rear == NULL) {
 return 0;
 }
 else {
 node* ptr = rear;
 if(rear == front){
 rear = NULL;
 front = NULL;
 }else{
 rear = rear->previous;
 rear->next = NULL;
 ptr->previous = NULL;
 }
 ptr = NULL;
 size--;
 delete ptr;
 return 0;
 }
 }
 int list_size() {
 return size;
 }
 void make_empty() {
 for (int i = 1; i <= size; i++) {
 node* ptr = front;
 front = front->next;
 ptr->next = NULL;
 delete ptr;
 }
 front = NULL;
 rear = NULL;
 size = 0;
 }
 void display() {
 node* ptr = front;
 if (front == NULL) {
 std::cout << "list empty" << "\n";
 }
 else {
 while (ptr != NULL) {
 std::cout << ptr->data << "\n";
 ptr = ptr->next;
 }
 }
 }
};
int main()
{
 doublelinklist list1;
 cout << "Inserting in the front when empty \n";
 list1.insert_front(30);
 list1.display();
 cout << "removing data making the list empty with rear\n";
 list1.remove_rear();
 list1.display();
 cout << "removing when list is empty with front \n";
 list1.remove_front();
 list1.display();
 cout << "Emptying list when empty \n";
 list1.make_empty();
 list1.display();
 cout << "inserting with loop and rear when empty \n";
 for (int i = 9; i >= 1; i--) {
 list1.insert_rear(i);
 }
 list1.display();
 cout << "Removing from ending of list \n";
 list1.remove_rear();
 list1.display();
 cout << "Removing from front of list \n";
 list1.remove_front();
 list1.display();
 cout << "displaying size of list \n";
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
