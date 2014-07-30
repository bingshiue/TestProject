/**
 * @file GameFrame.h
 *
 */

#ifndef GAMEFRAME_H_
#define GAMEFRAME_H_

#include "../common.h"
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

typedef struct _Table{
	unsigned int m_kind;
	unsigned char m_train_used;
	unsigned char m_multiple_used;

	/**
	 * @brief Clean.
	 */
	void Clean(void){
		m_kind = match_item_unknown;
		m_train_used = 0;
		m_multiple_used = 0;
	}

	/**
	 * @brief Constructor.
	 */
	_Table(void){
		Clean();
	}


}TABLE;/**< Table */

typedef struct _GameFrame{
	GAMECREDIT m_gameCredit;/**< Game Credit */
	GAMEREC m_gameRecord;/**< Game Record */
	MATCH m_match;/**< Match */
	SLOT m_slot[3];/**< Slot */
	TABLE m_table[TOTAL_FRAME_COUNT];/**< Table */
	unsigned int m_matchAwardType;/**< Match Award Type */
	unsigned int m_matchCount;/**M Match Count */
	unsigned int m_slotAwardType;/**< Slot Award Type */

	/**
	 * @brief Clean.
	 */
	void Clean(void){
		// Reset Match/Slot Award Type
		m_matchAwardType = match_award_none;
		m_matchCount = 0;
		m_slotAwardType = straight_award_none;
		// Clean Table
		for(int idx=0; idx<TOTAL_FRAME_COUNT; idx++ ) { m_table[idx].Clean(); }
		// Setup Table
		m_table[0].m_kind=match_item_orange;  //  0
		m_table[1].m_kind=match_item_cherry;  //  1
		m_table[2].m_kind=match_item_apple;   //  2
		m_table[3].m_kind=match_item_coin;    //  3
		m_table[4].m_kind=match_item_bar;     //  4
		m_table[5].m_kind=match_item_cherry;  //  5
		m_table[6].m_kind=match_item_multiple;//  6
		m_table[7].m_kind=match_item_apple;   //  7
		m_table[8].m_kind=match_item_orange;  //  8
		m_table[9].m_kind=match_item_diamond; //  9
		m_table[10].m_kind=match_item_coin;   //  10
		m_table[11].m_kind=match_item_cherry; //  11
		m_table[12].m_kind=match_item_bar;    //  12
		m_table[13].m_kind=match_item_orange; //  13
		m_table[14].m_kind=match_item_apple;  //  14
		m_table[15].m_kind=match_item_coin;   //  15
		m_table[16].m_kind=match_item_cherry; //  16
		m_table[17].m_kind=match_item_apple;  //  17
		m_table[18].m_kind=match_item_diamond;//  18
		m_table[19].m_kind=match_item_orange; //  19
		m_table[20].m_kind=match_item_apple;  //  20
		m_table[21].m_kind=match_item_train;  //  21
		m_table[22].m_kind=match_item_cherry; //  22
		m_table[23].m_kind=match_item_bar;    //  23
		m_table[24].m_kind=match_item_orange; //  24
		m_table[25].m_kind=match_item_apple;  //  25
		m_table[26].m_kind=match_item_cherry; //  26
		m_table[27].m_kind=match_item_coin;   //  27
		m_table[28].m_kind=match_item_crown;  //  28
	}

	/**
	 * @brief Constructor.
	 */
	_GameFrame(void){
		Clean();
	}

}GAMEFRAME;

#endif /* GAMEFRAME_H_ */
