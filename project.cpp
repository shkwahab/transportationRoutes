#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <climits>
#include <unistd.h> //for linux
// #include<windows.h> //windows
using namespace std;

string u_name, u_password, confirm_password;

bool login()
{
    string name, password;
    int counter = 0;
    cout << " Enter the username:";
    cin >> name;
    cout << "Enter the password:";
    cin >> password;
    if (u_name == name && u_password == password)
    {
        return true;
    }
    else
    {
        cout << "Wrong Creditionals";
        cout << endl;
        return false;
    }
    return false;
}

void takeSignUp()
{
    cout << "Enter your username:";
    cin >> u_name;
    cout << "Enter your password:";
    cin >> u_password;
    cout << "Enter confirm password:";
    cin >> confirm_password;
}
void signup()
{
    takeSignUp();
    int counter = 0;
    if (u_password != confirm_password)
    {
        cout << "Password and Confirm Password doesn't match!\n";
        cout << "Retry" << endl;
        while (true)
        {
            if (counter == 3)
            {
                break;
            }
            if (counter == 1)
            {
                cout << "You have left one chance to type write password otherwise you will have to wait run the program again\n";
            }
            takeSignUp();
            counter++;
        }
    }
    else
    {
        cout << "Registered Successfully" << endl;
    }
}

const int NUM_CITIES = 10;

vector<pair<int, int>> graph[NUM_CITIES];
// vector<pair<int, int>> *graph = new vector<pair<int, int>>[NUM_CITIES];

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

    void writeInputFile(string fileName, vector<pair<int, int>> graph[NUM_CITIES])
    {
        // Open the file
        ofstream file(fileName);

        // Check if the file is open
        if (!file.is_open())
        {
            cerr << "Error: Could not open file " << fileName << endl;
            return;
        }

        // Write the graph data to the file
        for (int i = 0; i < NUM_CITIES; i++)
        {
            for (auto j : graph[i])
            {
                file << i << "," << j.first << "," << j.second << endl;
            }
        }
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

    // Start to Goal Node Networks

    void writeNetwork(string fileName)
    {
        // Open the file
        ofstream file(fileName);

        // Check if the file is open
        if (!file.is_open())
        {
            cerr << "Error: Could not open file " << fileName << endl;
            return;
        }

        // Write the edges to the file
        for (int i = 0; i < NUM_CITIES; i++)
        {
            for (auto j : graph[i])
            {
                int neighbor = j.first;
                int weight = j.second;
                file << i << "," << neighbor << "," << weight << endl;
            }
        }

        // Close the file
        file.close();
    }
};

int main()
{
    TransportationRoutingProblem project;
    vector<pair<int, int>> dummyGraph[NUM_CITIES];
    int dist[NUM_CITIES];
    int start, end;
    int shortestPath=-1;
    cout << "--------------------------------------------------------------------"
         << endl;
    cout << "\t\t\t"
         << "Transportation Routing Problem\n"
         << "---------------------------------------------------------------------"
         << "\n\n";

    unsigned int microsecond = 1000000; // for linux
    usleep(2 * microsecond);            // sleeps for 3 second //for unix or linux
    //  Sleep(milliseconds); windows
    system("clear"); // for linux
    // system("cls")

    while (true)
    {
        cout << "⚠ To Use This Application You mush have to sign in" << endl;
        cout << endl
             << "Press 1 to Sign In" << endl
             << "Press 2 to Sign Up" << endl
             << "Press 3 to Exit" << endl;
        int option;
        cout << "Enter your choice:";
        cin >> option;
        if (option == 3)
        {
            break;
        }
        switch (option)
        {
        case 1:
            if (login() == 1)
            {
                system("clear"); // for linux
                // system("cls");  //for windows

                while (true)
                {
                    cout << "\n\t\t\t"
                         << "Welcome to my Project Trasportation Routing Problem made by Zohaib Ashraf"
                         << "\n\n";
                    cout << endl;
                    cout << "Press 1 to enter the network of the 10 cities(Distance between the cities)\n";
                    cout << "Press 2 to display the Network File of the Cities\n";
                    cout << "Press 3 to enter the start and end(goal) of the network city\n";
                    cout << "Press 4 to show the minumum cost to reach the goal city\n";
                    cout << "Press 5 to generate the output network file\n";
                    cout << "Press 6 to display the output newtwok file\n";
                    cout << "Press 7 to exit the application\n";
                    cout << endl;
                    int ch;
                    cout << "Enter your choice:";
                    cin >> ch;
                    if (ch == 7)
                    {
                        break;
                    }
                    switch (ch)
                    {
                    case 1:
                        for (int i = 0; i < NUM_CITIES; i++)
                        {
                            cout << "Enter the distance between City" << i << " to City" << i + 1 << ":";
                            cin >> dist[i];
                            dummyGraph[i].push_back({i + 1, dist[i]});
                        }
                        project.writeInputFile("projectNetworks.txt", dummyGraph);
                        break;
                    case 2:
                        project.displayNetwork("projectNetworks.txt");
                        break;
                    case 3:
                        cout << "Enter the Starting Route or Start City:";
                        cin >> start;
                        start = start - 1;
                        cout << "Enter the Destination Route or Goal City:";
                        cin >> end;
                        end = end - 1;
                        break;
                    case 4:
                        if (start < -1 || start > 10 || end > 10 || end < 0)
                        {
                            cout << " Starting City and Goal City must be defined correctly" << endl;
                        }
                        else
                        {
                            project.readNetwork("projectNetworks.txt");
                            shortestPath = project.dijkstra(start, end);
                            if (shortestPath == INT_MAX)
                            {
                                cout << "No path exists between city " << start << " and city " << end << endl;
                            }
                            else
                            {
                                cout << "Minimum cost to reach city " << end+1 << " is: " << shortestPath << endl;
                            }
                        }
                        break;
                    case 5:
                        if (shortestPath == -1)
                        {
                            cout << "You must have to compute first shortest path for this functionality" << endl;
                        }
                        else
                        {
                            cout << "Output Routes File Generated Successfully with the name of Output_Project" << endl;
                            project.writeNetwork("OutputRouteProject.txt");
                        }
                        break;
                    case 6:
                        project.displayNetwork("OutputRouteProject.txt");
                        break;
                    case 7:
                        break;
                    default:
                        cout << "Invalid Option" << endl;
                        break;
                    }
                }
            }
            break;
        case 2:
            signup();
            break;
        case 3:
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
    return 0;
}