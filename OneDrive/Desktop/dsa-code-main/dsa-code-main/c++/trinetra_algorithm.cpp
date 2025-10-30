#include <iostream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <iomanip>

using namespace std;

class Trinetra {
private:
    int window_size;
    deque<int> window;
    unordered_map<int, int> freq_map;
    double prev_avg;
    int anomaly_count;

    // Parameters for detection
    double avg_threshold;
    int freq_threshold;
    int delta_threshold;

public:
    Trinetra(int w, double avg_t = 10.0, int freq_t = 3, int delta_t = 15)
        : window_size(w), prev_avg(0), anomaly_count(0),
          avg_threshold(avg_t), freq_threshold(freq_t), delta_threshold(delta_t) {}

    void process(int num) {
        // Update window
        window.push_back(num);
        freq_map[num]++;
        if (window.size() > window_size) {
            int removed = window.front();
            window.pop_front();
            freq_map[removed]--;
            if (freq_map[removed] == 0) freq_map.erase(removed);
        }

        // Calculate current average
        double curr_avg = compute_average();

        // Detect anomalies
        bool is_anomaly = false;
        string reason;

        if (abs(curr_avg - prev_avg) > avg_threshold) {
            is_anomaly = true;
            reason += "[Avg shift] ";
        }

        if (freq_map[num] > freq_threshold) {
            is_anomaly = true;
            reason += "[High freq] ";
        }

        if (!window.empty() && abs(num - window.back()) > delta_threshold) {
            is_anomaly = true;
            reason += "[Spike] ";
        }

        if (is_anomaly) {
            anomaly_count++;
            cout << "⚠️  Anomaly Detected at " << num << ": " << reason << "\n";
        }

        prev_avg = curr_avg;
    }

    double compute_average() {
        if (window.empty()) return 0.0;
        double sum = 0;
        for (int val : window) sum += val;
        return sum / window.size();
    }

    int get_anomaly_count() const {
        return anomaly_count;
    }
};

// === Driver ===
void run_sample() {
    vector<int> stream = {
        10, 12, 11, 13, 50, 11, 10, 12, 200, 10, 11, 9, 8, 7, 100, 8, 6, 9
    };

    Trinetra detector(5); // window size of 5

    cout << "🔍 Running Trinetra Stream Analysis...\n\n";

    for (int val : stream) {
        detector.process(val);
    }

    cout << "\n✅ Total anomalies detected: " << detector.get_anomaly_count() << "\n";
}

// === Entry Point ===
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    run_sample();
    return 0;
}
