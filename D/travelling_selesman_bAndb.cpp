#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[10][10], visited[10], n, cost = 0;

// Function to find the path
int least(int c)
{
    int i, nc = 999;
    int min = 999, kmin;
    for (i = 0; i < n; i++)
    {
        // check if the city is visited or not
        if ((a[c][i] != 0) && (visited[i] == 0))

            // if not visited then check for minimum cost
            if (a[c][i] < min)
            {
                min = a[i][0] + a[c][i];
                kmin = a[c][i];
                nc = i;
            }
    }

    if (min != 999)
        cost += kmin;
    return nc;
}

// function to find the minimum cost
void mincost(int city)
{
    int i, ncity;
    visited[city] = 1;
    cout << city + 1 << "--->";
    ncity = least(city);
    if (ncity == 999)
    {
        ncity = 0;
        cout << ncity + 1;
        cost += a[city][ncity];
        return;
    }
    mincost(ncity);
}

int main()
{

    int i, j;
    cout << "Enter the number of cities: ";
    cin >> n;
    cout << "Enter the cost matrix: ";
    for (i = 0; i < n; i++)
    {
        cout << "Enter the elements of row: " << i + 1 << endl;
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    // uncomment the following line to print the cost matrix if you want
    // cout << "The cost matrix is: " << endl;
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "Enter starting city: ";
    int start;
    cin >> start;

    cout << "The path is: " << endl;
    mincost(start - 1);
    cout << endl;
    cout << "Minimum cost is: " << cost;
    return 0;
}