#include<stdio.h>
int findarr(int arr[]);
struct storage1
{
    int hue;
};

int main()
{
    int path[7] = {-1};
    int count = 0;
    int cost = 0;
    int graph[7][7] = {{0,4,3,0,0,0,0},
                     {0,0,0,0,5,12,0},
                     {0,0,0,7,0,10,0},
                     {0,0,0,0,0,2,0},
                     {0,0,0,0,0,0,16},
                     {0,0,0,0,0,0,5},
                     {0,0,0,0,0,0,0}};

    struct storage1 st[7];
    st[0].hue = 14;
    st[1].hue = 12;
    st[2].hue = 11;
    st[3].hue = 6;
    st[4].hue = 11;
    st[5].hue = 4;
    st[6].hue = 0;

    //start node is node0 and end node is node6
    for(int i=0; i<7; i++)
    {
        path[i] = -1;
    }
    path[0] = 0;

    for(int i=0; i<7;)
    {
        int arr[7] = {0};
        for(int j=0; j<7; j++)
        {
            // checking for existence of edge
            if(graph[i][j]!=0)
            {
                //f(n) = g(n) + h(n)
                arr[j] = graph[i][j] + st[j].hue;//storing the current possible paths
            }
            
        }
        i = findarr(arr);//selecting the best minimum path, returns index of least cost node
        count = count+1;
        path[count] = i;// stores the current path progress
        if(i==6)
         break;
    }
    // to process the path and calculate the cost
    for(int i=0; i<7; i++)
    { 
        if(path[i]==6)
        {
            printf("%d",path[i]);
            break;
        }
        printf("%d --> ",path[i]);
        cost = cost+ graph[path[i]][path[i+1]]; //selecting the edge cost from graph using the path array elements
    }
    // printing the cost
    printf("\ncost = %d",cost);
 
}

int findarr(int arr[])
{
    int least = 999;// smallest value in the array
    int ind; // return index of least value 
    for(int i=0; i<7; i++)
    {
        if(arr[i]!=0)
        {
            if(arr[i]<least)
            {
                least = arr[i];
                ind = i;
            }
        }
    }
    return ind;
}