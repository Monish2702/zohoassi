#include <iostream>
#include <cmath>
using namespace std;

class rectangle {
public:// private:
    int *left,*top,*width,*height,*area;
// public:
    rectangle(){ //default constructor initializing all the values to zero
        left = new int(0);
        top = new int(0);
        width = new int(0);
        height = new int(0);
        area = new int(0);
    }
    rectangle(int w, int h){  //parameterize constructor initializing the top,left to zero
        left = new int(0);
        top = new int(0);
        width = new int(w);
        height = new int(h);
        area = new int(0);
    }
    rectangle(int l,int t,int w,int h) { //parameterize constructor initializing all the values
        left = new int(l);
        top = new int(t);
        width = new int(w);
        height = new int(h);
        area = new int(0);
    }

    rectangle(float l, float t, float w, float h){ //parameterize constructor initializing all the values & round off
        left = new int(round(l));
        top = new int(round(t));
        width = new int(round(w));
        height = new int(round(h));
        area = new int(0);
    }

    rectangle(rectangle &r){ //copy constructor
        left = new int(* r.left);
        top = new int(* r.top);
        width = new int(* r.width);
        height = new int(* r.height);
        area = new int(*width * *height);
    }
    // void Area(){
    //     *area = *width * *height;
    //     area = new int(*width * *height);
        
    // }
    void print(){
    cout<<" 1) Left:: address   : "<<left<<"  value: "<<*left;
    cout<<"\n 2) Top:: address    : "<<top<<"  value: "<<*top;
    cout<<"\n 3) Width:: address  : "<<width<<"  value: "<<*width;
    cout<<"\n 4) Height:: address : "<<height<<"  value: "<<*height<<endl;
    if(area!=0) {cout<<" Area : "<<*area<<endl;}
    }
    ~rectangle() {
        delete left,top,width,height,area;
        cout<<"\nDestructor called"<<endl;;
    }
};

int main() {
    rectangle r1;
    cout<<"\n ----------------------- \n Default constructor\n ------------------------ \n"<<endl;
    // r1.Area();
    r1.print();
    rectangle r2(10,20);
    cout<<"\n ------------------------ \n Two parameter constructor:\n ------------------------ \n"<<endl;
    // r2.Area();
    r2.print();
    rectangle r3(10.5f,20.1f,30.9f,40.4f);
    cout<<"\n ------------------------ \n All parameter constructor\n ----------------------- \n"<<endl;
    r3.print();
    rectangle r4(r2);
    cout<<"\n ------------------------ \n Copy constructor-1\n ------------------------ \n"<<endl;
    r4.print();
    rectangle r5(r3);
    cout<<"\n ------------------------ \n Copy constructor-2\n ------------------------ \n"<<endl;
    r5.print();
    return 0;

}