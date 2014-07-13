/**
 * @file GameCredit.h
 *
 */

#ifndef GAMECREDIT_H_
#define GAMECREDIT_H_

typedef struct _GameCredit{
	unsigned int m_credit;/**< Credit */
	unsigned int m_matchBet;/**< Match Bet */
	unsigned int m_slotBet[3];/**< Slot Bet */
	unsigned int m_win;/**< Win */

	unsigned int m_freetimes;/**< free times */

	/**
	 * @brief Clean All Member.
	 */
	void Clean(void){
		m_credit=0;
		m_matchBet=0;
		m_slotBet[0]=0;
		m_slotBet[1]=0;
		m_slotBet[2]=0;
		m_win=0;

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
