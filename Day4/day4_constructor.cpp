#include <iostream>
using namespace std;

class rectangle {
private:
    int *left,*top,*width,*height;
public:
    rectangle(int l,int t,int w,int h) {
        left = new int(l);
        top = new int(t);
        width = new int(w);
        height = new int(h);
    }
    
};