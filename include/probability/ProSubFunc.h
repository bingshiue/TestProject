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

unsigned int GetMatchAward(GAMEFRAME* gameFrame);

unsigned int GetSlotStraightAward(GAMEFRAME* gameFrame);

unsigned int GetMatchWin(unsigned int matchAward,unsigned int bet);

unsigned int GetSlotStraightWin(unsigned int slotStraightAward,unsigned int bet);

unsigned int PlayMatchMultiple(GAMEFRAME* gameFrame);

unsigned int PlayMatchTrain(GAMEFRAME* gameFrame);

bool KeyOutCheck(MainFrame* mainFrame);

#endif /* PROSUBFUNC_H_ */
