/**
 * @brief On-board LED driver
 *
 * Here we define 'private' functions, variables and defines, used only by this driver.
 */

/***********************************************************************/
/* Includes                                                            */
/***********************************************************************/

/* System headerfiles */
#include "defines.h"

/* Own headerfiles */
#include "led_e.h"
#include "led_i.h"

/***********************************************************************/
/* Component singleton instance                                        */
/***********************************************************************/

/** @brief LED component singleton instance */
static ComponentInterface led_s_Instance_s =
{
  .init = (ReturnStatus (*)(void *))led_f_Init_s,
  .handle = (ReturnStatus (*)(void *, void (*)(void)))led_f_Handle_s,
  .comp_g_Control_b32 = &led_g_Control_b32
};

/***********************************************************************/
/* Helper functions                                                    */
/***********************************************************************/

ReturnStatus led_f_InitChannel_s()
{
  /*todo*/
  return RETURN_STATUS_OK;
}

ReturnStatus led_f_HandleChannel_s()
{
  /*todo*/
  return RETURN_STATUS_OK;
}

/***********************************************************************/
/* Functions                                                           */
/***********************************************************************/

/** @brief Returns singleton instance of this drivers interface structure */
ComponentInterface *led_f_GetInstance_s()
{
  return &led_s_Instance_s;
}

/**
 * @brief Init function
 *
 * @param params Parameters for the initialization
 */
ReturnStatus led_f_Init_s(void *params)
{
  uint32 i;

  /* Reset driver control bits */
  led_g_Control_b32.dword = 0;

  /* Initialize all available HW channels */
  for (i = 0; i < led_c_NumOfLeds_u32; i++)
  {
    if (led_f_InitChannel_s() != RETURN_STATUS_OK)
    {
      return RETURN_STATUS_ERROR;
    }
  }

  /* Set driver active bit flag to 1 */
  led_g_Control_b32.bits.b0 = 1;

  return RETURN_STATUS_OK;
}

/**
 * @brief Handle function
 *
 * @param params Parameters for the initialization
 * @param callback Function pointer to be called while waiting, or at the end of the function
 */
ReturnStatus led_f_Handle_s(void *params, void (*callback)(void))
{
  uint32 i;

  /* Handle all available HW channels */
  for (i = 0; i < led_c_NumOfLeds_u32; i++)
  {
    if (led_f_HandleChannel_s(/*todo*/) != RETURN_STATUS_OK)
    {
      return RETURN_STATUS_ERROR;
    }
  }

  return RETURN_STATUS_OK;
}
