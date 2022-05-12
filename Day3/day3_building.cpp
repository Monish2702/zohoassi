#include <iostream>
using namespace std;
int n, m, sum;

bool DoesExistAndUnvisited(int x, int y, int **people_in_buildings, bool **visited)
{
    if (x < 0 || x >= n || y < 0 || y >= m || people_in_buildings[x][y] == 0) // doesn't exist and not zero
        return false;
    if (visited[x][y] == true) // already visited
        return false;
    return true;
}

// To move left, up, right, down while performing DFS
int move_x[] = {-1, 0, 1, 0};
int move_y[] = {0, 1, 0, -1};

// Searcher
void dfs(int x, int y, int **people_in_buildings, bool **visited)
{
    if (!DoesExistAndUnvisited(x, y, people_in_buildings, visited))
    {
        return;
    }
    sum += people_in_buildings[x][y];
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        // if(DoesExistAndUnvisited(x+move_x[i],y+move_y[i],people_in_buildings,visited)){

        dfs(x + move_x[i], y + move_y[i], people_in_buildings, visited);
    }
}

// Main function
int main()
{
    cout << "Enter the x (m) coordinate length: ";
    cin >> m;
    cout << "Enter the y (n) coordinate length: ";
    cin >> n;
    int max = 0;
    // Allocating 2d people_in_buildingsay of size m*n
    int **people_in_buildings = new int *[m];
    bool **visited = new bool *[m];
    int **groups = new int *[m]; // max possible group size is size of people_in_buildings i.e m*n
    for (int i = 0; i < m; i++)
    {
        people_in_buildings[i] = new int[n];
        visited[i] = new bool[n];
        groups[i] = new int[n];
    }

    // getting input from user
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> people_in_buildings[i][j];
            visited[i][j] = false;
            groups[i][j] = 0;
        }
    }
    // calling dfs
    cout << "\nThe formed groups sum are: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum = 0;
            dfs(i, j, people_in_buildings, visited);
            if (sum > 0)
            {
                groups[i][j] = sum;
                cout << groups[i][j] << " ";
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            max = max > groups[i][j] ? max : groups[i][j];
        }
    }
    cout << "\nThe leader group is: " << max;

    // Deallocate
    for (int i = 0; i < m; i++)
    {
        delete[] people_in_buildings[i];
        delete[] visited[i];
        delete[] groups[i];
    }
    delete[] people_in_buildings;
    delete[] visited;
    delete[] groups;
    return 0;
}