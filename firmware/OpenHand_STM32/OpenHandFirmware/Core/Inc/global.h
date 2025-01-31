/**
 * Headerfile included in all other parts of code, containing global type definitions
 *
 * Here we define bitfields to access all possible bits of a register
 *
 */
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

/***********************************************************************/
/* Includes                                                            */
/***********************************************************************/

#include <inttypes.h> /* uint32_t definitions */
#include <stddef.h>   /* NULL definition */

/***********************************************************************/
/* Return status types, errors                                         */
/***********************************************************************/

/**
 * @brief Return type definition. Global, will be used by our functions. 0 is OK, everything else is an error.
 */
typedef enum
{
  RETURN_STATUS_OK = 0,
  RETURN_STATUS_ERROR,
  RETURN_STATUS_HARDWARE_ERROR,
  RETURN_STATUS_NULL_CALLBACK
  // RETURN_STATUS_INVALID_PARAMETER,
  // RETURN_STATUS_OUT_OF_MEMORY,
  // RETURN_STATUS_TIMEOUT
  /** Possibility to add more as needed... */
} ReturnStatus;

/***********************************************************************/
/* Compatability int typedefs                                          */
/***********************************************************************/

typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;

/***********************************************************************/
/* Bitfields for accessing register bits                               */
/***********************************************************************/

/**
 * @brief Union for accessing bits of a 32bit register
 */
typedef union
{
  /** @brief Access double word (32bit) */
  uint32 dword;
  /** @brief Access word (16bit) */
  struct
  {
    uint16 word0;
    uint16 word1;
  } word;
  /** @brief Access byte (8bit) */
  struct
  {
    uint8 byte0;
    uint8 byte1;
    uint8 byte2;
    uint8 byte3;
  } byte;
  /** @brief Access nibble (4bit) */
  struct
  {
    uint8 nib0 : 4;
    uint8 nib1 : 4;
    uint8 nib2 : 4;
    uint8 nib3 : 4;
    uint8 nib4 : 4;
    uint8 nib5 : 4;
    uint8 nib6 : 4;
    uint8 nib7 : 4;
  } nib;
  /** @brief Access bit pair (2bit) */
  struct
  {
    uint8 bp0 : 2;
    uint8 bp1 : 2;
    uint8 bp2 : 2;
    uint8 bp3 : 2;
    uint8 bp4 : 2;
    uint8 bp5 : 2;
    uint8 bp6 : 2;
    uint8 bp7 : 2;
    uint8 bp8 : 2;
    uint8 bp9 : 2;
    uint8 bp10 : 2;
    uint8 bp11 : 2;
    uint8 bp12 : 2;
    uint8 bp13 : 2;
    uint8 bp14 : 2;
    uint8 bp15 : 2;
  } bp;
  /** @brief Access bit */
  struct
  {
    uint8 b0 : 1;
    uint8 b1 : 1;
    uint8 b2 : 1;
    uint8 b3 : 1;
    uint8 b4 : 1;
    uint8 b5 : 1;
    uint8 b6 : 1;
    uint8 b7 : 1;
    uint8 b8 : 1;
    uint8 b9 : 1;
    uint8 b10 : 1;
    uint8 b11 : 1;
    uint8 b12 : 1;
    uint8 b13 : 1;
    uint8 b14 : 1;
    uint8 b15 : 1;
    uint8 b16 : 1;
    uint8 b17 : 1;
    uint8 b18 : 1;
    uint8 b19 : 1;
    uint8 b20 : 1;
    uint8 b21 : 1;
    uint8 b22 : 1;
    uint8 b23 : 1;
    uint8 b24 : 1;
    uint8 b25 : 1;
    uint8 b26 : 1;
    uint8 b27 : 1;
    uint8 b28 : 1;
    uint8 b29 : 1;
    uint8 b30 : 1;
    uint8 b31 : 1;
  } bits;
} bit32;

/**
 * @brief Union for accessing bits of a 16bit register
 */
typedef union
{
  /** @brief Access word (16bit) */
  uint16 word;
  /** @brief Access byte (8bit) */
  struct
  {
    uint8 byte0;
    uint8 byte1;
  } byte;
  /** @brief Access nibble (4bit) */
  struct
  {
    uint8 nib0 : 4;
    uint8 nib1 : 4;
    uint8 nib2 : 4;
    uint8 nib3 : 4;
  } nib;
  /** @brief Access bit pair (2bit) */
  struct
  {
    uint8 bp0 : 2;
    uint8 bp1 : 2;
    uint8 bp2 : 2;
    uint8 bp3 : 2;
    uint8 bp4 : 2;
    uint8 bp5 : 2;
    uint8 bp6 : 2;
    uint8 bp7 : 2;
  } bp;
  /** @brief Access bit */
  struct
  {
    uint8 b0 : 1;
    uint8 b1 : 1;
    uint8 b2 : 1;
    uint8 b3 : 1;
    uint8 b4 : 1;
    uint8 b5 : 1;
    uint8 b6 : 1;
    uint8 b7 : 1;
    uint8 b8 : 1;
    uint8 b9 : 1;
    uint8 b10 : 1;
    uint8 b11 : 1;
    uint8 b12 : 1;
    uint8 b13 : 1;
    uint8 b14 : 1;
    uint8 b15 : 1;
  } bits;
} bit16;

/**
 * @brief Union for accessing bits of a 8bit register
 */
typedef union
{
  /** @brief Access byte (8bit) */
  uint8 byte;
  /** @brief Access nibble (4bit) */
  struct
  {
    uint8 nib0 : 4;
    uint8 nib1 : 4;
  } nib;
  /** @brief Access bit pair (2bit) */
  struct
  {
    uint8 bp0 : 2;
    uint8 bp1 : 2;
    uint8 bp2 : 2;
    uint8 bp3 : 2;
  } bp;
  /** @brief Access bit */
  struct
  {
    uint8 b0 : 1;
    uint8 b1 : 1;
    uint8 b2 : 1;
    uint8 b3 : 1;
    uint8 b4 : 1;
    uint8 b5 : 1;
    uint8 b6 : 1;
    uint8 b7 : 1;
  } bits;
} bit8;


#endif /* INC_GLOBAL_H_ */
