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

	unsigned long m_matchAwardRec[NUM_MTACH_AWARDS];/**< Match Award Size */
	unsigned long m_slotAwardRec[NUM_STRAIGHT_AWARDS];/**< Straight Award Size */

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
	}

	/**
	 * @brief Constructor.
	 */
	_GameRecord(void){
		Clean();
	}

}GAMEREC;/**< Game Record */



#endif /* GAMERECORD_H_ */
