/**
 * @file setting.h
 *
 */

#ifndef SETTING_H_
#define SETTING_H_

enum {
	Disable = 0,
	Enable = 1
};

/*  */
const unsigned int defaultMaxKeyIn = 50000;

/* Coin Value */
const unsigned int coinValueTab[6] = { 1, 5, 10, 20, 50, 100 };

/* Max Bet */
const unsigned int maxBetTab[15] = { 8,16,24,32,40,48,64,80,160,240,320,400,480,640,800 };

/* Main Over Max Win */
const unsigned int mainOverMaxWinTab[7] = { 1000, 2000, 3000, 4000, 5000, 10000, Disable };

/* Double Up Over Max Win */
const unsigned int doubleOverMaxWinTab[10] = { 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000 };

#endif /* SETTING_H_ */
