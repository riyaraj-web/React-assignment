#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

// A structure to hold the state of each junction
struct JunctionState {
    std::string last_used_from = ""; // The name of the child node last used
    int switch_count = 0; // How many times this junction has been switched
};

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, K;

    // Maps a child node (workstation or junction) to its parent junction
    std::map<std::string, std::string> parent_of;
    // Maps a junction name to its current state
    std::map<std::string, JunctionState> junction_states;
    // Stores the sequence of products to be processed
    std::vector<std::string> products;
    long long total_time = 0;

    // --- 1. Input Parsing ---

    std::cin >> N;
    std::string line;
    std::getline(std::cin, line); 

    // Read the N lines describing the conveyor structure
    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string junction_name, connected_node;
        
        ss >> junction_name;
        // Initialize the state for this junction
        junction_states[junction_name] = JunctionState(); 

        while (ss >> connected_node) {
            // All connected nodes lead to this junction
            parent_of[connected_node] = junction_name;
        }
    }

    // Read the line with the product sequence
    std::getline(std::cin, line);
    std::stringstream ss_products(line);
    std::string product_origin;
    while (ss_products >> product_origin) {
        products.push_back(product_origin);
    }
    
    // Read the switch limit K
    std::cin >> K;

    // --- 2. Simulation ---

    // Process each product one by one
    for (const std::string& start_node : products) {
        long long current_product_time = 0;

        std::vector<std::string> path;
        std::string current_node = start_node;
        while (parent_of.count(current_node)) {
            path.push_back(current_node);
            current_node = parent_of[current_node];
        }
        path.push_back(current_node); 

            for (size_t i = 0; i < path.size() - 1; ++i) {
            std::string child = path[i];
            std::string junction = path[i+1];
                     
            JunctionState& state = junction_states[junction];
            
            current_product_time += 1;

            bool switch_needed = (state.last_used_from != child);

            if (switch_needed) {
                bool is_locked = (state.switch_count >= K);

                if (is_locked) {
                    current_product_time += 3; 
                    
                } else {
                    current_product_time += 2; 
                    state.switch_count++;
                    state.last_used_from = child;
                }
            }
        }
        total_time += current_product_time;
    }

    std::cout << total_time << std::endl;

    return 0;
}