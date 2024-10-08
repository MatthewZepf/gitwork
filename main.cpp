#include <iostream>
#include <random>
#include <vector>
using namespace std;

//test
vector<int> memo(100, -1);

int fibonacci(int n) {
    if (n >= 2) {
        for (int i = 0; i < depth; ++i) {
            cout << "  ";
        }
        cout << "fibonacci(" << n << ") " << n << endl;
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    else {
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    }
}

void montyHall() {
    // Monty Hall problem
    int choice;
    cout << "Monty Hall Problem" << endl;
    cout << "Choose a door (1, 2, or 3): ";
    cin >> choice;
    int car = rand() % 3 + 1;
    // Reveal a door with a goat
    // Hi there! I'm adding a comment here to create a merge conflict.
    int reveal;
    do {
        reveal = rand() % 3 + 1;
    } while (reveal == car || reveal == choice);
    cout << "There is a goat behind door " << reveal << "!" << endl;
    // Give the option to switch doors
    char answer;
    cout << "Do you want to switch doors? (y/n): ";
    cin >> answer;
    if (answer == 'y') {
        // Switch the door
        int newChoice;
        do {
            newChoice = rand() % 3 + 1;
        } while (newChoice == choice || newChoice == reveal);
        choice = newChoice;
    }
    // Reveal the final choice
    cout << "You chose door " << choice << "." << endl;
    if (choice == car) {
        cout << "Congratulations! There is a car behind door " << car << "!" << endl;
    } else {
        cout << "Sorry, there is a goat behind door " << car << "." << endl;
    }
}

int main() {
    int n;
    cout << "Would you like to play the monte hall game or the fibonacci game? (1/2): ";
    cin >> n;
    if (n == 1) {
        montyHall();
    } else if (n == 2) {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << "Fibonacci number at position " << num << " is " << fibonacciTree(num) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
    // adding a comment for more merge conflicts :)
    return 0;
}