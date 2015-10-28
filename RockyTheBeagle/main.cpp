//
//  main.cpp
//  RockyTheBeagle
//
//  Created by Zareek Galvan on 10/28/15.
//  Copyright © 2015 Trisquel Labs. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;

int d[20];
bool in[20];
int matriz[20][20];

void initializeMatrix(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

int minDist(int n)
{
    int min = INT_MAX;
    int minX = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (!in[i] && d[i] <= min)
        {
            min = d[i];
            minX = i;
        }
    }
    
    return minX;
}

void dijkstra(int n)
{
    for (int i = 0; i < n; i++)
    {
        d[i] = INT_MAX;
        in[i] = false;
    }
    d[0] = 0;
    int max = 0;
    for (int c = 0; c < n - 1; c++)
    {
        int u = minDist(n);
        
        in[u] = true;
        
        for (int v = 0; v < n; v++)
        {
            if (!in[v] && matriz[u][v] && d[u] != INT_MAX && d[u] + matriz[u][v] < d[v])
            {
                d[v] = d[u] + matriz[u][v];
                if (d[v] == d[max])
                {
                    if (v <= max)
                    {
                        max = v;
                    }
                }
            }
        }
    }
}

int cuarto(int n)
{
    int cuarto = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i] > d[cuarto])
        {
            cuarto = i;
        }
    }
    
    return cuarto;
}

int main()
{
    int cases, nodes, arcs, value;
    cin >> cases;
    
    for (int i = 0; i < cases; i++)
    {
        char x, y;
        cin >> nodes >> arcs;
        
        initializeMatrix(nodes);
        
        for (int i = 0; i < arcs; i++)
        {
            cin >> x >> y >> value;
            matriz[x-'A'][y-'A'] = matriz[y-'A'][x-'A'] = value;
        }
        
        dijkstra(nodes);
        
        cout << "Case " << i + 1 << ": " << (char)('A' + cuarto(nodes)) << endl;
    }
}