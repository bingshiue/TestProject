/**
 * @file ProSubFunc.h
 *
 */

#ifndef PROSUBFUNC_H_
#define PROSUBFUNC_H_

#include <assert.h>
#include "../log.h"
#include "../mersenne_twister/MTRandom.h"
#include "../components/mainFrame.h"

unsigned int GetSlotLeftStopItem(MTRANDOM* mtRandom,MainFrame* mainFrame);

unsigned int GetSlotMiddleStopItem(MTRANDOM* mtRandom,MainFrame* mainFrame);

unsigned int GetSlotRightStopItem(MTRANDOM* mtRandom,MainFrame* mainFrame);

unsigned int GetMatchStopItem(MTRANDOM* mtRandom,MainFrame* mainFrame);

typedef unsigned int (*SLOTSTOPSUBFUNC)(MTRANDOM* mtRandom,MainFrame* mainFrame);

unsigned int GetMatchAward(void);

unsigned int GetSlotStraightAward(void);

#endif /* PROSUBFUNC_H_ */
