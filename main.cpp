#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
#include <sstream>
#include <stack>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;

    stringstream ss(line);

    string temp;

    while (getline(ss, temp, ' '))
    {
        tokens.push_back(Token(temp));
    }

        return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op)
{

    if (op == "(")
    {
        return 4;
    }

    if (op == ")")
    {
        return 3;
    }

    if (op == "*" || op == "/")
    {
        return 2;
    }

    if (op == "+" || op == "-")
    {
        return 1;
    }

    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {

    int counter = 0;

    for (int i = 0; i < tokens.size(); i++)
    {

        if (isdigit(tokens[i].value[0]))
        {
            counter++;

        } else if (isOperator(tokens[i].value))
        {

            if (counter < 2)
            {
                return false;
            }

            counter--;
        }

    }

    return counter == 1;
}

bool isValidInfix(const vector<Token>& tokens) {

    if (tokens.size() % 2 == 0)
    {
        return false;
    }

    bool nextIsOp = false;

    int counter = 0;

    for (int i = 0; i < tokens.size(); i++)
    {

        if (isdigit(tokens[i].value[0]))
        {

            if (nextIsOp)
            {
                return false;
            }

            nextIsOp = true;

        }

        else if (isOperator(tokens[i].value))
        {

            if (!nextIsOp)
            {
                return false;
            }

            nextIsOp = false;

        }

        else if (tokens[i].value == "(")
        {

            if (nextIsOp)
            {
                return false;
            }

            counter++;

        }

        else if (tokens[i].value == ")")
        {

            if (!nextIsOp)
            {
                return false;
            }

            counter--;
        }

    }

    return nextIsOp && counter == 0;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;

    stack<Token> tempStack;

    for (int i = 0; i < tokens.size(); i++)
    {

        if (isdigit(tokens[i].value[0]))
        {

            output.push_back(tokens[i]);

        } else if (isOperator(tokens[i].value))
        {

            while (!tempStack.empty() && precedence(tokens[i].value) <=
                precedence(tempStack.top().value))
            {

                output.push_back(tempStack.top());
                tempStack.pop();

            }

            tempStack.push(tokens[i]);

        }

    }

    while (!tempStack.empty())
    {
        output.push_back(tempStack.top());
        tempStack.pop();
    }

    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;

    for (int i = 0; i < tokens.size(); i++)
    {

        if (isdigit(tokens[i].value[0]))
        {

            stack.push(stoi(tokens[i].value));

        } else if (isOperator(tokens[i].value))
        {

            double numTop = stack.top();
            stack.pop();

            double numBot = stack.top();
            stack.pop();


            if (tokens[i].value == "+")
            {

                stack.push(numBot + numTop);

            } else if (tokens[i].value == "-")
            {

                stack.push(numBot - numTop);

            } else if (tokens[i].value == "*")
            {

                stack.push(numBot * numTop);

            } else if (tokens[i].value == "/")
            {

                stack.push(numBot / numTop);

            }

        }

    }

    return stack.top();
}

// Main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}