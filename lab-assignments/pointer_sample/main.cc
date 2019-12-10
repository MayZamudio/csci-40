#include <iostream>
#include <memory>
using namespace std;

//This is some demo code showing the difference between normal ("raw") pointers and smart pointers

void example_1(); //Returns nothing
int *example_2(); //Returns a raw pointer
int *example_3(); //Returns a raw pointer
unique_ptr<int[]> example_4(); //Returns a smart pointer
shared_ptr<int[]> example_5(); //Returns a smart pointer

int main() {
    cout << "This program will teach you about pointers through exmaple.\n";
    cout << "Which example code do you wish to run? (1 through 5)\n";
    int x = 0;
    cin >> x;
    if (!cin || x < 1 || x > 5) {
        cout << "Bad input!\n";
        exit(EXIT_FAILURE);
    }
    if (x == 1) example_1();
    else if (x == 2) {
        cout << "Calling example_2...\n";
        int *a = example_2();
        if (a == nullptr)
            cout << "Got a nullptr. What should we do with it?\n";
        else
            cout << "Got a non-null pointer from example_2... it's hard to tell if we own that memory or not or if it is an array. Should we:\n";
        cout << "0) delete[] a;\n";
        cout << "1) delete a;\n";
        cout << "2) leave it alone\n";
        int choice = 0;
        cin >> choice;
        if (!cin) exit(EXIT_FAILURE);
        if (choice <= 0) {
            cout << "Congrats, we were supposed to delete[] it. You can't tell from looking at the code in main, though.\n";
            delete[] a;
        }
        else if (choice == 1) {
            cout << "Ooh, so close but bad. It's an array, not just a pointer to an int, so we should have called delete[] instead of delete\n";
            delete a;
        }
        else {
            cout << "Oof. We actually own that memory, so it was our responsibility to delete it. We're going to leak all that memory now.\n";
        }
            }
    else if (x == 3) {
        cout << "Calling example_3...\n";
        int *a = example_3();
        if (a == nullptr)
            cout << "Got a nullptr. What should we do with it?\n";
        else
            cout << "Got a non-null pointer from example_3... it's hard to tell if we own that memory or not or if it is an array. Should we:\n";
        cout << "0) delete[] a;\n";
        cout << "1) delete a;\n";
        cout << "2) leave it alone\n";
        int choice = 0;
        cin >> choice;
        if (!cin) exit(EXIT_FAILURE);
        if (choice <= 0) {
            cout << "Ooh, unlucky! We got a non-owning raw pointer to a chunk of memory that wasn't new-ed. This will crash.\n";
            delete[] a;
        }
        else if (choice == 1) {
            cout << "Ooh, unlucky! Both delete[] and delete will crash when ASAN is on, and you try freeing memory you shouldn't.\n";
            delete a;
        }
        else {
            cout << "Correctomundo! This function returned a non-owning pointer to some memory, not that you could tell from looking just at main.\n";
            cout << "That array has already been de-allocated, but we can still look at what was there and see if it has changed or not...\n";
            cout << "Here's the first 20 ints in memory from that pointer:\n";
            for (int i = 0; i < 20; i++) {
                cout << "a[" << i << "]: " << a[i] << endl;
            }
        }
    }
        else if (x == 4) {
        cout << "Calling example_4...\n";
        auto a = example_4();
        if (a == nullptr)
            cout << "Got a nullptr. What should we do with it?\n";
        else
            cout << "Got a non-null pointer from example_4... it's hard to tell if we own that memory or not or if it is an array. Should we:\n";
        cout << "0) delete[] a;\n";
        cout << "1) copy it\n";
        cout << "2) leave it alone\n";
        int choice = 0;
        cin >> choice;
        if (!cin) exit(EXIT_FAILURE);
        if (choice <= 0) {
            cout << "Can't delete a smart pointer! It'll delete itself!\n";
            //delete[] a;
        }
        else if (choice == 1) {
            cout << "Oof. You can't copy a unique pointer. That's why it's a unique pointer!\n";
            //auto b = a; //Won't compile
        }
        else {
            cout << "Yep! You don't ever have to worry about ownership when you use a unique pointer - if you have it, you own it.\n";
            cout << "And you don't even have to delete it - it'll delete itself when it goes out of scope.\n";
            cout << "Here's the first 20 ints in memory from that pointer:\n";
            for (int i = 0; i < 20; i++) {
                cout << "a[" << i << "]: " << a[i] << endl;
            }
        }
    }
        else if (x == 5) {
        cout << "Calling example_5...\n";
        auto a = example_5();
        if (a == nullptr)
            cout << "Got a nullptr. What should we do with it?\n";
        else
            cout << "Got a non-null pointer from example_5... it's hard to tell if we own that memory or not or if it is an array. Should we:\n";
        cout << "0) delete[] a;\n";
        cout << "1) copy it\n";
        cout << "2) leave it alone\n";
        int choice = 0;
        cin >> choice;
        if (!cin) exit(EXIT_FAILURE);
        if (choice <= 0) {
            cout << "Can't delete a smart pointer! It'll delete itself!\n";
            //delete[] a;
        }
        else if (choice == 1) {
            cout << "You can copy a shared pointer all you want!\n";
            cout << "Once *all* of the copies go out of scope, the thing pointed to is deallocated automatically.\n";
            auto b = a; //B will be a copy of A, and then it'll go away with the }
        }
        else {
            cout << "Yep! You don't ever have to worry about ownership when you use a unique pointer - if you have it, you own it.\n";
            cout << "And you don't even have to delete it - it'll delete itself when it goes out of scope.\n";
            cout << "Here's the first 20 ints in memory from that pointer:\n";
            for (int i = 0; i < 20; i++) {
                cout << "a[" << i << "]: " << a[i] << endl;
            }
        }
    }
}
