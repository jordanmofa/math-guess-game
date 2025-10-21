#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
cout << "Name : Jordan Mofa \n";
cout << "EUID : jem0647\n";
cout << "Email :jordanmofa@my.unt.edu \n";
cout << "Dept : Computer Science\n";
cout << "Course : CSCE 1030\n\n";
// 2. Points variable initialized to 50
int points = 50;
// 3. Enumeration with values 1..6
enum MenuOptions { MULTIPLY = 1, DIVIDE, AVERAGE, REVEAL, GIVEUP,
EXIT };
// 4. Ask for username and validate
string username;
bool validName = false;
while (!validName) {
cout << "Enter player's username (letters, digits, spaces only):
";
getline(cin, username);
if (username.length() == 0) {
cout << "Error: Username cannot be empty. Please try
again.\n";
continue;
}
validName = true;
for (size_t i = 0; i < username.length(); ++i) {
char ch = username[i];
if (!(isalnum(static_cast<unsigned char>(ch)) ||
isspace(static_cast<unsigned char>(ch)))) {
validName = false;
break;
}
}
if (!validName) {
cout << "Error: Username may contain only letters, digits and
whitespace. Try again.\n";
}
}
// 5. Welcome message
cout << "\nWelcome, " << username << "! Let's play the guessing
game.\n\n";
// 6. Seeded random integers in range 50..100, first < second
srand(static_cast<unsigned int>(time(NULL)));
int rand1 = 0, rand2 = 0;
do {
rand1 = 50 + rand() % 51; // 50..100
rand2 = 50 + rand() % 51; // 50..100
} while (!(rand1 < rand2));
bool revealShown = false; // to ensure REVEAL cost applies once per
game set
bool quit = false;
// 9. Main loop: continue until user chooses EXIT or points become
negative
while (!quit && points >= 0) {
cout << "-----------------------------\n";
cout << "Current points: " << points << "\n";
cout << "Menu:\n";
cout << " " << MULTIPLY << ". MULTIPLY the two numbers (guess the
product)\n";
cout << " " << DIVIDE << ". DIVIDE the two numbers (guess the
quotient first/second)\n";
cout << " " << AVERAGE << ". AVERAGE the two numbers (guess the
average)\n";
cout << " " << REVEAL << ". REVEAL the first random number
(costs 3 points)\n";
cout << " " << GIVEUP << ". GIVEUP (show both numbers)\n";
cout << " " << EXIT << ". EXIT\n";
cout << "Enter your choice (1-6): ";
int choice;
if (!(cin >> choice)) {
// invalid input (non-integer)
cin.clear();
cin.ignore(10000, '\n');
cout << "Invalid input. Please enter a number between 1 and
6.\n";
continue;
}
cin.ignore(10000, '\n'); // discard rest of line
switch (choice) {
case MULTIPLY: {
cout << "Guess the product of the two hidden numbers: ";
long long guess;
if (!(cin >> guess)) {
cin.clear();
cin.ignore(10000, '\n');
cout << "Invalid input. Returning to menu.\n";
break;
}
cin.ignore(10000, '\n');
long long actualProduct = static_cast<long long>(rand1) *
static_cast<long long>(rand2);
long long diff = llabs(actualProduct - guess);
if (diff < 50) { // correct
points += 5;
cout << "Correct guess! Product = " << actualProduct
<< ".\n";
cout << "You earned 5 points. Current points: " <<
points << ".\n";
// ask if user wants another game
cout << "Do you want to play another game (generate
new numbers)? (Y/N): ";
char resp;
cin >> resp;
cin.ignore(10000, '\n');
if (resp == 'Y' || resp == 'y') {
// regenerate numbers until rand1 < rand2
do {
rand1 = 50 + rand() % 51;
rand2 = 50 + rand() % 51;
} while (!(rand1 < rand2));
revealShown = false;
cout << "New numbers have been generated. Continue
playing.\n";
} else {
cout << "Continuing with current numbers.\n";
}
} else { // incorrect
points -= 1;
cout << "Incorrect guess. Actual product is not within
+/-49 of your guess.\n";
cout << "You lost 1 point. Current points: " << points
<< ".\n";
}
break;
}
case DIVIDE: {
cout << fixed << setprecision(4);
cout << "Guess the floating point quotient (first_number /
second_number): ";
double guess;
if (!(cin >> guess)) {
cin.clear();
cin.ignore(10000, '\n');
cout << "Invalid input. Returning to menu.\n";
break;
}
cin.ignore(10000, '\n');
double actualQuotient = static_cast<double>(rand1) /
static_cast<double>(rand2);
double diff = fabs(actualQuotient - guess);
if (diff < 0.5) { // correct
points += 5;
cout << "Correct guess! Quotient = " << actualQuotient
<< ".\n";
cout << "You earned 5 points. Current points: " <<
points << ".\n";
cout << "Do you want to play another game (generate
new numbers)? (Y/N): ";
char resp;
cin >> resp;
cin.ignore(10000, '\n');
if (resp == 'Y' || resp == 'y') {
do {
rand1 = 50 + rand() % 51;
rand2 = 50 + rand() % 51;
} while (!(rand1 < rand2));
revealShown = false;
cout << "New numbers generated. Continue
playing.\n";
} else {
cout << "Continuing with current numbers.\n";
}
} else { // incorrect
points -= 1;
cout << "Incorrect guess. Actual quotient is not
within +/-0.5 of your guess.\n";
cout << "Actual quotient = " << actualQuotient <<
".\n";
cout << "You lost 1 point. Current points: " << points
<< ".\n";
}
break;
}
case AVERAGE: {
cout << fixed << setprecision(4);
cout << "Guess the floating point average of the two
numbers: ";
double guess;
if (!(cin >> guess)) {
cin.clear();
cin.ignore(10000, '\n');
cout << "Invalid input. Returning to menu.\n";
break;
}
cin.ignore(10000, '\n');
double actualAverage = (static_cast<double>(rand1) +
static_cast<double>(rand2)) / 2.0;
double diff = fabs(actualAverage - guess);
if (diff < 2.0) { // correct
points += 5;
cout << "Correct guess! Average = " << actualAverage
<< ".\n";
cout << "You earned 5 points. Current points: " <<
points << ".\n";
cout << "Do you want to play another game (generate
new numbers)? (Y/N): ";
char resp;
cin >> resp;
cin.ignore(10000, '\n');
if (resp == 'Y' || resp == 'y') {
do {
rand1 = 50 + rand() % 51;
rand2 = 50 + rand() % 51;
} while (!(rand1 < rand2));
revealShown = false;
cout << "New numbers generated. Continue
playing.\n";
} else {
cout << "Continuing with current numbers.\n";
}
} else { // incorrect
points -= 1;
cout << "Incorrect guess. Actual average is not within
+/-2.0 of your guess.\n";
cout << "Actual average = " << actualAverage << ".\n";
cout << "You lost 1 point. Current points: " << points
<< ".\n";
}
break;
}
case REVEAL: {
if (!revealShown) {
points -= 3;
revealShown = true;
cout << "The first random number is: " << rand1 <<
"\n";
cout << "3 points deducted for revealing. Current
points: " << points << ".\n";
} else {
cout << "Error: The first number has already been
revealed for this game set. No additional deduction.\n";
}
break;
}
case GIVEUP: {
cout << "You gave up. The two random numbers are:\n";
cout << " First = " << rand1 << "\n";
cout << " Second = " << rand2 << "\n";
cout << "Do you want to play another game (generate new
numbers)? (Y/N): ";
char resp;
cin >> resp;
cin.ignore(10000, '\n');
if (resp == 'Y' || resp == 'y') {
do {
rand1 = 50 + rand() % 51;
rand2 = 50 + rand() % 51;
} while (!(rand1 < rand2));
revealShown = false;
cout << "New numbers generated. Continue playing.\n";
} else {
cout << "Continuing with current numbers.\n";
}
break;
}
case EXIT: {
cout << "\nGoodbye, " << username << "!\n";
cout << "Final points balance: " << points << "\n";
quit = true;
break;
}
default: {
cout << "Invalid menu choice. Please enter a number
