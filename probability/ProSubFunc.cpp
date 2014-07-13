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

extern unsigned int DefaultKeyInOut[10][3];

unsigned int GetSlotLeftStopItem(MTRANDOM* mtRandom, MainFrame* mainFrame) {
	int random = 0;
	random = mtRandom->getRandomLong(RANDOM_BASE);

	SlotProStep* leftSlotStep = &(mainFrame->m_slot1Step);

	unsigned int ret = slot_item_unknown;

	if (random < leftSlotStep->step1)
		ret = slot_item_cherry;
	else if (random >= leftSlotStep->step1 && random < leftSlotStep->step2)
		ret = slot_item_apple;
	else if (random >= leftSlotStep->step2 && random < leftSlotStep->step3)
		ret = slot_item_orange;
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

	LOGD(__func__, "Random=%d,Stop Item=%d \n", random, ret);

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
		ret = slot_item_apple;
	else if (random >= middleSlotStep->step2 && random < middleSlotStep->step3)
		ret = slot_item_orange;
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

	LOGD(__func__, "Random=%d,Stop Item=%d \n", random, ret);

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
		ret = slot_item_apple;
	else if (random >= rightSlotStep->step2 && random < rightSlotStep->step3)
		ret = slot_item_orange;
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

	LOGD(__func__, "Random=%d,Stop Item=%d \n", random, ret);

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
		ret = match_item_apple;
	else if (random >= matchStep->step2 && random < matchStep->step3)
		ret = match_item_orange;
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

	LOGD(__func__, "Random=%d,Stop Item=%d \n", random, ret);

	return ret;
}

unsigned int GetMatchAward(GAMEFRAME* gameFrame) {
	unsigned int award = match_award_none;
	unsigned int slot_freecoin_cnt=0;
	bool bingo = false;

	switch(gameFrame->m_match.item){
	case match_item_cherry:
	case match_item_apple:
	case match_item_orange:
	case match_item_bar:
	case match_item_diamond:
	case match_item_crown:
		for(unsigned int idx=0; idx<sizeof(gameFrame->m_slot)/sizeof(gameFrame->m_slot[0]); idx++){
			if(gameFrame->m_match.item == gameFrame->m_slot[idx].item){
				bingo = true;
				break;
			}
		}
		break;

	case match_item_coin:
		for(unsigned int idx=0; idx<sizeof(gameFrame->m_slot)/sizeof(gameFrame->m_slot[0]); idx++){
			if(gameFrame->m_slot[idx].item==slot_item_coin || gameFrame->m_slot[idx].item==slot_item_freecoin){
				bingo = true;
				if(gameFrame->m_slot[idx].item==slot_item_freecoin){
					slot_freecoin_cnt++;
				}
			}
		}
		break;

	case match_item_multiple:
	case match_item_train:
		bingo = true;
		break;

	default:
		LOGE("Probability","%s: Error \n",__func__);
		break;

	}


	if(bingo==true){
		switch(gameFrame->m_match.item){

		case match_item_cherry:
			award = match_award_cherry;
			break;
		case match_item_apple:
			award = match_award_apple;
			break;
		case match_item_orange:
			award = match_award_orange;
			break;
		case match_item_coin:
			award = match_award_coin;
			//freecoin
			if(slot_freecoin_cnt > 0){
				LOGI("Probability","Win Free Time, Match Item = %d, Slot Item= %d,%d,%d \n",gameFrame->m_match.item,gameFrame->m_slot[0].item,gameFrame->m_slot[1].item,gameFrame->m_slot[2].item);
				gameFrame->m_gameCredit.m_freetimes += (slot_freecoin_cnt*5);
				LOGI("Probability","%s: Free Time += %d, Free Times = %d \n",__func__,slot_freecoin_cnt*5, gameFrame->m_gameCredit.m_freetimes);
			}

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

	// Coin & Free Coin
	if((cnt[slot_item_coin] + cnt[slot_item_freecoin]) == 3){
		LOGI("Probability","Coin & Free Coin Mix Straight, Slot Item= %d,%d,%d \n",gameFrame->m_slot[0].item,gameFrame->m_slot[1].item,gameFrame->m_slot[2].item);
		bingo = true;
	}

	if(bingo==true){
		switch(gameFrame->m_slot[0].item){

		case slot_item_cherry:
			award = straight_award_cherry;
			break;
		case slot_item_apple:
			award = straight_award_apple;
			break;
		case slot_item_orange:
			award = straight_award_orange;
			break;
		case slot_item_coin:
		case slot_item_freecoin:
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
		//case slot_item_freecoin:
			//award = straight_award_freecoin;
			//break;
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

unsigned int PlayMatchMultiple(GAMEFRAME* gameFrame){

	return 0;
}

unsigned int PlayMatchTrain(GAMEFRAME* gameFrame){

	return 0;
}

bool KeyOutCheck(MainFrame* mainFrame){
	bool result;
	unsigned long w1;
	unsigned long auto_money;
	float coin;

	auto_money = mainFrame->m_gameFrame.m_gameCredit.m_credit;

	result = false;
	coin   = (float)auto_money /(float)(mainFrame->m_settingData.m_coinValue);
	w1 = mainFrame->m_mtRandom.getRandomLong(1000);

	if (coin > DefaultKeyInOut[0][0] && coin < DefaultKeyInOut[0][1]) {
		if (w1 < DefaultKeyInOut[0][2])
		{
			result = true;
		}
	} else if (coin >= DefaultKeyInOut[1][0] && coin < DefaultKeyInOut[1][1]) {
		if (w1 < DefaultKeyInOut[1][2])
		{
			result = true;
		}
	} else if (coin >= DefaultKeyInOut[2][0] && coin < DefaultKeyInOut[2][1]) {
		if (w1 < DefaultKeyInOut[2][2])
		{
			result = true;
		}
	} else if (coin >= DefaultKeyInOut[3][0] && coin < DefaultKeyInOut[3][1]) {
		if (w1 < DefaultKeyInOut[3][2])
		{
			result = true;
		}
	} else if (coin >= DefaultKeyInOut[4][0] && coin < DefaultKeyInOut[4][1]) {
		if (w1 < DefaultKeyInOut[4][2])
		{
			result = true;
		}
	} else if (coin >= DefaultKeyInOut[5][0] && coin < DefaultKeyInOut[5][1]) {
		if (w1 < DefaultKeyInOut[5][2])
		{
			result = true;
		}
	} else if (coin >= DefaultKeyInOut[6][0] && coin < DefaultKeyInOut[6][1]) {
		if (w1 < DefaultKeyInOut[6][2])
		{
			result = true;
		}
	} else if (coin >= DefaultKeyInOut[7][0] && coin < DefaultKeyInOut[7][1]) {
		if (w1 < DefaultKeyInOut[7][2])
		{
			result = true;
		}
	} else if (coin >= DefaultKeyInOut[8][0] && coin < DefaultKeyInOut[8][1]) {
		if (w1 < DefaultKeyInOut[8][2])
		{
			result = true;
		}
	} else if (coin >= DefaultKeyInOut[9][0] && coin < DefaultKeyInOut[9][1]) {
		if (w1 < DefaultKeyInOut[9][2])
		{
			result = true;
		}
	} else if (coin >= DefaultKeyInOut[9][2]) {
		if (w1 <= 999)//100%
		{
			result = true;
		}
	}

	return result;
}
