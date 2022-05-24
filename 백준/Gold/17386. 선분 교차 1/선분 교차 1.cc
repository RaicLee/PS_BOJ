#include <iostream>

using namespace std;

typedef struct P{
    long long x,y;
}POINT;

int ccw(POINT a, POINT b, POINT c)
{
    long long result = 1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y;
    result -= (1LL * a.y*b.x + 1LL * b.y * c.x + 1LL * c.y * a.x);
    if (result > 0)
        return 1;
    else if (result == 0)
        return 0;
    else
        return -1;
}

int main()
{
    POINT a,b,c,d;
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cin>>c.x>>c.y;
    cin>>d.x>>d.y;
    int r1 = ccw(a,b,c);
    int r2 = ccw(a,b,d);
    int r3 = ccw(c,d,a);
    int r4 = ccw(c,d,b);
    
    if (r1 * r2 <= 0 && r3 * r4 <= 0)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    
}