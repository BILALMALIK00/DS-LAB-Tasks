#include<iostream>
using namespace std;
class queue{
	public:
		int front;//pop--->front
		int rear;//push-->rear 
		int size;
		int *arr;
		queue(int s){
			size=s;
			arr=new int[size];
			front=0;
			rear=0;
		}
		void enqueue(int val){
			if(!isfull()){
				arr[rear]=val;
				rear++;
			}else{
				cout<<"queue is full"<<endl;
			}
		}
	int  dequeue(){
		int val;
			if(front==rear){
				cout<<"Empty"<<endl;
				return -1;
			}else{
				val=arr[front];
				arr[front]=-1;
				front++;
			}
			if(front==rear){
				rear=0;
				front=0;
			}
			return val;
		}
		bool isempty(){
			if(front==rear){
				return true;
			}
			return false;
		}
		bool isfull(){
			if(rear==size){
				return true;
			}
			return false;
		}
		void display(){
			if(isempty()){
				cout<<"Empty"<<endl;
				return;
			}
		for(int i=front;i<rear;i++){
			cout<<arr[i]<<" ";
		}
			cout<<endl;
		}
		~queue(){
			delete[]arr;
		}
};
int main(){
	queue q1(7);
	int custumer_ids[]={13,7,4,1,6,8,10};
	int size=sizeof(custumer_ids)/sizeof(custumer_ids[0]);
	for(int i=0;i<size;i++){
		q1.enqueue(custumer_ids[i]);
	}
	q1.display();
	cout<<"Checkouts"<<endl;
	for(int i=0;i<size;i++){
		cout<<"Checking out ID:"<<q1.dequeue()<<endl;
	}
	
cout<<"All checked out"<<endl;	






}
