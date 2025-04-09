#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

class DiskScheduler {
private:
    vector<int> requests;
    int headPosition;
    int diskSize;

    void validateInputs() {
        if (requests.empty()) {
            throw runtime_error("Request queue cannot be empty");
        }
        for (int request : requests) {
            if (request < 0 || request >= diskSize) {
                throw runtime_error("Invalid disk position: " + to_string(request));
            }
        }
        if (headPosition < 0 || headPosition >= diskSize) {
            throw runtime_error("Invalid head position");
        }
    }

    void visualizeMovement(int from, int to) {
        cout << setw(4) << from << " -> " << setw(4) << to 
             << " | Distance: " << setw(4) << abs(to - from) << endl;
    }

public:
    DiskScheduler(int diskSize = 200) : diskSize(diskSize) {}

    void setRequests(const vector<int>& req) {
        requests = req;
    }

    void setHeadPosition(int pos) {
        headPosition = pos;
    }

    void executeFCFS() {
        try {
            validateInputs();
            
            cout << "\nFCFS Disk Scheduling Simulation\n";
            cout << "================================\n";
            cout << "Initial head position: " << headPosition << "\n\n";
            
            int currentPosition = headPosition;
            int totalSeekTime = 0;
            double averageSeekTime = 0;
            
            cout << "Movement Pattern:\n";
            for (int request : requests) {
                int seekDistance = abs(request - currentPosition);
                visualizeMovement(currentPosition, request);
                totalSeekTime += seekDistance;
                currentPosition = request;
            }
            
            averageSeekTime = static_cast<double>(totalSeekTime) / requests.size();
            
            cout << "\nResults:\n";
            cout << "Total seek time: " << totalSeekTime << " cylinders\n";
            cout << "Average seek time: " << fixed << setprecision(2) 
                 << averageSeekTime << " cylinders\n";
            
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
};

int main() {
    try {
        DiskScheduler scheduler;
        char choice;
        
        do {
            cout << "\nFCFS Disk Scheduling Program\n";
            cout << "1. Use default values\n";
            cout << "2. Enter custom values\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice) {
                case '1': {
                    vector<int> defaultRequests = {98, 183, 37, 122, 14, 124, 65, 67};
                    scheduler.setRequests(defaultRequests);
                    scheduler.setHeadPosition(53);
                    scheduler.executeFCFS();
                    break;
                }
                case '2': {
                    vector<int> customRequests;
                    int n, pos;
                    
                    cout << "Enter the number of requests: ";
                    cin >> n;
                    
                    cout << "Enter the requests:\n";
                    for (int i = 0; i < n; i++) {
                        cin >> pos;
                        customRequests.push_back(pos);
                    }
                    
                    cout << "Enter initial head position: ";
                    cin >> pos;
                    
                    scheduler.setRequests(customRequests);
                    scheduler.setHeadPosition(pos);
                    scheduler.executeFCFS();
                    break;
                }
                case '3':
                    cout << "Exiting program...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != '3');
        
        return 0;
    } catch (const exception& e) {
        cerr << "Fatal error: " << e.what() << endl;
        return 1;
    }
}