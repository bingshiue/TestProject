/**
 * @file GameCredit.h
 *
 */

#ifndef GAMECREDIT_H_
#define GAMECREDIT_H_

typedef struct _GameCredit{
	unsigned int m_credit;/**< Credit */
	unsigned int m_slotAwardBet;/**< SLot Award Bet */
	unsigned int m_matchAwardBet[3];/**< Match Award Bet */
	unsigned int m_win;/**< Win */
	unsigned int m_matchMultipleWin;/**< Match Multiple Win */
	unsigned int m_matchTrainWin;/**< Match Train Win */

	unsigned int m_freetimes;/**< free times */

	/**
	 * @brief Clean All Member.
	 */
	void Clean(void){
		m_credit=0;
		m_slotAwardBet=0;
		m_matchAwardBet[0]=0;
		m_matchAwardBet[1]=0;
		m_matchAwardBet[2]=0;
		m_win=0;
		m_matchMultipleWin=0;
		m_matchTrainWin=0;

		m_freetimes=0;
	}

	/**
	 * @brief Constructor.
	 */
	_GameCredit(void){
		Clean();
	}


}GAMECREDIT;/**< Game Credit */



#endif /* GAMECREDIT_H_ */
