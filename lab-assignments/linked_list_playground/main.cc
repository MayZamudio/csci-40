#include <iostream>
using namespace std;

class LL {
  public:
    int data;
    LL *next;
    LL(int new_data, LL *new_next) : data{new_data}, next{new_next} {}
};

//Prints a list starting at the node passed in
void print_list(LL* foo) {
    while (foo != NULL) {
        cout << foo->data << endl; //Output the data
        foo = foo-> next; //Move to the next node in the list
    }
}

int main() {

    cout << "Inserting 42 into first...\n";
    LL *first = new LL(42, nullptr);
    //first = NULL; //Uncomment this and see what explodes
    cout << "First data: " << first->data << endl;

    cout << "Inserting 32 into second...\n";
    LL *second = new LL(32, first);
    cout << "Second data: " << second->data << " First data: " << second->next->data << endl;

    cout << "Inserting 22 into third...\n";
    LL *third = new LL(22, second);
    cout << "Third data: " << third->data << " Second data: " << third->next->data << " First Data: " << third->next->next->data << endl;

    cout << "Inserting 12 into forth...\n";
    LL *fourth = new LL(12, third);
    cout << "All the datas: " << fourth->data << " " << fourth->next->data
         << " " << fourth -> next -> next -> data << " "
         << fourth -> next -> next -> next -> data << endl;
    cout << "The second half of the list is:\n";
    print_list(second); //Print the second half of the list
    cout << "The whole of the list is:\n";
    print_list(fourth); //Print the whole list
    
    //When you're done, you must delete all the nodes
    LL *cur = fourth;
    while (cur) {
        LL *next = cur->next;
        delete cur;
        cur = next;
    }

    return 0; //Delete this line to enable bonus mode

    //This code here will build a new list based on user input
    LL *head = nullptr;
    int count = 0;
    while (true) {
        cout << "Pls enter int: ";
        int x = 0;
        cin >> x;
        if (!cin || !x) break;
        LL *temp = new LL(x, head);
        head = temp;
        count++;
    }
    cout << "What index do you want to print: ";
    int index = 0;
    cin >> index;
    if (index >= count || count < 1) {
        cout << "No.\n";
        return 0;
    }
    LL *temp = head;
    for (int i = 0; i < index; i++) temp = temp->next;
    cout << "The value you asked for is: " << temp->data << endl;

}