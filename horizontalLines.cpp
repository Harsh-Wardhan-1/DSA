#include <iostream>
#include <map>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
int main()
{
    int t;
    scanf("%d", &t);
    vector<pi> v;
    for (int i = 0; i < 2 * t; i++)
    {
        pi p;
        scanf("%d\n%d", &p.first, &p.second);
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    map<deque<pi>, int> m;
    for (auto x : v)
    {
        int n = 0;
        int a = x.first, b = x.second;
        deque<pi> v1;
        v1.push_back(x);
        bool active = true;
        while (active)
        {
            bool s = true;
            if (n % 2 == 0)
            {
                for (auto x1 : v)
                {
                    if (x1.second == b && x1.first > a)
                    {
                        a = x1.first;
                        n++;
                        v1.push_back(x1);
                        s = false;
                    }
                }
            }
            else
            {
                for (auto x1 : v)
                {
                    if (x1.first == a && x1.second > b)
                    {
                        b = x1.second;
                        n++;
                        v1.push_back(x1);
                        s = false;
                    }
                }
            }
            if (s == true)
            {
                if (n % 2 == 0)
                {
                    v1.pop_back();
                }
                active = false;
            }
        }
        m[v1] = v1.size();
    }
    int m1 = -1000;
    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        m1 = max(m1, itr->second);
    }
    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        if (itr->second == m1)
        {
            for (auto x : itr->first)
            {
                printf("%d\t%d\n", x.first, x.second);
            }
        }
    }
}