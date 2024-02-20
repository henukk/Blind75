#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list<int>> graf;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    graf.resize(numCourses);

    for (int i = 0; i < prerequisites.size(); ++i)
    {
        graf[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    vector<bool> visited(numCourses, false);
    vector<bool> recStack(numCourses, false);

    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i] && isCyclic(i, visited, recStack))
        {
            return false;
        }
    }

    return true;
}

bool isCyclic(int v, vector<bool> &visited, vector<bool> &recStack)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for (i = graf[v].begin(); i != graf[v].end(); ++i)
        {
            if (!visited[*i] && isCyclic(*i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}