#include <iostream>
#include <fstream>
#include "stack.h"
#include <string>
using namespace std;

struct State 
{
    int row;
    int col;
};

int PmtForN()
{
    int N;
    cout << "Enter the value of N for the N-Queens problem: ";
    cin >> N;
    return N;
}

void removeQueen(State& currentState, int N, bool colCheck[], bool diagFCheck[], bool diagSCheck[], int positions[]) {
    colCheck[currentState.col] = false;
    diagFCheck[currentState.row + currentState.col] = false;
    diagSCheck[N - 1 + currentState.col - currentState.row] = false;
    positions[currentState.row] = -1;
}

int main() 
{
    int N = PmtForN();

    if(N <= 0) 
    {
        cout << "Invalid input. Please enter a positive integer" << endl;
        return 0;
    }

    int* positions = new int[N];

    for(int i = 0; i < N; i++) 
    {
        positions[i] = -1;
    }

    // To check column and the two diagonals is enough, don't need to check row
    bool* colCheck = new bool[N];
    bool* diagFCheck = new bool[2 * N - 1];
    bool* diagSCheck = new bool[2 * N - 1];

    for(int i = 0; i < N; i++) 
    {
        colCheck[i] = false;
    }
    for(int i = 0; i < 2 * N - 1; i++) 
    {
        diagFCheck[i] = false;
        diagSCheck[i] = false;
    }
    
    
    Stack<State> stack; 

    ofstream outFile;
    string fileName = to_string(N) + "queens_solutions.txt";
    outFile.open(fileName);

    int solutionCount = 0;

    // initial state
    State currentState;
    currentState.row = 0;
    currentState.col = -1; // Will be 0 right after being incremented
    // currentState.col = 0; // this doesn't work

    while(true) 
    {
        currentState.col += 1; // needed bc of the -1

        while(currentState.col < N && (colCheck[currentState.col] || diagFCheck[currentState.row + currentState.col] || diagSCheck[N - 1 + currentState.col - currentState.row])) 
        {
            currentState.col += 1;
        }

        if(currentState.col < N) 
        {
            // we should save where the queen is
            positions[currentState.row] = currentState.col;
            colCheck[currentState.col] = true;
            diagFCheck[currentState.row + currentState.col] = true;
            diagSCheck[N - 1 + currentState.col - currentState.row] = true;

            if(currentState.row == N - 1) // checking if we are at the last row
            {
                solutionCount++;
                outFile << "Solution " << solutionCount << ": [";
                for(int i = 0; i < N; i++) 
                {
                    outFile << positions[i];
                    if(i != N -1) outFile << ", ";
                }
                outFile << "]" << endl;
                removeQueen(currentState, N, colCheck, diagFCheck, diagSCheck, positions);
                while(currentState.col >= N - 1) // Backtracking part
                {
                    if(stack.isEmpty()) 
                    {
                        goto end;  
                    }
                    currentState = stack.top();
                    stack.pop();
                    removeQueen(currentState, N, colCheck, diagFCheck, diagSCheck, positions);
                }
            } else {
                // Put current state in the stack
                stack.push(currentState);

                // Move to next row
                currentState.row += 1;
                currentState.col = -1;
            }
        } else {
            // Backtrack
            if(stack.isEmpty()) 
            {
                break; // All solutions found
            }
            currentState = stack.top();
            stack.pop();

            removeQueen(currentState, N, colCheck, diagFCheck, diagSCheck, positions);
        }
    }
end:
    outFile.close();

    // Opening the file again to put the total solutions at the top
    ifstream inFile(fileName);
    string fileContent;
    string line;
    while(getline(inFile, line)) 
    {
        fileContent += line + "\n";
    }
    inFile.close();

    // Write total solutions and the rest
    outFile.open(fileName);
    outFile << "Total solutions for N=" << N << ": " << solutionCount << endl;
    outFile << fileContent;
    outFile.close();

    cout << "Solutions have been saved to '" << fileName << "'" << endl;

    // Cleaning up
    delete[] positions;
    delete[] colCheck;
    delete[] diagFCheck;
    delete[] diagSCheck;

    return 0;
}
