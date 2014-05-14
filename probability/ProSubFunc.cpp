/**
 * @file ProSubFunc.cpp
 *
 */

#include "../include/probability/ProDefine.h"
#include "../include/probability/ProType.h"
#include "../include/probability/ProItem.h"
#include "../include/probability/ProSubFunc.h"

unsigned int GetSlotLeftStopItem(MTRANDOM* mtRandom, MainFrame* mainFrame) {
	int random = 0;
	random = mtRandom->getRandomLong(RANDOM_BASE);

	SlotProStep* leftSlotStep = &(mainFrame->m_slot1Step);

	unsigned int ret = slot_item_unknown;

	if (random < leftSlotStep->step1)
		ret = slot_item_cherry;
	else if (random >= leftSlotStep->step1 && random < leftSlotStep->step2)
		ret = slot_item_orange;
	else if (random >= leftSlotStep->step2 && random < leftSlotStep->step3)
		ret = slot_item_apple;
	else if (random >= leftSlotStep->step3 && random < leftSlotStep->step4)
		ret = slot_item_coin;
	else if (random >= leftSlotStep->step4 && random < leftSlotStep->step5)
		ret = slot_item_bar;
	else if (random >= leftSlotStep->step5 && random < leftSlotStep->step6)
		ret = slot_item_diamond;
	else if (random >= leftSlotStep->step6 && random < leftSlotStep->step7)
		ret = slot_item_crown;
	else if (random >= leftSlotStep->step7 && random < leftSlotStep->step8)
		ret = slot_item_freecoin;
	else if (random >= leftSlotStep->step8 && random < leftSlotStep->step9)
		ret = slot_item_roulette;

	assert(ret > 0);

	LOGD(__func__, "Stop Item = %d \n", ret);

	return ret;
}

unsigned int GetSlotMiddleStopItem(MTRANDOM* mtRandom, MainFrame* mainFrame) {
	int random = 0;
	random = mtRandom->getRandomLong(RANDOM_BASE);

	SlotProStep* middleSlotStep = &(mainFrame->m_slot2Step);

	unsigned int ret = slot_item_unknown;

	if (random < middleSlotStep->step1)
		ret = slot_item_cherry;
	else if (random >= middleSlotStep->step1 && random < middleSlotStep->step2)
		ret = slot_item_orange;
	else if (random >= middleSlotStep->step2 && random < middleSlotStep->step3)
		ret = slot_item_apple;
	else if (random >= middleSlotStep->step3 && random < middleSlotStep->step4)
		ret = slot_item_coin;
	else if (random >= middleSlotStep->step4 && random < middleSlotStep->step5)
		ret = slot_item_bar;
	else if (random >= middleSlotStep->step5 && random < middleSlotStep->step6)
		ret = slot_item_diamond;
	else if (random >= middleSlotStep->step6 && random < middleSlotStep->step7)
		ret = slot_item_crown;
	else if (random >= middleSlotStep->step7 && random < middleSlotStep->step8)
		ret = slot_item_freecoin;
	else if (random >= middleSlotStep->step8 && random < middleSlotStep->step9)
		ret = slot_item_roulette;

	assert(ret > 0);

	LOGD(__func__, "Stop Item = %d \n", ret);

	return ret;
}

unsigned int GetSlotRightStopItem(MTRANDOM* mtRandom, MainFrame* mainFrame) {
	int random = 0;
	random = mtRandom->getRandomLong(RANDOM_BASE);

	SlotProStep* rightSlotStep = &(mainFrame->m_slot3Step);

	unsigned int ret = slot_item_unknown;

	if (random < rightSlotStep->step1)
		ret = slot_item_cherry;
	else if (random >= rightSlotStep->step1 && random < rightSlotStep->step2)
		ret = slot_item_orange;
	else if (random >= rightSlotStep->step2 && random < rightSlotStep->step3)
		ret = slot_item_apple;
	else if (random >= rightSlotStep->step3 && random < rightSlotStep->step4)
		ret = slot_item_coin;
	else if (random >= rightSlotStep->step4 && random < rightSlotStep->step5)
		ret = slot_item_bar;
	else if (random >= rightSlotStep->step5 && random < rightSlotStep->step6)
		ret = slot_item_diamond;
	else if (random >= rightSlotStep->step6 && random < rightSlotStep->step7)
		ret = slot_item_crown;
	else if (random >= rightSlotStep->step7 && random < rightSlotStep->step8)
		ret = slot_item_freecoin;
	else if (random >= rightSlotStep->step8 && random < rightSlotStep->step9)
		ret = slot_item_roulette;

	assert(ret > 0);

	LOGD(__func__, "Stop Item = %d \n", ret);

	return ret;
}

unsigned int GetMatchStopItem(MTRANDOM* mtRandom, MainFrame* mainFrame) {
	int random = 0;
	random = mtRandom->getRandomLong(RANDOM_BASE);

	MatchProStep* matchStep = &(mainFrame->m_matchStep);

	unsigned int ret = slot_item_unknown;

	if (random < matchStep->step1)
		ret = match_item_cherry;
	else if (random >= matchStep->step1 && random < matchStep->step2)
		ret = match_item_orange;
	else if (random >= matchStep->step2 && random < matchStep->step3)
		ret = match_item_apple;
	else if (random >= matchStep->step3 && random < matchStep->step4)
		ret = match_item_coin;
	else if (random >= matchStep->step4 && random < matchStep->step5)
		ret = match_item_bar;
	else if (random >= matchStep->step5 && random < matchStep->step6)
		ret = match_item_diamond;
	else if (random >= matchStep->step6 && random < matchStep->step7)
		ret = match_item_crown;
	else if (random >= matchStep->step7 && random < matchStep->step8)
		ret = match_item_multiple;
	else if (random >= matchStep->step8 && random < matchStep->step9)
		ret = match_item_train;

	assert(ret > 0);

	LOGD(__func__, "Stop Item = %d \n", ret);

	return ret;
}
