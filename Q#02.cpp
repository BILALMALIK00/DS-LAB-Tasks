//k230026
#include<iostream>
using namespace std;
class exam{
    private:
    string *name;
    string *date;
    int *score;
    public:
    exam(string n,string d,int sc){
        name =new string(n);
        date=new string(d);
        score=new int(sc);
    };
    void setname(string n){
        *name=n;
    }
    void setdate(string d){
        *date=d;
    }
    void setscore(int sc){
        *score=sc;
    }
    int getscore(){
        return *score;
    }
    string getname(){
        return *name;
    }
    string getdate(){
        return *date;
    }
    void print(){
        cout<<"Name:"<<*name<<endl;
        cout<<"Date:"<<*date<<endl;
        cout<<"Score:"<<*score<<endl;
        cout<<endl;
    }
    ~exam(){
        delete name;
        delete date;
        delete score;
    }
 
};
int main(){
    exam e1("bilal","23 March 2024",98);
    e1.print();
    exam e2(e1);//shallow copy
    e2.print();
    exam a3("malik","23 april 2024",90);
    a3=e1;
    //modification of orignal;
    e1.setname("hilal");
    e1.setdate("23 aug 2024");
    e1.setscore(89);
    cout<<"After Modification:"<<endl;
    e1.print();
    e1.print();
    a3.print();
    //result issue is that we dont have user defined copy constructor and assignment operator so here we are doing shallow copy which means if we change data of original object then their copie's data  will also changed.
    //as all three objects share same memory so destructor will try to delete same memory multiple times so to fix this we have to provide user defined copy constructor and assignment operator
}