/**
 * @file settingType.h
 *
 */

#ifndef SETTING_TYPE_H_
#define SETTING_TYPE_H_

#include "settingDefault.h"

typedef struct SettingData{
	unsigned int m_maxKeyIn;/**< Max Key In */
	unsigned int m_coinValue;/**< Coin Value */
	unsigned int m_maxBet;/**< Max Bet */
	unsigned int m_mainGameOverMaxWin;/**< Main Game Over Max Win */
	unsigned int m_doubleGameOverMaxWin;/**< Double Game Over Max Win */
    unsigned char m_runDoubleGame;/**< Run Double Game */
    unsigned char m_runToDead;/**< Run To Dead (Doublr Game) */

	/**
	 * @brief Constructor.
	 */
	SettingData(void){
		m_maxKeyIn = DEFAULT_MAX_KEYIN;
		m_coinValue = DEFAULT_COIN_VALUE;
		m_maxBet = DEFAULT_MAX_BET;
		m_mainGameOverMaxWin = DEFAULT_MAIN_GAME_OVER_MAX_WIN;
		m_doubleGameOverMaxWin = DEFAULT_DOUBLE_GAME_OVER_MAX_WIN;
		m_runDoubleGame = DEFAULT_RUN_DOUBLE_GAME;
		m_runToDead = DEFAULT_RUN_TO_DEAD;
	}

}SETTINGDATA;/**< Setting Data */



#endif /* SETTING_TYPE_H_ */
