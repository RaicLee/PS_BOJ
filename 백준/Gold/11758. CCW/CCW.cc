#include <iostream>

using namespace std;

typedef struct P{
    int x,y;
}POINT;

int ccw(POINT a, POINT b, POINT c)
{
    POINT p1,p2;
    p1.y = b.y - a.y;
    p1.x = b.x - a.x;
    p2.y = c.y - a.y;
    p2.x = c.x - a.x;
    int result = (p1.y * p2.x) - (p1.x * p2.y);
    if (result < 0)
        return 1;
    else if (result == 0)
        return 0;
    else
        return -1;
}

int main()
{
    POINT a,b,c;
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cin>>c.x>>c.y;
    cout<<ccw(a,b,c)<<endl;

    return 0;
}