#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WINDOW_SIZE = 4; // Size of the sliding window
const int TOTAL_FRAMES = 10; // Total number of frames to send
const int TIMEOUT_DURATION = 3000; // Timeout duration in milliseconds

// Function to simulate sending frames
void sendFrames(queue<int>& frames, vector<bool>& ackReceived, int& nextFrameToSend) {
    int framesToSend = min(WINDOW_SIZE, TOTAL_FRAMES - nextFrameToSend);
    for (int i = 0; i < framesToSend; ++i) {
        if (nextFrameToSend < TOTAL_FRAMES) {
            cout << "Sending frame " << nextFrameToSend << endl;
            frames.push(nextFrameToSend);
            nextFrameToSend++;
        }

      /*  auto endTime = chrono::steady_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
    if (elapsedTime > TIMEOUT_DURATION) {
        cout << "Timeout occurred. Retransmitting frames..." << endl;*/
    }
}

// Function to simulate receiving acknowledgments
void receiveAcks(queue<int>& frames, vector<bool>& ackReceived) {
    while (!frames.empty()) {
        int frame = frames.front();
        frames.pop();

        // Simulate random acknowledgment loss
        if (rand() % 10 < 2) {
            cout << "Acknowledgment for frame " << frame << " lost!" << endl;
        } else {
            cout << "Acknowledgment for frame " << frame << " received" << endl;
            ackReceived[frame] = true;
        }
    }
}

// Function to simulate retransmission of lost frames
void retransmitFrames(queue<int>& frames, vector<bool>& ackReceived, int& base) {
    for (int i = base; i < base + WINDOW_SIZE && i < TOTAL_FRAMES; ++i) {
        if (!ackReceived[i]) {
            cout << "Retransmitting frame " << i << endl;
            frames.push(i);
        }
    }
}

int main() {
    srand(time(0));
    vector<bool> ackReceived(TOTAL_FRAMES, false);
    queue<int> frames;
    int base = 0;
    int nextFrameToSend = 0;

    while (base < TOTAL_FRAMES) {
        // Send frames within the window
        sendFrames(frames, ackReceived, nextFrameToSend);

        // Simulate delay and receive acknowledgments
        receiveAcks(frames, ackReceived);

        // Move the base to the next unacknowledged frame
        while (base < TOTAL_FRAMES && ackReceived[base]) {
            base++;
        }

        // Retransmit lost frames if any
        if (base < nextFrameToSend) {
            retransmitFrames(frames, ackReceived, base);
        }
    }

    cout << "All frames sent and acknowledged!" << endl;

    return 0;
}
