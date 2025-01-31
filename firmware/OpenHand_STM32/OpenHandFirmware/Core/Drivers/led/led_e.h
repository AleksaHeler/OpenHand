/**
 * Headerfile (external) belonging to the corresponding .c file
 *
 * Here we define 'public' functions, variables and defines, to be accessed by other modules.
 * 
 * @todo: describe how other components should use this driver (write 0/1 in array to control LEDs, control register bits, etc.)
 */
#ifndef LED_E_H_
#define LED_E_H_

/***********************************************************************/
/* Includes                                                            */
/***********************************************************************/

#include "defines.h"


/***********************************************************************/
/* Global variables                                                    */
/***********************************************************************/

/** @todo: define what bits of control register do (en/dis driver, set LEDs to failsafe...) */

/**
 * @brief LED driver control register
 */
extern bit32 led_g_Control_b32;

/**
 * @brief Total number of available LEDs
 */
extern const uint32 led_c_NumOfLeds_u32;

/**
 * @brief LED states, to be accessed by other modules
 */
extern bit8 led_g_LedStates_ab8[];


/***********************************************************************/
/* Functions                                                           */
/***********************************************************************/

/** @brief Returns singleton instance of this drivers interface structure */
extern ComponentInterface* led_f_GetInstance_s();

/** @brief Init function */
extern ReturnStatus led_f_Init_s(void *params);
/** @brief Handle function */
extern ReturnStatus led_f_Handle_s(void *params, void (*callback)(void));


#endif /* LED_E_H_ */
