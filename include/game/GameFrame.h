/**
 * @file GameFrame.h
 *
 */

#ifndef GAMEFRAME_H_
#define GAMEFRAME_H_

#include "../probability/ProItem.h"
#include "../probability/ProAward.h"
#include "GameCredit.h"
#include "GameRecord.h"

typedef struct _Match{
	unsigned int item;

	/**
	 * @brief Clean.
	 */
	void Clean(void){
		item = match_item_unknown;
	}

	/**
	 * @brief Constructor.
	 */
	_Match(void){
		Clean();
	}

}MATCH;/**< Match */

typedef struct _Slot{
	unsigned int item;

	/**
	 * @brief Clean.
	 */
	void Clean(void){
		item = slot_item_unknown;
	}

	/**
	 * @brief Constructor.
	 */
	_Slot(void){
		Clean();
	}

}SLOT;/**< Slot */

#define TABLE_SIZE  29

typedef struct _GameFrame{
	GAMECREDIT m_gameCredit;/**< Game Credit */
	GAMEREC m_gameRecord;/**< Game Record */
	MATCH m_match;/**< Match */
	SLOT m_slot[3];/**< Slot */
	unsigned int m_table[TABLE_SIZE];/**< Table */
	unsigned int m_matchAwardType;/**< Match Award Type */
	unsigned int m_slotAwardType;/**< Slot Award Type */

	/**
	 * @brief Clean.
	 */
	void Clean(void){
		// Reset Match/Slot Award Type
		m_matchAwardType = match_award_none;
		m_slotAwardType = straight_award_none;
		// Setup Table
		m_table[0]=match_item_orange;  //  0
		m_table[1]=match_item_cherry;  //  1
		m_table[2]=match_item_apple;   //  2
		m_table[3]=match_item_coin;    //  3
		m_table[4]=match_item_bar;     //  4
		m_table[5]=match_item_cherry;  //  5
		m_table[6]=match_item_multiple;//  6
		m_table[7]=match_item_apple;   //  7
		m_table[8]=match_item_orange;  //  8
		m_table[9]=match_item_diamond; //  9
		m_table[10]=match_item_coin;   //  10
		m_table[11]=match_item_cherry; //  11
		m_table[12]=match_item_bar;    //  12
		m_table[13]=match_item_orange; //  13
		m_table[14]=match_item_apple;  //  14
		m_table[15]=match_item_coin;   //  15
		m_table[16]=match_item_cherry; //  16
		m_table[17]=match_item_apple;  //  17
		m_table[18]=match_item_diamond;//  18
		m_table[19]=match_item_orange; //  19
		m_table[20]=match_item_apple;  //  20
		m_table[21]=match_item_train;  //  21
		m_table[22]=match_item_cherry; //  22
		m_table[23]=match_item_bar;    //  23
		m_table[24]=match_item_orange; //  24
		m_table[25]=match_item_apple;  //  25
		m_table[26]=match_item_cherry; //  26
		m_table[27]=match_item_coin;   //  27
		m_table[28]=match_item_crown;  //  28
	}

	/**
	 * @brief Constructor.
	 */
	_GameFrame(void){
		Clean();
	}

}GAMEFRAME;

#endif /* GAMEFRAME_H_ */
