#ifndef __STATS_H
#define __STATS_H
#include <iostream>
#include <iomanip>
#include "Debug.h"
using namespace std;

enum PIPESTAGE { IF1 = 0, IF2 = 1, ID = 2, EXE1 = 3, EXE2 = 4, MEM1 = 5, 
                 MEM2 = 6, WB = 7, PIPESTAGES = 8 };

class Stats {
  private:
    long long cycles;
    int flushes;
    int bubbles;

    int memops;
    int branches;
    int taken;

    int resultReg[PIPESTAGES];

  public:
    Stats();

    void clock();

    void flush(int count);

    void registerSrc(int r);
    void registerDest(int r);

    void countMemOp() { memops++; }
    void countBranch() { branches++; }
    void countTaken() { taken++; }
	
    void showPipe();

    // getters
    long long getCycles() { return cycles; }
    int getFlushes() { return flushes; }
    int getBubbles() { return bubbles; }
    int getMemOps() { return memops; }
    int getBranches() { return branches; }
    int getTaken() { return taken; }

  private:
    void bubble();
};

#endif
