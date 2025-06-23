#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector>
using namespace std;

string glass = "[ ]";
int panels = 18;
const int livesNum = 10;
int lives = livesNum;

void setUpBridge(vector<string>& left, vector<string>& right) {
    for (int i = 0; i < panels; i++) {
        int side = rand() % 2;
        if (side == 0) {
            left.push_back(glass);
            right.push_back("   ");
        }
        else {
            right.push_back(glass);
            left.push_back("   ");
        }
    }
}

void displayPlayerOnLand(int turn, string state) {
    if (turn == 0) {
        for (int i = 0; i < lives; i++) {
            if (i < (livesNum / 2)) {
                cout << "O";
            }
        }
        cout << " ";
    }
    else {
        if (state == glass) {
            for (int i = 0; i < livesNum; i++) {
                if (i < (livesNum - lives) + turn) {
                    cout << " ";
                } else {
                    cout << "O";
                }
            }
            cout << " ";
        }
        else {
            for (int i = 0; i < livesNum; i++) {
                cout << " ";
            }
            cout << " ";
        }
    }
}

void displayBridgeOnTurn(int& turn, const vector<string>& left, const vector<string>& right) {
    cout << endl;
    displayPlayerOnLand(turn, left[0]);
    for (int i = 0; i < panels; i++) {
        if (turn <= lives && left[i] == glass && i < turn) { 
            cout << "[O]" << " ";
            continue;
        }
        if (turn > lives && i >= (turn - lives) && left[i] == glass && i < turn) {
            cout << "[O]" << " ";
            continue;
        }
        cout << (turn > i ? left[i] : glass) << " ";
    }
    cout << " L " << endl;
    displayPlayerOnLand(turn, right[0]);
    for (int i = 0; i < panels; i++) {
        if (turn <= lives && right[i] == glass && i < turn) { 
            cout << "[O]" << " ";
            continue;
        }
        if (turn > lives && i >= (turn - lives) && right[i] == glass && i < turn) {
            cout << "[O]" << " ";
            continue;
        }
        cout << (turn > i ? right[i] : glass) << " ";
    }
    cout << " R " << endl;
} 

void displayPlayer(string state) {
    if (state == glass) {
        for (int i = 0; i < lives; i++) {
            cout << "O";
        }
    }
}

void displayBridge(const vector<string>& left, const vector<string>& right) {
    cout << endl;
    for (int i = 0; i < panels; i++) {
        cout << left[i] << " ";
    }
    cout << " L  ";
    displayPlayer(left.back());
    cout << endl;
    for (int i = 0; i < panels; i++) {
        cout << right[i] << " ";
    }
    cout << " R  ";
    displayPlayer(right.back());
    cout << endl << endl;
}

int main() {
    srand(time(nullptr));
    int turn = -1;
    
    vector<string> left;
    vector<string> right;
    

    setUpBridge(left, right);

    cout << "Welcome to the Glass Bridge Game!\n";
    cout << "There are pairs of glass panels. Each pair has one tempered glass and one annealed glass, arranged either on the left or right side.\n";
    cout << "By choosing to jump on the left or right panel, you'll discover whether the glass is annealed or tempered.\n";
    cout << "There are 18 pairs of panels, but only 10 players to cross. Try to get as many players safely to the other side as possible.\n";
    cout << "Be careful! Choosing the wrong panel means one player will be sacrificed.\n";
    cout << "The sides are labeled at the end of the bridge.\n\n";

    while (true) {
        char input;
        turn++;
        displayBridgeOnTurn(turn, left, right);

        cout << "\nTurn " << turn + 1 << ". Only " << lives << " foolish souls remain.\n";
        cout << "Step up and choose: Left or Right? One wrong step, and someone won't make it across... (L/R):\n";
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (tolower(input) != 'r' && tolower(input) != 'l') {
            cout << "Tsk tsk... indecision can be fatal.\n";
            cout << "Pick a side — Left or Right. No second chances. (L/R):\n";
            cin >> input;
        }

        if (tolower(input) == 'r') {
            if (right.at(turn) != glass) {
                lives--;
            }
        }
        if (tolower(input) == 'l') {
            if (left.at(turn) != glass) {
                lives--;
            }
        }

        if (lives == 0) {
            cout << "\nHow tragic... and yet, so entertaining.\n";
            cout << "You lose. Every last one of you... gone. Seems luck wasn't on your side after all.\n\n";
            break;
        }

        if (turn == panels - 1) {
            turn++;
            displayBridgeOnTurn(turn, left, right);
            cout << "\nWell, well... color me surprised.\n";
            cout << lives << " of you actually made it across. Hmph... I suppose that means you win. For now.\n";
            cout << "Enjoy your victory — while it lasts.\n\n";
            break;
        }
    }

    cout << "Take a look at the bridge — not that it matters now.\n";
    cout << "The panels don't lie. But you? You guessed.\n";
    displayBridge(left, right);

    return 0;
}