#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Constants for the theater
const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;

// Structure to represent a seat
struct Seat {
    int row;
    int col;
    bool isAvailable;
};

// Function to display the theater layout
void displayTheaterLayout(const vector<vector<Seat>>& theater) {
    cout << "Theater Layout:" << endl;
    for (const auto& row : theater) {
        for (const Seat& seat : row) {
            if (seat.isAvailable) {
                cout << "[ ]";
            } else {
                cout << "[X]";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to display movie listings
void displayMovieListings() {
    cout << "Movie Listings:" << endl;
    cout << "1. Movie A" << endl;
    cout << "2. Movie B" << endl;
    cout << "3. Movie C" << endl;
    cout << endl;
}

int main() {
    vector<vector<Seat>> theater(NUM_ROWS, vector<Seat>(NUM_COLS, {0, 0, true}));
    int movieChoice;
    int rowChoice, colChoice;
    int numTickets;
    double totalCost = 0.0;

    cout << "Welcome to the Movie Ticket Booking System!" << endl;

    while (true) {
        displayMovieListings();
        cout << "Select a movie (1-3, 0 to exit): ";
        cin >> movieChoice;

        if (movieChoice == 0) {
            break;
        } else if (movieChoice < 1 || movieChoice > 3) {
            cout << "Invalid choice. Please select a valid movie." << endl;
            continue;
        }

        displayTheaterLayout(theater);

        cout << "Enter the number of tickets to book: ";
        cin >> numTickets;

        for (int i = 0; i < numTickets; ++i) {
            cout << "Enter the row and column for ticket " << i + 1 << " (e.g., 2 4): ";
            cin >> rowChoice >> colChoice;

            if (rowChoice < 1 || rowChoice > NUM_ROWS || colChoice < 1 || colChoice > NUM_COLS || !theater[rowChoice - 1][colChoice - 1].isAvailable) {
                cout << "Invalid seat selection. Please choose a valid seat." << endl;
                --i; // Retry booking for the same ticket
                continue;
            }

            theater[rowChoice - 1][colChoice - 1].isAvailable = false;
            totalCost += TICKET_PRICE;
        }

        cout << "Booking successful! Total cost: $" << fixed << setprecision(2) << totalCost << endl;
    }

    cout << "Thank you for using the Movie Ticket Booking System!" << endl;

    return 0;
}
