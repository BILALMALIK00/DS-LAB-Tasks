#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data=d;
        next=NULL;
        prev=NULL;
    }
};

void insertfromtail(Node*& head, Node*& tail, int v) {
    Node* temp=new Node(v);
    if (head==NULL) {
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

void displayfromhead(Node* head){
    Node* temp = head;
    if(head==NULL){
		return;
}
    do {
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;
}

Node*getnode(Node*head,int index) {
    Node*curr=head;
    int cnt=1;
    if (head==NULL){
	return NULL;
}
    do{
        if(cnt==index){
        	return curr;
		}
        curr=curr->next;
        cnt++;
    } while (curr != head);
    	return NULL;//if index not equal means there is no node on that index and return null
}

Node* nodeswapping(Node* head,Node*&tail,int index1,int index2){
	Node*temp1=NULL;
	Node*temp2=NULL;
	Node*temp3=NULL;
	Node*temp4=NULL;
    if(index1==index2){
	 	return head;
}
    Node*node1=getnode(head,index1);
    Node*node2=getnode(head,index2);
    if (node1==NULL||node2==NULL) {
        cout<<"INVALID INDEX"<<endl;
        return head; 
    }
    Node*node1_prev=node1->prev;
    Node*node1_next=node1->next;
    Node*node2_prev=node2->prev;
    Node*node2_next=node2->next;
    if (node1->next==node2){  // handling adjacent nodes case
        node1->next=node2_next;
        node1->prev=node2;
        node2->next=node1;
        node2->prev=node1_prev;
        node1_prev->next=node2;
        node2_next->prev=node1;
}
	 else if(node2->next==node1){ 
        node2->next=node1_next;
        node2->prev=node1;
        node1->next=node2;
        node1->prev=node2_prev;
        node2_prev->next=node1;
        node1_next->prev=node2;
    } else{
        temp1=node1->prev;
		temp1->next = node2;//handling remaining cases
        temp2 = node1->next;
		temp2->prev=node2;
        temp3=node2->prev;
		temp3->next = node1;
      	temp4=node2->next;
	  	temp4->prev = node1;
        swap(node1->next,node2->next);
        swap(node1->prev,node2->prev);//swapping node1 and node2 next and prev pointers
    }
    if(index1==1){
    	head=node2;
    }
    else if(index2==1){
	 head=node1;
}
    if (node1==tail) {
        tail=node2;
    } else if(node2==tail) {
        tail=node1;
    }
     head->prev=tail;
    tail->next=head;
    return head;

}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertfromtail(head,tail,1);
    insertfromtail(head,tail,7);
    insertfromtail(head,tail,4);
    insertfromtail(head,tail,2);
    insertfromtail(head,tail,6);
    insertfromtail(head,tail,4);
    insertfromtail(head,tail,5);
    insertfromtail(head,tail,3);
    insertfromtail(head,tail,9);
    insertfromtail(head,tail,8);
    cout << "ORIGINAL LIST:" << endl;
    displayfromhead(head);
    int ind1=0;
    int ind2=0;
	cout<<"ENTER INDEX OF NODE TO SWAP:";
	cin>>ind1;
	cout<<"ENTER ANOTHER INDEX OF NODE TO SWAP:";
	cin>>ind2;
    head = nodeswapping(head,tail,ind1,ind2);
    cout << "LIST AFTER SWAPPING NODES:"<< endl;
    displayfromhead(head);
    //cout<<"head:"<<head->data<<endl;
    //cout<<"tail:"<<tail->data<<endl;
}
