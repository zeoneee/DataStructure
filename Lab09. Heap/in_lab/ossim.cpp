//--------------------------------------------------------------------
//
//  Laboratory B, In-lab Exercise 1                       ossim.cs
//
//  (Shell) Operating system task scheduling simulation
//
//--------------------------------------------------------------------

// Simulates an operating system's use of a priority queue to regulate
// access to a system resource (printer, disk, etc.).

// 2019112587 김지현

#include <iostream>
#include <cstdlib>
#include "ptyqueue.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declaration for the task data struct
//

struct TaskData
{
    int priority,              // Task's priority
        arrived;               // Time when task was enqueued

    int pty() const
    {
        return priority;
    }   // Returns the priority
};

//--------------------------------------------------------------------

int getRandom(int n) {
    // 0부터 n-1까지의 랜덤한 수를 리턴하는 함수
    return rand() % n;
}

void main()
{
    PtyQueue<TaskData> taskPQ;   // Priority queue of tasks
    TaskData task;               // Task
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        numPtyLevels,            // Number of priority levels
        numArrivals;             // Number of new tasks arriving

    cout << endl << "Enter the number of priority levels : ";
    cin >> numPtyLevels;

    cout << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    int maxlow = 0;
    int maxhigh = 0;

    for (minute = 0; minute < simLength; minute++)
    {
        // Dequeue the first task in the queue (if any).

        cout << endl << endl << "Current minute = " << minute << endl;
        if (!(taskPQ.isEmpty())) {
            task = taskPQ.dequeue();
            cout << "Test Dequeued" << endl;
            cout << "This task's priority: " << task.pty() << endl;
            cout << "This task was arrived at " << task.arrived <<
                ", and waited for " << minute - task.arrived << " minutes" << endl;

            if (task.pty() == 0) {
                if (minute - task.arrived > maxlow)
                    maxlow = minute - task.arrived;
            }
            else if (task.pty() == 1) {
                if (minute - task.arrived > maxhigh)
                    maxhigh = minute - task.arrived;
            }
        }


        // Determine the number of new tasks and add them to
        // the queue.

        int k = getRandom(4);
        if (k == 1) {
            task.priority = getRandom(numPtyLevels);
            task.arrived = minute;
            taskPQ.enqueue(task);
            cout << "Adding 1 task" << endl;
        }
        else if (k == 2) {
            task.priority = getRandom(numPtyLevels);
            task.arrived = minute;
            taskPQ.enqueue(task);
            task.priority = getRandom(numPtyLevels);
            task.arrived = minute;
            taskPQ.enqueue(task);
            cout << "Adding 2 tasks" << endl;
        }
        else {
            cout << "No task was added this time" << endl;
        }

        cout << endl << endl;
        taskPQ.showStructure();

    }
    cout << "Longest wait for any low-priority(0) task : " << maxlow << endl;
    cout << "Longest wait for any hight-priority(1) task : " << maxhigh << endl;

}
