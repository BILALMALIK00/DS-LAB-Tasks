#include<iostream>
using namespace std;
class Node {
	public:
		int data;
		Node*prev;
		Node*next;
		Node(int d) {
			data=d;
			next=NULL;
			prev=NULL;
		}
};
class DoublycircularLL {
	public:
		Node*head=NULL;
		Node*tail=NULL;
		void insertattail(int v) {
			Node*temp=new Node(v);
			if(head==NULL) {
				head=temp;
				tail=temp;
				tail->next=head;
				head->prev=tail;
			} else {
				tail->next=temp;
				temp->prev=tail;
				tail=temp;
				tail->next=head;
				head->prev=tail;
			}
		}
		void insertfromhead(int v) {

			Node*temp=new Node(v);
			if(head==NULL) {
				head=temp;
				tail=temp;
				tail->next=head;
				head->prev=tail;
			} else {
				temp->next=head;
				head->prev=temp;
				head=temp;
				tail->next=head;
				head->prev=tail;
			}
		}
void insertatanyposition(int pos, int val) {
   if(pos==1){
   	insertfromhead(val);
   	return;
   }
   if(pos<1){
   	cout<<"Invalid Position"<<endl;//start from 1
   	return;
   }
   int cnt=1;
   Node*curr=head;
   Node*prev=NULL;
   curr=curr->next;
   cnt++;
   if(curr!=NULL){
   while(curr!=head){
   	curr=curr->next;
   	cnt++;
   }
}
   	if(pos>cnt||pos<1) {
	cout<<"Invalid Position"<<endl;
	return;
}
	cnt=1;
	curr=head;
		while(cnt<pos) {
		if(curr!=NULL) {
			prev=curr;
			curr=curr->next;
			cnt++;
				}
			}
			Node*newnode=new Node(val);
			prev->next=newnode;
			newnode->prev=prev;
			newnode->next=curr;
			curr->prev=newnode;
			if(curr==head) {
			tail=newnode;
			}
			tail->next=head;
			head->prev=tail;
   }
   
   void deletion(int pos){
   	if(pos<1){
   		cout<<"OUT OF BOUND"<<endl;
   		return;
	   }
   int cnt=1;
	Node*curr=head;
	Node*prev=NULL;
	if(head==NULL){
	cout<<"LIST IS EMPTY"<<endl;
	return;
	}
			
	if(pos==1) {
		if(head==tail){
		head=NULL;
		tail=NULL;
		delete head;
		cout<<"Deleted"<<endl;
	}else{
		head=head->next;
		tail->next=head;
		head->prev=tail;
		curr->prev=NULL;
		delete curr;
}
		return;
			}
			
		do {
			prev=curr;
			curr=curr->next;
			cnt++;
		} while(curr!=head&&cnt<pos);
				
			if(pos>cnt||curr==head){
				cout<<"OUT OF BOUND KINDLY PROVIDE CORRECT POSITION TO DELETE"<<endl;
				return;
			}
				Node*temp=NULL;
				temp=curr->next;
				prev->next=temp;
				temp->prev=prev;
				if(curr==tail){
					tail=prev;
					tail->next=head;
					head->prev=tail;
				}
				curr->next=NULL;
				curr->prev=NULL;
				delete curr;
			}	
   

		void displayfromhead() { // displaying from head
			Node*temp=head;
			do {
				cout<<temp->data<<"->";
				temp=temp->next;
			} while(temp!=head);
			cout<<endl;
		}

		void displayfromtail() {
			if(tail==NULL){
				return;
			}
			Node*temp=tail;
			do {
				cout<<temp->data<<"->";
				temp=temp->prev;
			} while(temp!=tail);
			cout<<endl;
		}

};
int main() {
	DoublycircularLL l1;
	l1.insertattail(3);
	l1.displayfromhead();
	l1.insertattail(6);
	l1.displayfromhead();
	l1.displayfromtail();
	l1.insertfromhead(8);
	l1.displayfromhead();
	DoublycircularLL l2;
	l2.insertfromhead(7);
	l2.insertfromhead(9);
	l2.displayfromhead();
	DoublycircularLL l3;
l3.insertatanyposition(1,1);
l3.insertatanyposition(2,2);
l3.insertatanyposition(3,3);
l3.insertatanyposition(4,5);
l3.insertatanyposition(5,5);
l3.insertatanyposition(6,3);
l3.insertattail(6);
l3.insertfromhead(4);
l3.displayfromhead();
l3.deletion(6);
l3.displayfromhead();
l3.deletion(1);
l3.displayfromhead();
l3.deletion(2);
l3.displayfromhead();
cout<<"head:"<<l3.head->data<<endl;//checking 
cout<<"Tail:"<<l3.tail->data<<endl;
l3.insertattail(11);
l3.insertatanyposition(1,10);
l3.insertfromhead(1);
l3.insertatanyposition(8,90);
l3.displayfromhead();
cout<<"head:"<<l3.head->data<<endl;//checking 
cout<<"Tail:"<<l3.tail->data<<endl;
DoublycircularLL l4;
l4.insertatanyposition(1,20);
l4.deletion(1);
}

