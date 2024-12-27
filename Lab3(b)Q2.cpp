#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node*next;
		Node*prev;
		Node(int d){
			data=d;
			next=NULL;
			prev=NULL;
		}
};
Node*combining(Node*head1,Node*head2,Node*tail1,Node*tail2){
	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}
	
	tail1->next=head2;
	head2->prev=tail1;
	tail2->next=head1;
    head1->prev=tail2;
	return head1;
}
void insertattail(Node*&head,Node*&tail,int v){
	Node*temp=new Node(v);
	if(head==NULL){
		head=temp;
		tail=temp;
		 temp->next = head;
        head->prev = tail;
	}else{
		tail->next=temp;
        temp->prev=tail;
        tail=temp;
         temp->next = head;
        head->prev = tail;
	}
}
void display(Node* head) {
    if (head == NULL){
	 return ;
    
}
    Node*temp=head;
    do{
        cout<<temp->data << "->";
        temp = temp->next;
    } while(temp!=head);
    cout<<endl;
}

int main(){
	Node*head=NULL;
	Node*tail=NULL;
	insertattail(head,tail,1);
	insertattail(head,tail,7);
	insertattail(head,tail,9);
	insertattail(head,tail,2);
	cout<<"LIST L"<<endl;
	display(head);
	Node*newhead=NULL;
	Node*newtail=NULL;
	insertattail(newhead,newtail,9);
	insertattail(newhead,newtail,8);
	insertattail(newhead,newtail,7);
	insertattail(newhead,newtail,4);
	cout<<"LIST M"<<endl;
	display(newhead);
	cout<<"COMBINED"<<endl;
	Node*temp=combining(head,newhead,tail,newtail);
	display(temp);

	
}
