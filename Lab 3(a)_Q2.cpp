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
void insertattail(Node*&head,Node*&tail,int v){
	Node*temp=new Node(v);
	if(head==NULL){
		head=temp;
		tail=temp;
	}else{
		tail->next=temp;
		tail=temp;
	}
}
	Node*middle(Node*head){
	Node*fast=head->next;
	Node*slow=head;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
		}
		slow=slow->next;
	}
	return slow;
}
Node*Reverse(Node*head){
	Node*curr=head;
	Node*prev=NULL;
	Node*nextnode=NULL;
	while(curr){
		nextnode=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextnode;
	}
	return prev;
}
bool ispalindrome(Node*head){
	if(head==NULL||head->next==NULL){
		return true;
	}
	Node*curr=head;
	Node*mid=middle(curr);
	Node*rev=Reverse(mid->next);
	Node*head2=rev;
	Node*head1=head;
	while(head2!=NULL){
		if(head1->data!=head2->data){
			return false;
		}
		head2=head2->next;
		head1=head1->next;
	}
	mid->next = Reverse(rev);
	return true;
}
void display(Node*head){
	Node*temp=head;
	while(temp){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
	cout<<endl;
}
int main(){
	Node*head=NULL;
	Node*tail=NULL;
	insertattail(head,tail,2);
	insertattail(head,tail,0);
	insertattail(head,tail,2);
	display(head);
	if(ispalindrome(head)){
		cout<<"YES LINKLIST IS A PALINDROME"<<endl;
	}else{
	cout<<"NO LINKLIST IS NOT A PALINDROME"<<endl;
	}
}
