#include "PCB.h"


PCB::PCB(int id, std::string name, ProcessStatus status, int counter) {
    processID = id;
    processName = name;
    processStatus = status;
    commandCounter = counter;
    for (int i = 0; i < 8; i++) {
        cpuRegisters[i] = 0;
    }
}