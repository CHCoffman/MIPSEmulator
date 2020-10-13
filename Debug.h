#ifndef __DEBUG_H
#define __DEBUG_H

//#define DEBUG // comment back in for debugging output

#ifdef DEBUG
#define D(x) x
#else
#define D(x)
#endif

#endif
