#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> maxHeap;  // Max-heap to store fuel available at stations
    int currentFuel = startFuel;
    int stops = 0;
    int prevLocation = 0;

    stations.push_back({target, 0});  // Add destination as a "station"

    for (auto& station : stations) {
        int location = station[0];
        int fuel = station[1];

        // Refuel as much as possible before reaching the next station
        currentFuel -= (location - prevLocation);

        while (currentFuel < 0 && !maxHeap.empty()) {
            currentFuel += maxHeap.top();  // Take fuel from the station with the most fuel
            maxHeap.pop();
            stops++;
        }

        if (currentFuel < 0) {
            return -1;  // It's impossible to reach the destination
        }

        maxHeap.push(fuel);  // Add current station's fuel to the max-heap
        prevLocation = location;
    }

    return stops;
}

int main() {
    vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    int target = 100;
    int startFuel = 50;
    cout << "Minimum refuel stops: " << minRefuelStops(target, startFuel, stations) << endl;
    return 0;
}
