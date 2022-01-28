#include <iostream>
#include<cstring>
using namespace std;

class comp_num
{
private:
    int re, img;

public:
    comp_num(int re, int img)
    {
        this->re = re;
        this->img = img;
    }
    void print()
    {
        cout << re << " + " << img << "i";
    }
    void add(const comp_num &t)
    {
        re += t.re;
        img += t.img;
    }
    void multiply(const comp_num &t)
    {
        int rer = re * t.re - img * t.img;
        int imgr = re * t.img + img * t.re;
        re = rer;
        img = imgr;
    }
    void complement()
    {
        img *= -1;
    }
};

int main()
{
    comp_num c1(1, 2);
    comp_num c2(1, 1);
    c1.complement();
    c1.print();
    cout << endl;
    return 0;
}
