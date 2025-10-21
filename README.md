# Guessing Game 🎮
A simple C++ console game built for my CSCE 1030 class.  
Players guess the **product**, **quotient**, or **average** of two random numbers between 50 and 100.  
Points are earned for correct guesses and lost for incorrect ones or when revealing numbers.

## Features
- Menu-driven gameplay using enumerations and switch cases
- Random number generation with input validation
- Point system with reward and penalty logic
- Loop-based replay and exit options

## How to Run
1. Clone this repository.
2. Compile the program:
   ```bash
   g++ main.cpp -o guessing_game
Option 1: Run the Executable (Windows)
If you're using Windows, you can play immediately:
1. Download or clone this repository.
2. Open the folder and double-click **guessing_game.exe**.
3. The game will launch in a console window.

> 💡 No compiler setup is needed if you use the provided `.exe` file.

Option 2: Compile from Source (Any OS)
If you prefer or you're not on Windows:
1. Open a terminal in the project folder.
2. Compile the code:
```bash
   g++ main.cpp -o main.exe
   ```bash
   g++ guessing_game.cpp -o guessing_game
