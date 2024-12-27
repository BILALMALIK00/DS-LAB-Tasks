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
void insertattail(Node*&head,Node*&tail,int val){
	Node*temp=new Node(val);
	if(head==NULL){
		head=temp;
		tail=temp;
	}else{
		tail->next=temp;
		tail=temp;
	}
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
Node*evenodd(Node*&head){
	Node*head1=NULL;
	Node*tail1=NULL;
	Node*head2=NULL;
	Node*tail2=NULL;
	Node*curr=head;
	while(curr!=NULL){
		if(curr->data%2==0){
			insertattail(head1,tail1,curr->data);
		}else{
			insertattail(head2,tail2,curr->data);
		}
		curr=curr->next;
	}
	if(head1!=NULL&&head2!=NULL){
		tail1->next=head2;
		return head1;
	}else if(head1!=NULL){
		return head1;
	}else{
		return head2;
	}
}
int main(){
	Node*head=NULL;
	Node*tail=NULL;
	insertattail(head,tail,17);
	insertattail(head,tail,15);
	insertattail(head,tail,8);
	insertattail(head,tail,12);
	insertattail(head,tail,10);
	insertattail(head,tail,5);
	insertattail(head,tail,4);
	insertattail(head,tail,1);
	insertattail(head,tail,7);
	insertattail(head,tail,6);
	cout<<"ORIGINAL LIST"<<endl;
	display(head);
	cout<<"AFTER MODIFICATION"<<endl;
	Node*eve=evenodd(head);
	display(eve);
}
