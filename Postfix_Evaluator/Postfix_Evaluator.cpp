#include <bits/stdc++.h>
#include <sstream>
using namespace std;
int EvaluatePostfix(const string& expression)
{
    stack <int >st;
    string op;
    stringstream s(expression);
    while (getline(s, op, ' '))
    {
        if (op == "+" || op == "-" || op == "*" || op == "/")
        {
            if (st.size() < 2)
            {
                cout << "Invalid postfix expression: insufficient operands.";
                break;
            }
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            if (op == "+")
            {
                st.push(operand1 + operand2);
            }
            else if (op == "-")
            {
                st.push(operand1 - operand2);
            }
            else if (op == "*")
            {
                st.push(operand1 * operand2);
            }
            else if (op == "/")
            {
                if (operand2 == 0)
                {
                    cout << "Division by zero is not allowed.";
                    break;
                }
                st.push(operand1 / operand2);
            }
        }
        else
        {
            int operand = stoi(op);
            st.push(operand);
        }
    }
    if (st.size() != 1)
    {
        cout << "Invalid postfix expression: too many operands.";

    }
    else
    {
        return st.top();
    }

}
int main()
{


    string expression;
    cout << "Enter a postfix expression :  ";
    getline(cin, expression);

    int result = EvaluatePostfix(expression);
    cout << "The result of the expression is: " << result << endl;


}