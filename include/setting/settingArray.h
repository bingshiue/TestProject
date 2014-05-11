/**
 * @file settingArray.h
 *
 */

#ifndef SETTING_ARRAY_H_
#define SETTING_ARRAY_H_

#include "settingDefault.h"

/* Coin Value */
const unsigned int coinValueTab[6] = { 1, 5, 10, 20, 50, 100 };

/* Max Bet */
const unsigned int maxBetTab[5] = { 10,20,30,40,50 };

/* Main Over Max Win */
const unsigned int mainOverMaxWinTab[7] = { 1000, 2000, 3000, 4000, 5000, 10000, DISABLE };

/* Double Up Over Max Win */
const unsigned int doubleOverMaxWinTab[10] = { 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000 };

#endif /* SETTING_ARRAY_H_ */
