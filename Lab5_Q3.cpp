#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node*next;
		Node(int d){
			data=d;
			next=NULL;
		}
};
void insertatail(Node*&head,Node*&tail,int val){
	Node*temp=new Node(val);
	if(head==NULL){
		head=temp;
		tail=temp;
	}else{
		tail->next=temp;
		tail=temp;
	}
}
bool searchnumber(Node*head,int target){
	if(head==NULL){
		return false;
	}
bool number_present=searchnumber(head->next,target);
	if(head->data==target){
		return true;
	}
	return number_present;
}
int main(){
		Node*head=NULL;
	Node*tail=NULL;
	insertatail(head,tail,1);
	insertatail(head,tail,9);
	insertatail(head,tail,1);
	insertatail(head,tail,2);
	insertatail(head,tail,5);
	insertatail(head,tail,4);
	insertatail(head,tail,3);
	int num;
	cout<<"enter number to search"<<endl;
	cin>>num;
	if(searchnumber(head,num)){
		cout<<"Number "<<num<< " found"<<endl;
	}else{
		cout<<"Number "<<num<<" not found"<<endl;
	}
}
