#include<iostream>
using namespace std;
//in question it wasnt mention either linklist is singly or doubly so i chose singly but same method can be used for doubly linklist just we have to update prev pointer
class Node{
	public:
		int data;
		Node*next;
		Node(int d){
			data=d;
			next=NULL;
		}
};
void insertattail(Node*& head, Node*& tail,int val) {
    Node* temp=new Node(val);
    if (head==NULL) {
        head=temp;
        tail=temp;
    } else{
        tail->next=temp;
        tail=temp;
    }
}
void display(Node*head){
	Node*curr=head;
	while(curr!=NULL){
		cout<<curr->data<<"->";
		curr=curr->next;

	}
	cout<<endl;
}
Node*reverse(Node*head){
	Node*curr=head;
	Node*prev=NULL;
	Node*forward=NULL;
	while(curr!=NULL){
		forward=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forward;
	}
	return prev;
}

Node*alternate2(Node*head,Node*tail){
	Node*curr=head;
	Node*prev=NULL;
	Node*temp=NULL;
	if(head==NULL||head->next==NULL){
		return head;
	}
	Node*newhead=NULL;
	while(curr!=NULL&&curr->next!=NULL){
		temp=curr->next;
		curr->next=temp->next;
		temp->next=newhead;	//basically similar tu insertathead function 
		newhead=temp;
		prev=curr;
		curr=curr->next;
}
	if(prev!=NULL){
		prev->next=newhead;
	}else{
		head=newhead;
	}
	return head;
}
Node*alternate(Node*head,Node*tail){//it uses extra space to reverse nodes 
	Node*curr=head;
	Node*prev;
	Node*newhead=NULL;
	Node*newtail=NULL;
	Node*newnode=NULL;
		if(head==NULL||head->next==NULL){
		return head;
	}
while(curr!=NULL&&curr->next!=NULL){
	newnode=curr->next;
	curr->next=newnode->next;
	newnode->next=NULL;
	insertattail(newhead,newtail,newnode->data);
	prev=curr;
	curr=curr->next;
}
	newhead=reverse(newhead);
	if(prev!=NULL){
		prev->next=newhead;
	}else{
		head=newhead;
	}
	return head;
}
int main(){
	Node*head=NULL;
	Node*tail=NULL;
	Node*newhead=NULL;
	Node*newtail=NULL;
	insertattail(head,tail,10);
	insertattail(head,tail,4);
	insertattail(head,tail,9);
	insertattail(head,tail,1);
	insertattail(head,tail,3);
	insertattail(head,tail,5);
	insertattail(head,tail,9);
	insertattail(head,tail,4);
	cout<<"Original"<<endl;
	display(head);
	cout<<"By Method 1:"<<endl;
	Node*al=alternate(head,tail);
	display(al);
	insertattail(newhead,newtail,10);
	insertattail(newhead,newtail,4);
	insertattail(newhead,newtail,9);
	insertattail(newhead,newtail,1);
	insertattail(newhead,newtail,3);
	insertattail(newhead,newtail,5);
	insertattail(newhead,newtail,9);
	insertattail(newhead,newtail,4);
	cout<<"Without Extra Space"<<endl;
	Node*al2=alternate2(newhead,newtail);
	display(al2);
}
