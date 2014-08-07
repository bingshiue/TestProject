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

#define MULTIPLE_MAX_TIMES  6/**< Multiple Maximum Times */
#define MULTIPLE_MIN_TIMES  2/**< Multiple Minimum Times */

unsigned int DrawMatchMultipleItem(MainFrame* mainFrame,unsigned int time, unsigned int totalTimes);

unsigned int CheckItemCount(unsigned int item);

unsigned int GetMatchMultipleAward(GAMEFRAME* gameFrame,unsigned int item);

unsigned int GetMatchMultipleWin(GAMEFRAME* gameFrame,unsigned int matchAward,unsigned int* bet);

unsigned int PlayMatchMultiple(MainFrame* mainFrame,unsigned int *drawTrain);

#endif /* PROMULTIPLESUBFUNC_H_ */
