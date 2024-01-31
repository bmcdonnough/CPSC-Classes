#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> V; //words from wordlist05.txt
//Global variables for bfs distance, bfs pred, and neighboring nodes
//Should be unordered_map type
unordered_map<string, vector<string>> nbrs;
unordered_map<string, int> level;
unordered_map<string, string> pred;
unordered_map<string, bool> visited;

//Implement breadth-first search, refer to Lab 10

// Function to fill the dictionary vector with words from wordlist05.txt
void fillDictionary(string filename, vector<string> &words)
{
  ifstream infile(filename);
  string word;
  while (getline(infile, word))
  {
    words.push_back(word);
  }
}

// Fills a map with all the neighbor words
void findnbrs(vector<string> words, unordered_map<string, vector<string>> &nbrs)
{
  for (int i = 0; i < words.size(); i++)
  {
    for (int j = i + 1; j < words.size(); j++)
    {
      string first = words[i];
      string second = words[j];

      // Count number of different characters between words
      int count = 0;
      for (int k = 0; k < first.size(); k++)
      {
        if (first[k] != second[k])
        {
          count++;
        }
      }

      // If count is 1, the two words are nbrs
      if (count == 1)
      {
        nbrs[first].push_back(second);
        nbrs[second].push_back(first);
      }
    }
  }
}

// Updates steps with the length of the word ladder solution and p with
// the sequence of words in the solution
void wordLadder(string s, string t, int &steps, vector<string> &p)
{
  // If source and target are the same
  if (s == t)
  {
    steps = 0;
    p.push_back(s);
    return;
  }

  // Read in all words from given wordlist
  fillDictionary("wordlist05.txt", V);
  findnbrs(V, nbrs);

  // Set up queue to be used to find solutions
  queue<string> queue;
  queue.push(s);
  visited[s] = true;
  pred[s] = "";
  level[s] = 0;

  while (!queue.empty())
  {
    string current = queue.front();
    queue.pop();

    // If target is found, update steps and p and end the function
    if (current == t)
    {
      steps = level[t];
      while (current != "")
      {
        p.push_back(current);
        current = pred[current];
      }
      reverse(p.begin(), p.end());
      return;
    }

    // If the target is not found, try each neighbor until
    // a solution is found
    for (string neighbor : nbrs[current])
    {
      if (!visited[neighbor])
      {
        visited[neighbor] = true;
        pred[neighbor] = current;
        level[neighbor] = level[current] + 1;
        queue.push(neighbor);
      }
    }
  }
  steps = 0;
}

/*
int main(void)
{
  int steps = 0;
  string s, t;
  vector<string> path;
  
  cout << "Source: ";
  cin >> s;

  cout << "Target: ";
  cin >> t;

  wordLadder(s, t, steps, path);

  if (steps == 0)
  {
      cout << "No path!\n";
  }
  else
  {
      cout << "Steps: " << steps << "\n\n";
      for (int i=0; i<path.size(); i++)
      {
          cout << path[i] << endl;
      }
  }
  return 0;
}
*/