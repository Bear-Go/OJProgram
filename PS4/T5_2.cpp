#include <bits/stdc++.h>

using namespace std;

/*
B.细木棒的问题
Input:
第一行输入一个数n, 代表木棒的个数.
接下来n行按木棒落下的顺序输入空格分割的四个数x1,y1,x2,y2, 代表木棒两个端点的坐标(x1,y1),(x2,y2).
Output:
输出一个数, 代表没有被遮住的木棒的个数.
*/

typedef struct line {
    long long x1, y1, x2, y2;
} line;

bool is_intersect(line l1, line l2) {
    if(
       ( max(l1.x1,l1.x2)>=min(l2.x1,l2.x2)&&min(l1.x1,l1.x2)<=max(l2.x1,l2.x2) )&&
       ( max(l1.y1,l1.y2)>=min(l2.y1,l2.y2)&&min(l1.y1,l1.y2)<=max(l2.y1,l2.y2) )
      )
        if(
            ( (l2.x1-l1.x1)*(l1.y2-l1.y1)-(l2.y1-l1.y1)*(l1.x2-l1.x1) ) *
            ( (l2.x2-l1.x1)*(l1.y2-l1.y1)-(l2.y2-l1.y1)*(l1.x2-l1.x1) ) <=0 &&
            ( (l1.x1-l2.x1)*(l2.y2-l2.y1)-(l1.y1-l2.y1)*(l2.x2-l2.x1) ) *
            ( (l1.x2-l2.x1)*(l2.y2-l2.y1)-(l1.y2-l2.y1)*(l2.x2-l2.x1) ) <=0
          )
            return true;
        else
            return false;
    else
        return false;
}

vector<line> cover;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        line l;
        cin >> l.x1 >> l.y1 >> l.x2 >> l.y2;
        for (int j = 0; j < cover.size(); ++j)
        {
            if (is_intersect(l, cover[j]))
            {
                cover.erase(cover.begin() + j);
                j--;
            }
        }
        cover.push_back(l);
    }
    cout << cover.size();
    return 0;
}