/**
 * @file ProAward.h
 *
 */

#ifndef AWARD_H_
#define AWARD_H_


enum MATCH_AWARD {
	match_award_none = 0,    /**< Match Award None */
	match_award_cherry,      /**< Match Award Cherry */
	match_award_orange,      /**< Match Award Orange */
	match_award_apple,       /**< Match Award Apple */
	match_award_coin,        /**< Match Award Coin */
	match_award_bar,         /**< Match Award Bar */
	match_award_diamond,     /**< Match Award Diamond */
	match_award_crown,       /**< Match Award Crown */
	match_award_multiple,    /**< Match Award Multiple */
	match_award_train,       /**< Match Award Train */

};/**< Match Award */

enum STRAIGHT_AWARD {
	straight_award_none = 0, /**< Straight Award None */
	straight_award_cherry,   /**< Straight Award Cherry */
	straight_award_orange,   /**< Straight Award Orange */
	straight_award_apple,    /**< Straight Award Apple */
	straight_award_coin,     /**< Straight Award Coin */
	straight_award_bar,      /**< Straight Award Bar */
	straight_award_diamond,  /**< Straight Award Diamond */
	straight_award_crown,    /**< Straight Award Crown */
	straight_award_freecoin, /**< Straight Award Freecoin */
	straight_award_roulette, /**< Straight Award Roulette */

};/**< Straight Award */


#endif /* AWARD_H_ */
