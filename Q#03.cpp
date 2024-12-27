//k230026
#include<iostream>
using namespace std;
class document{
    private:
    string *text;
    public:
    document(string d){
        text=new string(d);
       

    }
    //following rule of 3
    ~document(){// destructor
        delete text;
    }
    document(const document &t){ //copy constructor
        text=new string(*t.text);
       
    }
    document&operator=(const document &t){//assignment operator
    if(this==&t){
        return *this;
    }
    delete text;
        text=new string(*t.text);
       return *this;

    }
    void display(){
                cout<<"TEXT:"<<*text<<endl;

    }
    void settext(string t){
        *text=t;
    }
};
int main(){
    document d1("this file is safe");
 document d2(d1);//copying using copy constructor
 document d3("corrupted");
 d3=d1;//using assignment operator
 cout<<"BEFORE MODIFICATION:"<<endl;
 d1.display();
 d2.display();
 d3.display();
   d1.settext("i have modified origial");
   cout<<"AFTER MODIFICATION:"<<endl;
   d1.display();
   d2.display();
   d3.display();
}