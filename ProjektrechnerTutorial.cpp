// CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void printHelp()
{
    cout << "========================================" << endl;
    cout << "      Calculator Console Application    " << endl;
    cout << "========================================" << endl << endl;
    cout << "Format:  a+b  |  a-b  |  a*b  |  a/b" << endl << endl;
    cout << "Beispiele:" << endl;
    cout << "  3+4     ergibt   7" << endl;
    cout << "  10-5    ergibt   5" << endl;
    cout << "  6*7     ergibt   42" << endl;
    cout << "  15/3    ergibt   5" << endl;
    cout << "  2.5*4   ergibt   10" << endl << endl;
    cout << "Zum Beenden 'q' eingeben." << endl;
    cout << "----------------------------------------" << endl << endl;
}

int main()
{
    printHelp();

    string input;

    while (true)
    {
        cout << "Eingabe: ";
        cin >> input;

        if (input == "q" || input == "Q" || input == "exit")
        {
            cout << "Auf Wiedersehen!" << endl;
            break;
        }

        // Find operator (start at 1 to allow negative first number, e.g. -5+3)
        size_t opPos = string::npos;
        char op = 0;

        for (size_t i = 1; i < input.size(); i++)
        {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                opPos = i;
                op = c;
                break;
            }
        }

        if (opPos == string::npos || opPos == input.size() - 1)
        {
            cout << "Ungueltige Eingabe. Beispiel: 3+4" << endl << endl;
            continue;
        }

        string leftStr  = input.substr(0, opPos);
        string rightStr = input.substr(opPos + 1);

        double a = 0.0, b = 0.0;
        try
        {
            a = stod(leftStr);
            b = stod(rightStr);
        }
        catch (...)
        {
            cout << "Ungueltige Zahlen. Beispiel: 3+4" << endl << endl;
            continue;
        }

        if (op == '/' && b == 0.0)
        {
            cout << "Fehler: Division durch Null!" << endl << endl;
            continue;
        }

        double result = 0.0;
        switch (op)
        {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
        }

        cout << input << " = " << result << endl << endl;
    }

    return 0;
}
