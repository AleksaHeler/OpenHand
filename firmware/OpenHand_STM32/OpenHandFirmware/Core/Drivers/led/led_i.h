/**
 * Headerfile (internal) belonging to the corresponding .c file
 *
 * Here we define 'private' functions, variables and defines, used only by this driver.
 */
#ifndef LED_I_H_
#define LED_I_H_

/***********************************************************************/
/* Includes                                                            */
/***********************************************************************/

#include "defines.h"
#include "led_e.h"


/***********************************************************************/
/* Module defines                                                      */
/***********************************************************************/

#define DEFAULT_LED_STATE 0

const uint32 led_c_NumOfLeds_u32 = 2;


/***********************************************************************/
/* Hardware configuration defines                                      */
/***********************************************************************/

/** Structure describing everything needed to initialize and handle digital output on STM32 */
typedef struct
{
  /** @brief GPIO port */
  uint16 port;
  /** @brief GPIO pin */
  uint16 pin;
} led_g_LedChnCfg_s;

//const led_g_LedChnCfg_s led_g_LedChannels_as[led_c_NumOfLeds_u32] =
//{
//  /* Dummy data! */
//  { 1, 1 }, /* LED_01 - port x, pin x */
//  { 1, 2 }  /* LED_02 - port x, pin x */
//};

/***********************************************************************/
/* Functions                                                           */
/***********************************************************************/

/* Exported functions */

ReturnStatus led_f_Init_s(void *params);
ReturnStatus led_f_Handle_s(void *params, void (*callback)(void));

/* Helper functions */

ReturnStatus led_f_InitChannel_s();
ReturnStatus led_f_HandleChannel_s();

/***********************************************************************/
/* Global variables                                                    */
/***********************************************************************/

bit32 led_g_Control_b32;

bit8 led_g_LedStates_ab8[2] = 
{
  DEFAULT_LED_STATE, DEFAULT_LED_STATE
};


#endif /* LED_I_H_ */
