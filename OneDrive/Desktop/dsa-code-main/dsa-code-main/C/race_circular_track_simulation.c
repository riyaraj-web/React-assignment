#include <stdio.h>
#include <stdlib.h>

// --- Data Structure Definition ---

/**
 * @brief Represents a single segment or point on the circular race track.
 * * This structure forms the node of the circular linked list.
 */
struct Node {
    int id;             // Unique identifier for the track segment (0 is the start/finish line).
    struct Node *next;  // Pointer to the next segment on the track, making it a circular list.
};

// --- Function Prototypes ---
struct Node *create_track(int n, struct Node *head);
int simulate_Race(int k, struct Node *head);

// --- Core Function: Create Circular Track ---

/**
 * @brief Creates a circular race track (circular linked list).
 * * The track has 'n' segments, with a total of (n+1) nodes (0 to n).
 * The head node (id=0) links back to the last node (id=n), forming a circle.
 * * @param n The number of track segments (nodes - 1).
 * @param head Pointer to the head of the list (initially NULL).
 * @return struct Node* The pointer to the head of the circular list (node with id=0).
 */
struct Node *create_track(int n, struct Node *head) {
    struct Node *temp = NULL;
    struct Node *prev = NULL;

    // Create n+1 nodes (from i=0 to i=n)
    for (int i = 0; i <= n; i++) {
        // Allocate memory for the new node (track segment)
        temp = (struct Node *)malloc(sizeof(struct Node));
        
        // Check if memory allocation failed
        if (temp == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            // In a real application, you would need to free previously allocated memory here.
            return NULL;
        }

        temp->id = i;
        temp->next = NULL;

        if (head == NULL) {
            // First node is the head (Start/Finish Line: id=0)
            head = temp;
        } else {
            // Link the previous node to the new node
            prev->next = temp;
        }
        
        // Move the 'previous' pointer forward
        prev = temp;
    }

    // Connect the last node (id=n) back to the head (id=0) to make the track circular
    if (temp != NULL) {
        temp->next = head;
    }
    
    return head;
}

// --- Core Function: Race Simulation (Lapping Challenge) ---

/**
 * @brief Simulates a race using the Tortoise and Hare (Floyd's) technique.
 * * Dominic (Tortoise) moves 1 segment per turn.
 * Stephano (Hare) moves 2 segments per turn.
 * * The race ends if:
 * 1. Stephano (faster) laps Dominic (slower) - Indicated by Dom == Steph. (Stephano wins this phase)
 * 2. Dominic completes 'k' required laps without being lapped. (Dominic wins)
 * * @param k The number of laps Dominic is required to finish.
 * @param head The starting point (node with id=0).
 * @return int Returns 0 upon completion.
 */
int simulate_Race(int k, struct Node *head) {
    // Both racers start at the same position (head/id=0)
    struct Node *Dom = head;
    struct Node *Steph = head;
    int laps = 0; // Counts the laps completed by Dominic (the slower racer)

    printf("\n--- Race Simulation Start ---\n");
    printf("Dominic speed: 1 segment/turn (Tortoise)\n");
    printf("Stephano speed: 2 segments/turn (Hare)\n");
    printf("Dominic's required laps: %d\n", k);
    printf("Track segments start at id=0 (Start/Finish).\n\n");

    // Race loop: continues as long as Dominic's required laps are not met
    while (k > laps) {
        // Safety check to ensure pointers are valid before moving
        if (Dom == NULL || Steph == NULL || Steph->next == NULL) {
             printf("Error: Invalid track structure (non-circular or too short).\n");
             return 0;
        }

        // 1. Advance the Racers
        Dom = Dom->next;             // Dominic moves 1 step
        Steph = Steph->next->next;   // Stephano moves 2 steps

        // 2. Check for Lapping (Meeting Point)
        // If the faster racer (Stephano) meets the slower racer (Dominic),
        // it means Stephano has successfully lapped Dominic.
        if (Dom == Steph) {
            printf("Racer collision detected at segment id: %d!\n", Dom->id);
            printf("Result: Stephano won the lapping challenge by catching Dominic!\n");
            return 0;
        }

        // 3. Count Dominic's Laps
        // We count a lap when Dominic (the slower one) crosses the start line (id=0)
        // Note: The original code counted Stephano's lap, but since the end condition uses 'k' for Dom,
        // it is more intuitive to track Dom's laps for the final goal check.
        if (Dom->id == 0) {
            laps++;
            printf("Dominic finished lap %d of %d.\n", laps, k);
        }
    }

    // --- Race End Condition ---
    
    // If the loop finished because k <= laps, Dominic completed his required laps.
    printf("\n--- Race Finished ---\n");
    printf("Result: Dominic finished his required %d laps without being lapped.\n", k);
    printf("Dominic wins the distance challenge!\n");
    
    return 0;
}

// --- Main Program ---

int main() {
    int nodes;
    int dom_laps;

    printf("Enter the number of track segments (e.g., 5 for a track with nodes 0 to 5): ");
    // The number entered here is the 'n' in the create_track function.
    if (scanf("%d", &nodes) != 1 || nodes < 1) {
        printf("Invalid input for track segments.\n");
        return 1;
    }

    printf("Enter the number of laps Dominic has to finish: ");
    if (scanf("%d", &dom_laps) != 1 || dom_laps < 1) {
        printf("Invalid input for laps.\n");
        return 1;
    }

    struct Node *head = NULL;
    
    // Create and link the track
    head = create_track(nodes, head);
    
    // Check for creation error
    if (head == NULL) {
        printf("Failed to create the track. Exiting.\n");
        return 1;
    }

    // Run the simulation
    simulate_Race(dom_laps, head);
    
    // --- Memory Cleanup ---
    
    // Free the dynamically allocated nodes to prevent memory leaks.
    struct Node *current = head;
    struct Node *temp_next = NULL;

    if (current != NULL) {
        // Break the cycle at the head to allow proper traversal for freeing
        struct Node *last_node = current;
        while (last_node->next != head) {
            last_node = last_node->next;
        }
        last_node->next = NULL; 

        // Now traverse and free each node
        while (current != NULL) {
            temp_next = current->next;
            free(current);
            current = temp_next;
        }
    }

    return 0;
}