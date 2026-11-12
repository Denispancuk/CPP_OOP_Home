#include <iostream>
#include <string>
#include <random>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Symbol {
    string name;
    int weight;
    int multiplier;
};

Symbol symbols[6] = {
    {u8"[\U0001F352]", 40, 6},
    {u8"[\U0001F34B]", 30, 10},
    {u8"[\U0001F514]", 15, 25},
    {u8"[\U0001F36B]", 10, 80},
    {u8"[\U00002B50]", 4, 250},
    {u8"[\U0001F0CF]", 1, 500}
};

int weights[6];

random_device rd;
mt19937 gen(rd());
discrete_distribution<> dist;

void spinGrid(int grid[3][3], discrete_distribution<>& dist, mt19937& gen) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = dist(gen);
        }
    }
}

void simulate(discrete_distribution<>& dist, mt19937& gen) {
    int spins = 10000000;
    long long postavleno = 0;
    long long win = 0;
    int grid[3][3];
    int lineWin[3];

    for (int i = 0; i < spins; i++) {
        spinGrid(grid, dist, gen);
        postavleno = postavleno + 3;
        win = win + evaluate(grid, 1, lineWin);
    }

    cout << "Spins: " << spins << endl;
    cout << "Postavleno: " << postavleno << ", win: " << win << endl;
    cout << "RTP = " << (double)win / postavleno * 100.0 << "%" << endl;
}

int main() {
    SetConsoleOutputCP(65001);

    int weights[6];
    for (int i = 0; i < 6; i++) {
        weights[i] = symbols[i].weight;
    }

    random_device rd;
    mt19937 gen(rd());
    discrete_distribution<> dist(weights, weights + 6);

int evaluate(int grid[3][3], int bet, int lineWin[3]) {
    int total = 0;
    for (int i = 0; i < 3; i++) {
        int a = grid[i][0];
        int b = grid[i][1];
        int c = grid[i][2];

        int target = a;
        if (target == 5) target = b;
        if (target == 5) target = c;

        if ((a == target || a == 5) && (b == target || b == 5) && (c == target || c == 5)) {
            lineWin[i] = bet * symbols[target].multiplier;
        }
        else {
            lineWin[i] = 0;
        }
        total = total + lineWin[i];
    }
    return total;
}



int main() {
    SetConsoleOutputCP(65001);
    for (int i = 0; i < 6; i++) {
        weights[i] = symbols[i].weight;
    }
    dist = discrete_distribution<>(weights, weights + 6);

    int balance = 1000;
    int bet = 10;
    int finalBet = bet * 3;
    //\033[97;41m - red
    //\033[97;40m - black
    //\033[97;42m - green
    cout << "\033[97;41m--------\033[97;40m--------\033[97;42m Casino \033[97;40m--------\033[97;41m--------\033[0m" << endl;

    while (balance >= finalBet) {
        cout << endl;
        cout << "Balance: " << balance << " | Bet per line: " << bet << " | Spin cost: " << finalBet << endl;
        cout << "Enter - spin, s - simulation, q - quit: ";

        char input = _getch();
        cout << endl;

        if (input == 'q' || input == 'Q') {
            break;
        }
        else if (input == 's' || input == 'S') {
            simulate();
        }
        else if (input == '\r') {
            balance = balance - finalBet;

            int grid[3][3];
            spinGrid(grid);

            cout << "Spinning the reels..." << endl;
            Sleep(400);

            cout << "-----------------------------" << endl;
            for (int i = 0; i < 3; i++) {
                cout << "| ";
                for (int j = 0; j < 3; j++) {
                    cout << symbols[grid[i][j]].name << " ";
                }
                cout << "|" << endl;
            }
            cout << "-----------------------------" << endl;

            int lineWin[3];
            int totalWin = evaluate(grid, bet, lineWin);

            for (int i = 0; i < 3; i++) {
                if (lineWin[i] > 0) {
                    cout << "Win on line " << i + 1 << ": +" << lineWin[i] << "!" << endl;
                }
            }

            if (totalWin > 0) {
                balance = balance + totalWin;
            }
            else {
                cout << "Try again, no combination" << endl;
            }
        }
    }

    cout << endl << "Game over! Your final balance: " << balance << endl;
    return 0;
}