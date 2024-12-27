#include<iostream>
using namespace std;
class date
{
	public:
	int date[5];
	int year[5];
	int month[5];
	
};
void sorting(date &d1){
	int min;
	for(int i=0;i<5;i++){
		min=i;
		for(int j=i+1;j<5;j++){
if(d1.year[j]<d1.year[min]||(d1.year[j]==d1.year[min]&&d1.month[j]<d1.month[min])||(d1.year[j]==d1.year[min]&&d1.month[j]==d1.month[min]&&d1.date[j]<d1.date[min])){
				min=j;
			}
		}
		int tempdate=d1.date[i];
		d1.date[i]=d1.date[min];
		d1.date[min]=tempdate;
		
		int tempmonth=d1.month[i];
		d1.month[i]=d1.month[min];
		d1.month[min]=tempmonth;
		int tempyear=d1.year[i];
		d1.year[i]=d1.year[min];
		d1.year[min]=tempyear;
	}
}
bool validation(int date,int month){
	if(month<1||month>12){
		return false;
	}
	if(date<1||date>31){
		return false;
	}
    if ((month==4||month==6||month==9||month==11)&&date>30){
	return false; 
}
 if (month==2&&date>28) {
	return false;
}
return true;
}
void display(date d1){
	for(int i=0;i<5;i++){
		cout<<d1.date[i]<<"/"<<d1.month[i]<<"/"<<d1.year[i]<<endl;
	}
}
int main(){
	date d1;
	for(int i=0;i<5;i++){
		do{
		cout<<"ENTER DATE:";
		cin>>d1.date[i];
		cout<<"ENTER MONTH:";
		cin>>d1.month[i];
		cout<<"ENTER YEAR:";
		cin>>d1.year[i];
		  if(!validation(d1.date[i],d1.month[i])){
                cout<<"INVALID INPUT ENTER AGAIN"<<endl;
            }
}while(!validation(d1.date[i],d1.month[i]));
}
	sorting(d1);
	display(d1);
}
