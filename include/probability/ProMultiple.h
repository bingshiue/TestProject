/**
 * @file ProMultiple.h
 *
 */

#ifndef PROMULTIPLE_H_
#define PROMULTIPLE_H_

unsigned int MatchAwardMulTable[10]={
		0,  /**< Match None */
		2,  /**< Match Cherry */
		5,  /**< Match Apple */
		7,  /**< Match Orange */
		12, /**< Match Coin */
		25, /**< Match Bar */
		50, /**< Match Diamond */
		100,/**< Match Crown */
		0,  /**< Match Multiple */
		0   /**< Match Train */
};/**< Match Award Multiple Table */

unsigned int SlotAwardMulTable[10]={
		0,  /**< None */
		10, /**< Cherry Straight */
		15, /**< Apple Straight */
		20, /**< Orange Straight */
		30, /**< Coin Straight */
		50, /**< Bar Straight */
		150,/**< Diamond  Straight */
		300,/**< Crown Straight */
		30, /**< Freecoin Straight == Coin Straight */
		0   /**< Roulette Straight */
};/**< Slot Straight Award Multiple Table */



#endif /* PROMULTIPLE_H_ */
