/*
Author: 謝承翰(b103040012)
Date: Sep. 29, 2021
Purpose: the way knight to walk through a board
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <cstdlib>

using namespace std;

typedef tuple<int, int, int> pt; // define a position

constexpr int I = 0, J = 1, DIR = 2; // the data ID in tuple

// stack
class stack
{
    pt arr[65]{}; // data array
    int p = 0; // pointer

public:
    pt top() // get the element on the top of stack
    {
        if (p == 0)
        {
            cout << "invaild\n";
            return pt{ 0,0,0 };
        }
        return arr[p - 1];
    }
    void pop() // get rid of the element on the top of stack
    {
        if (p == 0) return;
        --p;
    }
    void push(pt x) // create a element and put it on the top of stack
    {
        arr[p++] = x;
    }
    int size() // get the right now number of element the stack contains 
    {
        return p;
    }
};

// way direction
int dir[8][2] = { {-2,+1}, {-1,+2}, {+1,+2}, {+2,+1}, {+2,-1}, {+1,-2}, {-1,-2}, {-2,-1} };
int sq[15][15]; // board

// judge if the position is not out of limit
bool isvaild(pt p, int n) // position, the size of the board
{
    int i = get<I>(p); // i position
    int j = get<J>(p); // j position
    if ((i <= n and i >= 1) and (j <= n and j >= 1))
        if (sq[i][j] == 0) return true;
    return false;
}

int main()
{
    for (int n = 1; n <= 6; ++n)
    {
        stack stk; // stack
        stk.push(pt{ 1,1,0 }); // push the first point
        memset(sq, 0, sizeof(sq));

        int cnt = 0; // the number of cells we've walked
        bool ansExist = true; // judge if there's a solution

        while (stk.size() <= n * n)
        {
            if (stk.size() == 0)
            {
                ansExist = false;
                break;
            }

            // get the right now point 
            pt now = stk.top();
            pt nex = now;

            // write on the cell the number of step we've walked
            sq[get<I>(now)][get<J>(now)] = stk.size();

            if (stk.size() == n * n)
                break;

            // try next step
            for (; get<DIR>(now) < 8; ++get<DIR>(now))
            {
                int dire = get<DIR>(now);
                get<I>(nex) = get<I>(now) + dir[dire][0];
                get<J>(nex) = get<J>(now) + dir[dire][1];
                if (isvaild(nex, n))
                    break;
            }
            if (!isvaild(nex, n) or get<DIR>(now) == 8)
            {
                sq[get<I>(now)][get<J>(now)] = 0;
                stk.pop();
                continue;
            }
            
            // refresh the direction we've tried
            stk.pop();
            ++get<DIR>(now);
            stk.push(now);

            // put the nex step
            get<DIR>(nex) = 0;
            stk.push(nex);
        }

        // judge if there's a solution or not
        if (ansExist)
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                    cout << sq[i][j] << ' ';
                cout << endl;
            }
            cout << endl;
        }
        else
            cout << "no solution\n" << endl;

    }

    return 0;
}
