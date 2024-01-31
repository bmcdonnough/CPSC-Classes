/*
 * Name: Benjamin McDonnough
 * Date Submitted: 12/1/23
 * Lab Section: 006
 * Assignment Name: Using Breadth-First Search to Solve Puzzles
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int,int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
                          "Fill B",
                          "Empty A",
                          "Empty B",
                          "Pour A->B",
                          "Pour B->A"};

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

// GENERIC (breadth-first search, outward from source_node)
void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;
  
  while (!to_visit.empty()) {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
      if (!visited[n]) {
	pred[n] = curnode;
	dist[n] = 1 + dist[curnode];
	visited[n] = true;
	to_visit.push(n);
      }
  }
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << "[" << t.first << "," << t.second << "]\n";
  } else {
    cout << "Initial state: " << "[" << s.first << "," << s.second << "]\n";
  }
}

void build_graph(void)
{
  state curr = make_pair(0, 0);
  state end = make_pair(3,4);
  const int jugOneMax = 3;
  const int jugTwoMax = 4;

  //Implement this function
  while(curr != end){
    state next;

    //Fill A
    next = make_pair(jugOneMax, curr.second);

    if(next != curr){
      pair<state, state> move = make_pair(curr, next);
      nbrs[curr].push_back(next);
      edge_label[move] = actions[0];
    }

    //Fill B
    next = make_pair(curr.first, jugTwoMax);

    if(next != curr){
      pair<state, state> move = make_pair(curr, next);
      nbrs[curr].push_back(next);
      edge_label[move] = actions[1];
    }

    //Empty A
    next = make_pair(0, curr.second);

    if(next != curr){
      pair<state, state> move = make_pair(curr, next);
      nbrs[curr].push_back(next);
      edge_label[move] = actions[2];
    }

    //Empty B
    next = make_pair(curr.first, 0);

    if(next != curr){
      pair<state, state> move = make_pair(curr, next);
      nbrs[curr].push_back(next);
      edge_label[move] = actions[3];
    }

    //A into B
    int aLevel = curr.first;
    int bLevel = curr.second;

    if(curr.second < jugTwoMax){
      while(aLevel > 0 && bLevel < jugTwoMax){
        bLevel++;
        aLevel--;
      }
    }

    next = make_pair(aLevel, bLevel);

    if(next != curr){
      pair<state, state> move = make_pair(curr, next);
      nbrs[curr].push_back(next);
      edge_label[move] = actions[4];
    }

    //Fill A
    aLevel = curr.first;
    bLevel = curr.second;

    if(curr.first < jugOneMax){
      while(bLevel > 0 && aLevel < jugOneMax){
        aLevel++;
        bLevel--;
      }
    }

    next = make_pair(aLevel, bLevel);
    
    if(next != curr){
      pair<state, state> move = make_pair(curr, next);
      nbrs[curr].push_back(next);
      edge_label[move] = actions[5];
    }

    if(curr.second == jugTwoMax){
      curr = make_pair(curr.first + 1,0);
    }
    else{
      curr = make_pair(curr.first, curr.second + 1);
    }
           
  }
}

/*int main(void)
{
  build_graph();

  state start = make_pair(0,0);
  
  for (int i=0; i<5; i++)
    nbrs[make_pair(i,5-i)].push_back(make_pair(-1,-1));
  search (start);
  if (visited[make_pair(-1,-1)]) 
    print_path (start, pred[make_pair(-1,-1)]);
  else
    cout << "No path!\n";
  
  return 0;
}*/
