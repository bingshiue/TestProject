/**
 * @file ProSubFunc.cpp
 *
 */

#include "../include/log.h"
#include "../include/probability/ProDefine.h"
#include "../include/probability/ProType.h"
#include "../include/probability/ProItem.h"
#include "../include/probability/ProAward.h"
#include "../include/probability/ProMultiple.h"
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

unsigned int GetMatchAward(GAMEFRAME* gameFrame) {
	unsigned int award = match_award_none;
	bool bingo = false;

	for(unsigned int idx=0; idx<sizeof(gameFrame->m_slot)/sizeof(gameFrame->m_slot[0]); idx++){
		if(gameFrame->m_match.item == gameFrame->m_slot[idx].item){
			bingo = true;
			break;
		}
	}

	if(gameFrame->m_match.item == match_item_multiple || gameFrame->m_match.item == match_item_train){
		bingo = true;
	}

	if(bingo==true){
		switch(gameFrame->m_match.item){

		case match_item_cherry:
			award = match_award_cherry;
			break;
		case match_item_orange:
			award = match_award_orange;
			break;
		case match_item_apple:
			award = match_award_apple;
			break;
		case match_item_coin:
			award = match_award_coin;
			break;
		case match_item_bar:
			award = match_award_bar;
			break;
		case match_item_diamond:
			award = match_award_diamond;
			break;
		case match_item_crown:
			award = match_award_crown;
			break;
		case match_item_multiple:
			award = match_award_multiple;
			break;
		case match_item_train:
			award = match_award_train;
			break;

		default:
			award = match_award_none;
			LOGE("Probability","%s: Match Award Error ! \n",__func__);
			break;
		}
	}

	LOGD("Probability","%s: Match Award=%d \n",__func__,award);
	return award;
}

unsigned int GetSlotStraightAward(GAMEFRAME* gameFrame){
	unsigned int award = straight_award_none;
	bool bingo = false;
	unsigned int cnt[10]={0};

	for(unsigned int idx=0; idx<sizeof(gameFrame->m_slot)/sizeof(gameFrame->m_slot[0]); idx++){
		cnt[gameFrame->m_slot[idx].item]++;
	}

	for(unsigned int idx=0; idx<sizeof(cnt)/sizeof(cnt[0]); idx++){
		if(cnt[idx] >= 3){
			bingo = true;
			break;
		}
	}

	if(bingo==true){
		switch(gameFrame->m_slot[0].item){

		case slot_item_cherry:
			award = straight_award_cherry;
			break;
		case slot_item_orange:
			award = straight_award_orange;
			break;
		case slot_item_apple:
			award = straight_award_apple;
			break;
		case slot_item_coin:
			award = straight_award_coin;
			break;
		case slot_item_bar:
			award = straight_award_bar;
			break;
		case slot_item_diamond:
			award = straight_award_diamond;
			break;
		case slot_item_crown:
			award = straight_award_crown;
			break;
		case slot_item_freecoin:
			award = straight_award_freecoin;
			break;
		case slot_item_roulette:
			award = straight_award_roulette;
			break;

		default:
			award = straight_award_none;
			LOGE("Probability","%s: Slot Straight Award Error ! \n",__func__);
			break;
		}
	}

	LOGD("Probability","%s: Slot Straight Award=%d \n",__func__,award);
	return award;
}

unsigned int GetMatchWin(unsigned int matchAward,unsigned int bet){
	unsigned int matchWin = 0;

	matchWin = MatchAwardMulTable[matchAward] * bet;
	LOGD("Probability","%s: Match Win = %d \n",__func__,matchWin);

	return matchWin;
}

unsigned int GetSlotStraightWin(unsigned int slotStraightAward,unsigned int bet){
	unsigned int slotStraightWin = 0;

	slotStraightWin = SlotAwardMulTable[slotStraightAward] * bet;
	LOGD("Probability","%s: Slot Straight Win = %d \n",__func__,slotStraightWin);

	return slotStraightWin;
}
