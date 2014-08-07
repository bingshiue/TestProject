/**
 * @file ProTrainSubFunc.cpp
 *
 */
#include "../include/log.h"
#include "../include/probability/ProDefine.h"
#include "../include/probability/ProType.h"
#include "../include/probability/ProItem.h"
#include "../include/probability/ProAward.h"
#include "../include/probability/ProMulTable.h"
#include "../include/probability/ProTrainSubFunc.h"

unsigned int DrawMatchTrainHeadFrame(MainFrame* mainFrame){
	int random = 0;
	random = mainFrame->m_mtRandom.getRandomLong(RANDOM_BASE);

	MATCHTRAINSTEP* matchTrainStep = &(mainFrame->m_matchTrainStep);

	unsigned int head=0;

	for(unsigned int idx=0; idx<TOTAL_FRAME_COUNT; idx++){
		if(idx==0){
			if(random < matchTrainStep->step[idx]){
				head = idx;
				break;
			}
		}else{
			if(random >= matchTrainStep->step[idx-1] && random < matchTrainStep->step[idx]){
				head = idx;
				break;
			}
		}
	}

	assert(head >= 0 && head < 29);

	LOGD("Probability","%s: Draw Head Frame =%d \n",__func__,head);

	return head;
}

unsigned int GetMatchTrainAward(GAMEFRAME* gameFrame,unsigned int item){
	unsigned award=match_award_none;
	unsigned int slot_freecoin_cnt=0;
	bool bingo = false;

	gameFrame->m_matchCount = 0;

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
				gameFrame->m_matchCount++;
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
				gameFrame->m_matchCount++;
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
			LOGE("Probability","%s: Match Train Award Error ! \n",__func__);
			break;
		}
	}

	LOGD("Probability","%s: Match Train Award=%d \n",__func__,award);

	// Record Award
	gameFrame->m_gameRecord.m_totalMatchTrainAwardRec[award]++;

	return award;
}

unsigned int GetMatchTrainWin(GAMEFRAME* gameFrame,unsigned int matchAward,unsigned int* bet){
	unsigned int matchTrainWin = 0;

	matchTrainWin = MatchAwardMulTable[matchAward] * (bet[0]+bet[1]+bet[2]) * gameFrame->m_matchCount;
	LOGD("Probability","%s: Match Train Award = %d, Match Train Count = %d, Match Train Win = %d \n",__func__,matchAward,gameFrame->m_matchCount,matchTrainWin);

	return matchTrainWin;
}

unsigned int PlayMatchTrain(MainFrame* mainFrame){
	int head_frame=0;
	unsigned int item=match_item_unknown;
	int award;
	unsigned int totalWin=0;

	// head_frame is index
	head_frame = DrawMatchTrainHeadFrame(mainFrame);

	// Record head frame
	mainFrame->m_gameFrame.m_gameRecord.m_totalMatchTrainDrawFrameRec[head_frame]++;

	for(unsigned idx=0; idx<TRAIN_FRAME_COUNT; idx++){
		// get frame
		item = mainFrame->m_gameFrame.m_table[head_frame].m_kind;
		// get award
		award = GetMatchTrainAward(&mainFrame->m_gameFrame,item);
		// get win
		totalWin += GetMatchTrainWin(&mainFrame->m_gameFrame,award,mainFrame->m_gameFrame.m_gameCredit.m_matchAwardBet);

		// get next frame
		head_frame--;
		if(head_frame < TRAIN_HEAD_FRAME){
			head_frame = TRAIN_TAIL_FRAME;
		}
	}

	return totalWin;
}




