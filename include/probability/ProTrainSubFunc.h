/**
 * @file ProTrainSubFunc.h
 *
 */

#ifndef PROTRAINSUBFUNC_H_
#define PROTRAINSUBFUNC_H_

#include <assert.h>
#include "../log.h"
#include "../mersenne_twister/MTRandom.h"
#include "../components/mainFrame.h"

#define TRAIN_FRAME_COUNT  4
#define TRAIN_HEAD_FRAME   0
#define TRAIN_TAIL_FRAME  28


unsigned int DrawMatchTrainHeadFrame(MainFrame* mainFrame);

unsigned int GetMatchTrainAward(GAMEFRAME* gameFrame,unsigned int item);

unsigned int GetMatchTrainWin(GAMEFRAME* gameFrame,unsigned int matchAward,unsigned int* bet);

unsigned int PlayMatchTrain(MainFrame* mainFrame);

#endif /* PROTRAINSUBFUNC_H_ */
