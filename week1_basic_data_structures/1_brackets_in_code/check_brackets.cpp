#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket
{
    Bracket(char type, int position) : type(type),
        position(position)
    {
    }

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);

    stack<Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position)
    {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            if (position + 1 == text.length()) {
                cout << position + 1;
                return 0;
            }

            Bracket bracket(next, position);
            opening_brackets_stack.push(bracket);
            continue;
        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.empty()) {
                cout << position + 1;
                return 0;
            }

            char open = opening_brackets_stack.top().type;
            if (open == '(' && next == ')' || open == '[' && next == ']' || open == '{' && next == '}') {
                opening_brackets_stack.pop();
            } else {
                cout << position + 1;
                return 0;
            }
        }
    }

    if (!opening_brackets_stack.empty()) {
        cout << opening_brackets_stack.top().position + 1;
    } else {
        cout << "Success";
    }

    return 0;
}
