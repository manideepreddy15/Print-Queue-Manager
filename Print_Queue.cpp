#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

const string FILENAME = "queue.txt";

queue<string> loadQueue() {
    queue<string> q;
    ifstream fin(FILENAME);
    string line;
    while (getline(fin, line)) {
        if (!line.empty()) {
            q.push(line);
        }
    }
    return q;
}

void saveQueue(queue<string> q) {
    ofstream fout(FILENAME, ios::trunc);
    while (!q.empty()) {
        fout << q.front() << endl;
        q.pop();
    }
}

void addJob(const string& jobName) {
    queue<string> q = loadQueue();
    q.push(jobName);
    saveQueue(q);
    cout << "Added job: " << jobName << endl;
}

void processJob() {
    queue<string> q = loadQueue();
    if (!q.empty()) {
        cout << "Processed job: " << q.front() << endl;
        q.pop();
        saveQueue(q);
    } else {
        cout << "No jobs to process." << endl;
    }
}

void showQueue() {
    queue<string> q = loadQueue();
    if (q.empty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Pending jobs:" << endl;
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: print_queue <add|process|show> [job_name]" << endl;
        return 1;
    }

    string command = argv[1];

    if (command == "add") {
        if (argc < 3) {
            cout << "Error: No job name provided." << endl;
            return 1;
        }
        string jobName = argv[2];
        addJob(jobName);
    } else if (command == "process") {
        processJob();
    } else if (command == "show") {
        showQueue();
    } else {
        cout << "Invalid command. Use add, process, or show." << endl;
    }

    return 0;
}
