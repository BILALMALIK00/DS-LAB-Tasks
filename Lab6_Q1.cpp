#include<iostream>
#include<cstring>
using namespace std;
class stack {
	private:
		int top;
		int size;
		char *arr;
	public:
		stack(int s) {
			size=s;
			arr=new char[size];
			top=-1;
		}
		void push(char val) {
			if(top<size-1) {
				top++;
				arr[top]=val;
			} else {
				cout<<"stack is full"<<endl;
			}
		}
		void pop() {
			if(top!=-1) {
				top--;

			} else {
				cout<<"stack is empty"<<endl;
			}
		}
		bool isempty() {
			if(top==-1) {
				return true;
			}
			return false;
		}
		bool isfull() {
			if(top==size-1) {
				return true;
			}
			return false;
		}
		char gettop() {
			if(top!=-1) {
				return arr[top];
			}else{
				return '\0';
			}

		}
		~stack(){
			delete[]arr;
}

};
bool ispalindrome(string name) {
	stack s(name.size());
	for(int i=0; name[i]!='\0'; i++) {
		s.push(name[i]);
	}
	for(int i=0; i<name.size(); i++) {
		if(name[i]!=s.gettop()) {
			return false;
		}
		s.pop();
	}
	return true;
}
int main(){
		string name="BORROWROB";
		if(ispalindrome(name)) {
		cout<<"It is palindrome"<<endl;
	} else {
		cout<<"It is not a palindrome"<<endl;
}
}
