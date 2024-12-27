#include<iostream>
using namespace std;
class Node {
	public:
		int data;
		Node*next;
		Node(int d) {
			data=d;
			next=NULL;
		}
};
class singlyLL {
	public:
		Node*head=NULL;
		Node*tail=NULL;

		void insertattail(int v) {
			Node*temp=new Node(v);
			if(head==NULL) {
				head=temp;
				tail=temp;
				tail->next=head;
			} else {
				tail->next=temp;
				tail=temp;
				temp->next=head;
			}
		}
		void display() {
			Node*temp=head;
			do {
				cout<<temp->data<<"->";
				temp=temp->next;
			} while(temp!=head);
			cout<<endl;
		}
		void insertathead(int v) {
			Node*temp=new Node(v);
			if(head==NULL) {
				head=temp;
				tail=temp;
				temp->next=head;
			} else {
				temp->next=head;
				head=temp;
				tail->next=head;
			}
		}

		void insertatmiddle(int pos,int val) {
			int cnt=1;
			Node*prev=NULL;
			Node*curr=head;
			if(head==NULL) {
				cout<<"List is empty"<<endl;
				return;
			}
			do {
				curr=curr->next;
				cnt++;
			} while(curr!=head);
			if(pos>cnt||pos<1) {
				cout<<"Invalid Position"<<endl;
				return;
			}
			cnt=1;
			curr=head;
			if(pos==1) {
				insertathead(val);
				return;
			}
			while(cnt<pos) {
				if(curr!=NULL) {
					prev=curr;
					curr=curr->next;
					cnt++;
				}
			}
			Node*newnode=new Node(val);
			prev->next=newnode;
			newnode->next=curr;
			if(curr==head) {
				tail=newnode;
			}
			tail->next=head;
		}

		void Deletion(int pos) {
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
					cout<<"Deleted"<<endl;
				}else{
				head=head->next;
				curr->next=NULL;
				tail->next=head;
			}
				delete curr;
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
				if(curr==tail){
					tail=prev;
				}
				curr->next=NULL;
				delete curr;
			}
};
int main() {
	cout<<"DEMONSTRATING WHOLE CODE"<<endl;
	singlyLL l1;
	l1.insertattail(1);
	l1.insertattail(2);
	l1.insertattail(3);
	l1.insertattail(4);
	l1.insertattail(5);
	cout<<endl;
	l1.insertatmiddle(6,7);
	l1.insertatmiddle(7,8);//so basically insertatmiddle function is also insert at any postion
	l1.insertatmiddle(1,5);//we can use insertatmidle to insert at head,tail,middle
	l1.insertatmiddle(11,15);
	l1.insertattail(10);
	cout<<"head->"<<l1.head->data<<endl;//checking head and tail
	cout<<"tail->"<<l1.tail->data<<endl;
	l1.display();
	l1.Deletion(1);
	l1.display();
	l1.Deletion(2);
	l1.display();
	l1.Deletion(4);
	l1.display();
	l1.Deletion(5);
	l1.display();
	l1.Deletion(6);
	l1.display();
	l1.Deletion(1);
	l1.display();
	cout<<"head->"<<l1.head->data<<endl;//checking head and tail
	cout<<"tail->"<<l1.tail->data<<endl;	
	l1.Deletion(4);
	l1.display();
	cout<<"head->"<<l1.head->data<<endl;//checking head and tail
	cout<<"tail->"<<l1.tail->data<<endl;
	l1.insertatmiddle(3,10);
	l1.display();
	l1.Deletion(3);
	l1.display();
}
