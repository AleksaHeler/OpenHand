#ifndef OS_OS_E_H_
#define OS_OS_E_H_

/***********************************************************************/
/* Includes                                                            */
/***********************************************************************/

#include "defines.h"

/***********************************************************************/
/* Module defines                                                      */
/***********************************************************************/

#define MAX_NUM_OF_COMPONENTS 20

/** @brief OS Manager Singleton */
typedef struct {
    ComponentInterface *l_Components_as[MAX_NUM_OF_COMPONENTS];
    uint32 l_ComponentCount_u32;
} os_g_Manager_s;


/***********************************************************************/
/* Functions                                                           */
/***********************************************************************/

/**
 * @brief Function to get the singleton instance of the OS Manager
 */
os_g_Manager_s* os_f_GetManagerInstance_s();

/** 
 * @brief Register the given (driver/app) component with the OS Manager, to be handled later
 */
void os_f_RegisterComponent_v(os_g_Manager_s* manager, ComponentInterface* component);

/** 
 * @brief Initialize all compoennts, following the interface structure
 */
void os_f_InitializeComponents_v(os_g_Manager_s* manager);

/** 
 * @brief Handle all compoennts, following the interface structure
 */
void os_f_HandleComponents_v(os_g_Manager_s* manager);


#endif /* OS_OS_E_H_ */
