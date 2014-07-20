/**
 * @file ProMultipleSubFunc.h
 *
 */

#ifndef PROMULTIPLESUBFUNC_H_
#define PROMULTIPLESUBFUNC_H_

#include <assert.h>
#include "../log.h"
#include "../mersenne_twister/MTRandom.h"
#include "../components/mainFrame.h"

#define MULTIPLE_TIMES  5/**< Multiple Times */

unsigned int DrawMatchMultipleItem(MainFrame* mainFrame);

unsigned int CheckItemCount(unsigned int item);

unsigned int GetMatchMultipleAward(GAMEFRAME* gameFrame,unsigned int item);

unsigned int GetMatchMultipleWin(unsigned int matchAward,unsigned int bet);

unsigned int PlayMatchMultiple(MainFrame* mainFrame);

#endif /* PROMULTIPLESUBFUNC_H_ */
