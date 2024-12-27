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
int getlength(Node*head,int cnt){
	Node*temp=head;
	if(head==NULL){
		return cnt;
	}
	return getlength(temp->next,cnt+1);
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
	int cnt=0;
	int length=getlength(head,0);
	cout<<"Length of LinkList is "<< length<<endl;
}
