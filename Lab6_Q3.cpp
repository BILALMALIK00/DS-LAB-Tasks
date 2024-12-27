#include<iostream>
#include<cmath>
#include<string>
#include<sstream>  
using namespace std;
class Node {
    public:
    string data;
    Node* next;
    Node(string d) {
        data = d;
        next = NULL;
    }
};

class stack {
    private:
        Node* top;
    public:
        stack() {
            top = NULL;
        }
        void push(string val) {
            Node* temp = new Node(val);
            if (top == NULL) {
                top = temp;
            } else {
                temp->next = top;
                top = temp;
            }
        }
        string pop() {
            if (top == NULL) {
                return "";
            }
            Node* temp = top;
            string val = temp->data;
            top = top->next;
            delete temp;
            return val;
        }
        void display() {
            Node* temp = top;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        bool isEmpty() {
            return top == NULL;
        }
        string peek() {
            if (top == NULL) {
                return "";
            } else {
                return top->data;
            }
        }
};
double string_to_double(const string& s) {
    stringstream s_(s);
    double result;
    s_ >>result;
    return result;
}
string double_to_string(double num) {
    stringstream s;
    s << num;
    return s.str();
}

int precedence(char c) {
    if (c == '^') {
        return 3;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}

string infixtopostfix(const string& infix) {
    string postfix = " ";
	stack s1;
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c) || c == '.') {
            postfix += c;
        } else if (c == '(') {
            char str[2];  
    		str[0] = c;   
    		str[1] = '\0'; 
    		s1.push(str);
            postfix += ' ';
        } else if (c == ')') {
            postfix += ' ';
            while (!s1.isEmpty() && s1.peek() != "(") {
                postfix += s1.pop();
            }
            s1.pop();
        } else if (isOperator(c)) {
            postfix += ' ';
            while (!s1.isEmpty() && precedence(s1.peek()[0]) >= precedence(c)) {
                postfix += s1.pop();
            }
            char str[2];  
    		str[0] = c;   
    		str[1] = '\0'; 
    		s1.push(str);
        }
    }
    while (!s1.isEmpty()) {
        postfix += ' ';
        postfix += s1.pop();
    }
    return postfix;
}

double calculation(const string& postfix) {
    stack s1;
    string ans = " ";
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isdigit(c) || c == '.') {
            ans += c;
        }
        else if (c == ' ' && ans != " ") {
            double ans_ = string_to_double(ans); 
            s1.push(double_to_string(ans_));      
            ans = " ";
        } else if (isOperator(c)) {
            double val1 = string_to_double(s1.pop());
            double val2 = string_to_double(s1.pop());
            switch (c) {
            case '+':
                s1.push(double_to_string(val2 + val1));
                break;
            case '-':
                s1.push(double_to_string(val2 - val1));
                break;
            case '*':
                s1.push(double_to_string(val2 * val1));
                break;
            case '/':
                s1.push(double_to_string(val2 / val1));
                break;
            case '^':
                s1.push(double_to_string(pow(val2, val1)));
                break;
            default:
                cout << "Invalid operator" << endl;
            }
        }
    }
    return string_to_double(s1.pop());
}

int main() {
    string equation = "12+13-5*(0.5+0.5)+1";
    stack s1;
    s1.push("x");
    s1.push("=");
    s1.push("12");
    s1.push("+");
    s1.pop();
    s1.pop();
    string postfix = infixtopostfix(equation);
    double result = calculation(postfix);
    s1.push(double_to_string(result));
    s1.display();
    cout << "Answer is: " << result << endl;
}

