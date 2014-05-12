/**
 * @file ProType.h
 *
 */

#ifndef PROTYPE_H_
#define PROTYPE_H_

/**
 * @brief Slot Probability Step Structure.
 */
typedef struct SlotProStep{
	int step1;/**< step 1 */
	int step2;/**< step 2 */
	int step3;/**< step 3 */
	int step4;/**< step 4 */
	int step5;/**< step 5 */
	int step6;/**< step 6 */
	int step7;/**< step 7 */
	int step8;/**< step 8 */
	int step9;/**< step 9 */

	/**
	 * @brief Constructor.
	 */
	SlotProStep(){
		step1=0;
		step2=0;
		step3=0;
		step4=0;
		step5=0;
		step6=0;
		step7=0;
		step8=0;
		step9=0;
	}

	/**
	 * @brief Reset all member parameter.
	 */
	void Reset(void){
		step1=0;
		step2=0;
		step3=0;
		step4=0;
		step5=0;
		step6=0;
		step7=0;
		step8=0;
		step9=0;
	}

}SLOTPROSTEP;

/**
 * @brief Match Probability Step Structure.
 */
typedef struct MatchProStep{
	int step1;/**< step 1 */
	int step2;/**< step 2 */
	int step3;/**< step 3 */
	int step4;/**< step 4 */
	int step5;/**< step 5 */
	int step6;/**< step 6 */
	int step7;/**< step 7 */
	int step8;/**< step 8 */
	int step9;/**< step 9 */

	/**
	 * @brief Constructor.
	 */
	MatchProStep(){
		step1=0;
		step2=0;
		step3=0;
		step4=0;
		step5=0;
		step6=0;
		step7=0;
		step8=0;
		step9=0;
	}

	/**
	 * @brief Reset all member parameter.
	 */
	void Reset(void){
		step1=0;
		step2=0;
		step3=0;
		step4=0;
		step5=0;
		step6=0;
		step7=0;
		step8=0;
		step9=0;
	}

}MATCHPROSTEP;



#endif /* PROTYPE_H_ */
