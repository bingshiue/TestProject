/**
 * @file GameCredit.h
 *
 */

#ifndef GAMECREDIT_H_
#define GAMECREDIT_H_

typedef struct _GameCredit{
	unsigned int m_credit;/**< Credit */
	unsigned int m_bet;/**< Bet */
	unsigned int m_win;/**< Win */

	/**
	 * @brief Clean All Member.
	 */
	void Clean(void){
		m_credit=0;
		m_bet=0;
		m_win=0;
	}

	/**
	 * @brief Constructor.
	 */
	_GameCredit(void){
		Clean();
	}


}GAMECREDIT;/**< Game Credit */



#endif /* GAMECREDIT_H_ */
