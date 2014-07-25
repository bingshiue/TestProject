/**
 * @file ProMultipleSubFunc.cpp
 *
 */
#include "../include/log.h"
#include "../include/probability/ProDefine.h"
#include "../include/probability/ProType.h"
#include "../include/probability/ProItem.h"
#include "../include/probability/ProAward.h"
#include "../include/probability/ProMulTable.h"
#include "../include/probability/ProMultipleSubFunc.h"

unsigned int multiple_result[MULTIPLE_MAX_TIMES];
unsigned int multiple_idx;

unsigned int item_count[match_item_count][2] = {
		{match_item_unknown, 0},
		{match_item_cherry,  6},
		{match_item_apple,   6},
		{match_item_orange,  5},
		{match_item_coin,    4},
		{match_item_bar,     3},
		{match_item_diamond, 2},
		{match_item_crown,   1},
		{match_item_multiple,1},
		{match_item_train,   1}
};

unsigned int DrawMatchMultipleItem(MainFrame* mainFrame,unsigned int time, unsigned int totalTimes){
	int random = 0;
	MATCHMULTIPLESTEP* matchMultipleStep = &(mainFrame->m_matchMultipleStep);

	unsigned int finalChance = (totalTimes==time) ? true : false ;// Final Chance

	if(finalChance==true){
		random = mainFrame->m_mtRandom.getRandomLong(RANDOM_BASE);
	}else{
		int tmp_base = RANDOM_BASE - wxAtoi(mainFrame->m_matchMultipleItemPanel->mItem_train_tc->GetValue());
		LOGD("Probability","%s:tmp_base = %d \n",__func__,tmp_base);
		random = mainFrame->m_mtRandom.getRandomLong(tmp_base);
	}

	unsigned int ret = match_item_unknown;

	if (random < matchMultipleStep->step1)
		ret = match_item_cherry;
	else if (random >= matchMultipleStep->step1 && random < matchMultipleStep->step2)
		ret = match_item_apple;
	else if (random >= matchMultipleStep->step2 && random < matchMultipleStep->step3)
		ret = match_item_orange;
	else if (random >= matchMultipleStep->step3 && random < matchMultipleStep->step4)
		ret = match_item_coin;
	else if (random >= matchMultipleStep->step4 && random < matchMultipleStep->step5)
		ret = match_item_bar;
	else if (random >= matchMultipleStep->step5 && random < matchMultipleStep->step6)
		ret = match_item_diamond;
	else if (random >= matchMultipleStep->step6 && random < matchMultipleStep->step7)
		ret = match_item_crown;
	else if (random >= matchMultipleStep->step7 && random < matchMultipleStep->step8)
		ret = match_item_multiple;
	else if (random >= matchMultipleStep->step8 && random < matchMultipleStep->step9)
		ret = match_item_train;

	assert(ret > 0);

	return ret;
}

unsigned int CheckItemCount(unsigned int item){
	int ret = -1;
	unsigned int tmp_cnt=0;

	for(int idx=0; idx<MULTIPLE_MAX_TIMES; idx++){
		if(multiple_result[idx]==item){
			tmp_cnt++;
		}
	}

	if(tmp_cnt < item_count[item][1]){
		ret = 0;
	}

	return ret;
}

unsigned int GetMatchMultipleAward(GAMEFRAME* gameFrame,unsigned int item){
	unsigned int award = match_award_none;
	unsigned int slot_freecoin_cnt=0;
	bool bingo = false;

	switch(item){
	case match_item_cherry:
	case match_item_apple:
	case match_item_orange:
	case match_item_bar:
	case match_item_diamond:
	case match_item_crown:
		for(unsigned int idx=0; idx<sizeof(gameFrame->m_slot)/sizeof(gameFrame->m_slot[0]); idx++){
			if(item == gameFrame->m_slot[idx].item){
				bingo = true;
				break;
			}
		}
		break;

	case match_item_coin:
		for(unsigned int idx=0; idx<sizeof(gameFrame->m_slot)/sizeof(gameFrame->m_slot[0]); idx++){
			if(gameFrame->m_slot[idx].item==slot_item_coin || gameFrame->m_slot[idx].item==slot_item_freecoin){
				bingo = true;
				if(item==slot_item_freecoin){
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
		LOGE("Probability","%s: Error => item = %d \n",__func__,item);
		break;

	}


	if(bingo==true){
		switch(item){

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
#if 0
			//freecoin
			if(slot_freecoin_cnt > 0){
				LOGI("Probability","Win Free Time, Match Item = %d, Slot Item= %d,%d,%d \n",gameFrame->m_match.item,gameFrame->m_slot[0].item,gameFrame->m_slot[1].item,gameFrame->m_slot[2].item);
				gameFrame->m_gameCredit.m_freetimes += (slot_freecoin_cnt*5);
				LOGI("Probability","%s: Free Time += %d, Free Times = %d \n",__func__,slot_freecoin_cnt*5, gameFrame->m_gameCredit.m_freetimes);
			}
#endif
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
			LOGE("Probability","%s: Match Multiple Award Error ! \n",__func__);
			break;
		}
	}

	LOGD("Probability","%s: Match Multiple Award=%d \n",__func__,award);

	// Record Award
	gameFrame->m_gameRecord.m_totalMatchMultipleAwardRec[award]++;

	return award;
}

unsigned int GetMatchMultipleWin(unsigned int matchAward,unsigned int bet){
	unsigned int matchMultipleWin = 0;

	matchMultipleWin = MatchAwardMulTable[matchAward] * bet;
	LOGD("Probability","%s: Match Muliple Win = %d \n",__func__,matchMultipleWin);

	return matchMultipleWin;
}

unsigned int PlayMatchMultiple(MainFrame* mainFrame,unsigned int *drawTrain){

	int item=0;
	int check_cnt_result=0;
	int award;
	unsigned int totalWin=0;
	unsigned int playTimes=0;

	*drawTrain = false;

	for(int idx=0; idx<MULTIPLE_MAX_TIMES; idx++) multiple_result[idx]=0;
	multiple_idx=0;

	// Decide Play Times
	playTimes = mainFrame->m_mtRandom.getRandomLong(MULTIPLE_MIN_TIMES,MULTIPLE_MAX_TIMES);
	LOGD("Probability","%s:Decide Multiple Times = %d \n",__func__,playTimes);

	while(multiple_idx < playTimes ){
		item = DrawMatchMultipleItem(mainFrame,(multiple_idx+1),playTimes);
		check_cnt_result = CheckItemCount(item);

		if(!check_cnt_result){
			multiple_result[multiple_idx] = item;
			multiple_idx++;
		}else{
			continue;
		}
	};

	for(unsigned int idx=0; idx<playTimes; idx++){
		award = GetMatchMultipleAward(&mainFrame->m_gameFrame,multiple_result[idx]);
		totalWin += GetMatchMultipleWin(award,mainFrame->m_gameFrame.m_gameCredit.m_matchBet);

		if(award==match_award_train){
			*drawTrain = true;
			LOGD("Probability","%s:Draw Train in Multiple \n",__func__);
		}
	}

	return totalWin;
}

