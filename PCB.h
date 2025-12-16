#ifndef PCB_H
#define PCB_H

#include <string>

enum ProcessStatus {
    RUNNING,
    WAITING,
    STOPPED
};

struct PCB {
    int processID;
    std::string processName;
    ProcessStatus processStatus;
    int commandCounter;
    int cpuRegisters[8];

    PCB(int id, std::string name, ProcessStatus status, int counter);
};

#endif