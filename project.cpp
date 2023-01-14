#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int NUM_CITIES = 24;
const int NUM_TRUCKS = 50;

vector<pair<int, int>> graph[NUM_CITIES];

class TransportationRoutingProblem
{
public:
    vector<string> split(const string &s, char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    void readNetwork(string fileName)
    {
        // Open the file
        ifstream file(fileName);

        // Check if the file is open
        if (!file.is_open())
        {
            cerr << "Error: Could not open file " << fileName << endl;
            return;
        }

        // Read the file line by line
        string line;
        while (getline(file, line))
        {
            // Split the line into parts using the split function
            vector<string> parts = split(line, ',');

            // Extract the city names and distance
            int city1 = stoi(parts[0]);
            int city2 = stoi(parts[1]);
            int distance = stoi(parts[2]);

            // Add the edge to the graph
            graph[city1].push_back({city2, distance});
            graph[city2].push_back({city1, distance});
        }
    }

    int dijkstra(int start, int end)
    {
        // Create a priority queue to store the nodes to be visited
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Create an array to store the cost of reaching each city
        int cost[NUM_CITIES];
        for (int i = 0; i < NUM_CITIES; i++)
        {
            cost[i] = INT_MAX;
        }

        // Set the starting city's cost to zero
        cost[start] = 0;

        // Push the starting city onto the priority queue
        pq.push({0, start});

        // Loop until the priority queue is empty
        while (!pq.empty())
        {
            // Get the city with the lowest cost
            int curr = pq.top().second;
            pq.pop();

            // Check if we've reached the end city
            if (curr == end)
            {
                return cost[end];
            }

            // Check all neighboring cities
            for (auto i : graph[curr])
            {
                int neighbor = i.first;
                int weight = i.second;
                if (cost[curr] + weight < cost[neighbor])
                {
                    cost[neighbor] = cost[curr] + weight;
                    pq.push({cost[neighbor], neighbor});
                }
            }
        }
        return -1;
    }

    void displayNetwork(string fileName)
    {
        // Open the file
        ifstream file(fileName);

        // Check if the file is open
        if (!file.is_open())
        {
            cerr << "Error: Could not open file " << fileName << endl;
            return;
        }

        // Read the file line by line
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }
    
};