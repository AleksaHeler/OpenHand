/**
 * Headerfile included in all other parts of code, containing common defines
 *
 * Here we define driver interfaces, error codes etc.
 *
 */
#ifndef INC_DEFINES_H_
#define INC_DEFINES_H_

/***********************************************************************/
/* Includes                                                            */
/***********************************************************************/

#include "global.h"

/***********************************************************************/
/* Driver/application component interface define                       */
/***********************************************************************/

/** 
 * @brief Structure holding everything required from the driver/application component
 * 
 * Init/Handle function pointers, control register, etc.
 */
typedef struct
{
  /** @brief Initialization function, takes in some parameters */
  ReturnStatus (*init)(void *params);
  /** @brief Handling function, may take parameters and a callback function */
  ReturnStatus (*handle)(void *params, void (*callback)(void));
  /** @brief Main control register for the component */
  bit32* comp_g_Control_b32;
} ComponentInterface;


#endif /* INC_DEFINES_H_ */
