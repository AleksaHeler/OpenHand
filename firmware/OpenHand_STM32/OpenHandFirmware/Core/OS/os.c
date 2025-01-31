/**
 * @brief Custom "operating system" implementation, handling drivers and application components
 */

/***********************************************************************/
/* Includes                                                            */
/***********************************************************************/

#include "os_e.h"
#include "os_i.h"

/***********************************************************************/
/* OS singleton instance                                               */
/***********************************************************************/

/** @brief OS Manager singleton instance */
static os_g_Manager_s os_s_ManagerInstance_s;

/***********************************************************************/
/* Helper functions                                                    */
/***********************************************************************/

/** @todo: execution time measuring helper functions */

/***********************************************************************/
/* Functions                                                           */
/***********************************************************************/

/**
 * @brief Function to get the singleton instance of the OS Manager
 */
os_g_Manager_s* os_f_GetManagerInstance_s()
{
  return &os_s_ManagerInstance_s;
}

/** 
 * @brief Register the given (driver/app) component with the OS Manager, to be handled later
 * 
 * @param manager - OS Manager instance
 * @param component - Component to be registered
 */
void os_f_RegisterComponent_v(os_g_Manager_s* manager, ComponentInterface* component)
{
  if (manager->l_ComponentCount_u32 < MAX_NUM_OF_COMPONENTS)
  {
    manager->l_Components_as[manager->l_ComponentCount_u32++] = component;
    /** @todo: add print statements? */
  }
  else
  {
    /** @todo: make this more descriptive maybe? Add print statements */
  }
  return;
}

/** 
 * @brief Initialize all compoennts, following the interface structure
 * 
 * @param manager - OS Manager instance
 */
void os_f_InitializeComponents_v(os_g_Manager_s* manager)
{
  uint32 i;

  for (i = 0; i < manager->l_ComponentCount_u32; i++) {
    ReturnStatus l_ComponentStatus = manager->l_Components_as[i]->init(NULL);
    if (l_ComponentStatus != RETURN_STATUS_OK) {
      /* Log error, or do something, failsafe if error is HW or idk. */
      /* Maybe even halt execution and stay in failsafe... */
    }
  }
}

/** 
 * @brief Handle all compoennts, following the interface structure
 * 
 * @param manager - OS Manager instance
 */
void os_f_HandleComponents_v(os_g_Manager_s* manager)
{
  uint32 i;

  for (i = 0; i < manager->l_ComponentCount_u32; i++) {
    ReturnStatus l_ComponentStatus = manager->l_Components_as[i]->handle(NULL, NULL);
    if (l_ComponentStatus != RETURN_STATUS_OK) {
      /* Log error, or do something, failsafe if error is HW or idk. */
    }
    /** @todo: implement helper functions to monitor execution times and store it in global 'params' structure to be passed to all components as pointer (alongside other system info data there) */
  }
}

