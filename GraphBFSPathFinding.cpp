#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

vector<list<int>> adjacencyList;
vector<int> visitedFrom(10, -1);
queue<int> toVisit;
vector<bool> wasVisited(10, false);

void initializeGraph(vector<list<int>>& adjList)
{
  adjList.emplace_back(list<int>{8});
  adjList.emplace_back(list<int>{3, 7, 9, 2});
  adjList.emplace_back(list<int>{8, 1, 4});
  adjList.emplace_back(list<int>{4, 5, 1});
  adjList.emplace_back(list<int>{2, 3});
  adjList.emplace_back(list<int>{3, 6});
  adjList.emplace_back(list<int>{7 ,5});
  adjList.emplace_back(list<int>{1, 6});
  adjList.emplace_back(list<int>{2, 0, 9});
  adjList.emplace_back(list<int>{1, 8});

  for(int i = 0; i < adjList.size(); i++)
  {
    cout << i << " -> ";
    for(const auto& node: adjList[i])
    {
      cout << node << " ";
    }
    cout << endl;
  }
}

void bfs(int start, int stop)
{
  wasVisited[start] = true;
  toVisit.push(start);
  while(!toVisit.empty())
  {
    auto currentNode = toVisit.front();
    toVisit.pop();
    cout << "Visiting node: " << currentNode << endl;
    for(const auto& adjacent: adjacencyList[currentNode])
    {
      if(!wasVisited[adjacent])
      {
        cout << "Marking following adjacent node: " << adjacent << endl;
        wasVisited[adjacent] = true;
        visitedFrom[adjacent] = currentNode;
        toVisit.push(adjacent);
      }
    }
  }

  list<int> finalPath;
  auto current = stop;
  while(visitedFrom[current] != -1)
  {
    finalPath.emplace_back(current);
    current = visitedFrom[current];
  }
  finalPath.emplace_back(start);
  for(auto crit = crbegin(finalPath); crit != crend(finalPath); crit++)
  {
    cout << *crit << " -> ";
  }
}
int main()
{
  initializeGraph(adjacencyList);
  bfs(5, 9);
  return 0;
}
