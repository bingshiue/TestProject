/**
 * @file GameRecord.h
 *
 */

#ifndef GAMERECORD_H_
#define GAMERECORD_H_

#include "../probability/ProAward.h"

typedef struct _GameRecord{
	unsigned long m_totalKeyInCoin;/**< Total Key In Coins */
	unsigned long m_totalKeyOutCoin;/**< Total Key Out Coins */
	unsigned long m_totalMainPlayScores;/**< Total Main Play Scores */
	unsigned long m_totalMainPlayTimes;/**< Total Main Play Win Times */
	unsigned long m_totalMainWinScores;/**< Total Main Win Scores */
	unsigned long m_totalMainWinTimes;/**< Total Main Win Times */
	unsigned long m_totalDoublePlayScores;/**< Total Double */
	unsigned long m_totalDoublePlayTimes;/**< Total Double  */
	unsigned long m_totalDoubleWinScores;/**< Total Double  */
	unsigned long m_totalDoubleWinTimes;/**< Total Double  */
	unsigned long m_totalMainOverMaxWinTimes;/**< Total Main Over Max Win Times */
	unsigned long m_totalDoubleOverMaxWinTimes;/**< Total Double Over Max Win Times */
	unsigned long m_maxDoubleContinousWinTimes;/**< Max Double Continous Win Times */

	unsigned long m_matchAwardRec[NUM_MTACH_AWARDS];/**< Match Award Record */
	unsigned long m_slotAwardRec[NUM_STRAIGHT_AWARDS];/**< Straight Award Record */

	unsigned long m_totalFreeTimes;/**< Total Free Times */

	unsigned long m_totalMatchMultiplePlayTimes;/**< Total Match Multiple Play Times */
	unsigned long m_totalMatchMultipleWinTimes;/**< Total Match Multiple Win Times */
	unsigned long m_totalMatchMultiplePlay;/**< Total Match Multiple Play */
	unsigned long m_totalMatchMultipleWin;/**< Total Match Multiple Win */
	unsigned long m_totalMatchMultipleAwardRec[NUM_MTACH_AWARDS];/**< Total Match Multiple Award Record */


	unsigned long m_totalMatchTrainPlayTimes;/**< Total Match Train Play Times */
	unsigned long m_totalMatchTrainWinTimes;/**< Total Match Train Win Times */
	unsigned long m_totalMatchTrainPlay;/**< Total Match Train Play */
	unsigned long m_totalMatchTrainWin;/**< Total Match Train Win */
	unsigned long m_totalMatchTrainAwardRec[NUM_MTACH_AWARDS];/**< Total Match Train Award Record */

	/**
	 * @brief Clean All Member
	 */
	void Clean(void){
		m_totalKeyInCoin=0;
		m_totalKeyOutCoin=0;
		m_totalMainPlayScores=0;
		m_totalMainPlayTimes=0;
		m_totalMainWinScores=0;
		m_totalMainWinTimes=0;
		m_totalDoublePlayScores=0;
		m_totalDoublePlayTimes=0;
		m_totalDoubleWinScores=0;
		m_totalDoubleWinTimes=0;
		m_totalMainOverMaxWinTimes=0;
		m_totalDoubleOverMaxWinTimes=0;
		m_maxDoubleContinousWinTimes=0;
		for(unsigned int idx=0;idx<sizeof(m_matchAwardRec)/sizeof(m_matchAwardRec[0]);idx++) m_matchAwardRec[idx]=0;
		for(unsigned int idx=0;idx<sizeof(m_slotAwardRec)/sizeof(m_slotAwardRec[0]);idx++) m_slotAwardRec[idx]=0;
		m_totalFreeTimes=0;
		m_totalMatchMultiplePlayTimes=0;
		m_totalMatchMultipleWinTimes=0;
		m_totalMatchMultiplePlay=0;
		m_totalMatchMultipleWin=0;
		for(unsigned int idx=0;idx<sizeof(m_totalMatchMultipleAwardRec)/sizeof(m_totalMatchMultipleAwardRec[0]);idx++) m_totalMatchMultipleAwardRec[idx]=0;
		m_totalMatchTrainPlayTimes=0;
		m_totalMatchTrainWinTimes=0;
		m_totalMatchTrainPlay=0;
		m_totalMatchTrainWin=0;
		for(unsigned int idx=0;idx<sizeof(m_totalMatchTrainAwardRec)/sizeof(m_totalMatchTrainAwardRec[0]);idx++) m_totalMatchTrainAwardRec[idx]=0;
	}

	/**
	 * @brief Constructor.
	 */
	_GameRecord(void){
		Clean();
	}

}GAMEREC;/**< Game Record */



#endif /* GAMERECORD_H_ */
