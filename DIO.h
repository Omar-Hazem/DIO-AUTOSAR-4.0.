 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.h
 *
 * Description: Header file for Dio Module.
 *
 * Author: Omar Hazem
 ******************************************************************************/

#ifndef DIO_H
#define DIO_H

/* Id for the company in the AUTOSAR
 * for example Omar Hazem's ID = 1000 :) */
#define DIO_VENDOR_ID    (1000U)

/* Dio Module Id */
#define DIO_MODULE_ID    (120U)

/* Dio Instance Id */
#define DIO_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define DIO_SW_MAJOR_VERSION           (1U)
#define DIO_SW_MINOR_VERSION           (0U)
#define DIO_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_AR_RELEASE_MINOR_VERSION   (0U)
#define DIO_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Dio Status
 */
#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"
#include "STM32f446xx.h"
/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Dio Pre-Compile Configuration Header file */
#include "DIO_Cfg.h"

/* AUTOSAR Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_CFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_CFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (uint8)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (uint8)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (uint8)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8)0x05

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       (uint8)0x12

/* Service ID for DIO Init Channel */
#define DIO_INIT_SID                   (uint8)0x10

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (uint8)0x11

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8)0x0A

/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             (uint8)0x10

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8)0x14

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP      (uint8)0x1F

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define DIO_E_PARAM_POINTER             (uint8)0x20

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document.
 */
#define DIO_E_UNINIT                   (uint8)0xF0
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
#define GPIO_RCC_CLK_ENABLE()					       (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_CRCEN_Pos))
#define GPIO_RCC_CLK_DISABLE()				       (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_CRCEN_Pos))

#define GPIO_RCC_CLK_GPIOA_ENABLE()	 	       (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOAEN_Pos))
#define GPIO_RCC_CLK_GPIOA_DISABLE()         (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOAEN_Pos))

#define GPIO_RCC_CLK_GPIOB_ENABLE()		       (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOBEN_Pos))
#define GPIO_RCC_CLK_GPIOB_DISABLE()	       (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOBEN_Pos))

#define GPIO_RCC_CLK_GPIOC_ENABLE()		       (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOCEN_Pos))
#define GPIO_RCC_CLK_GPIOC_DISABLE()	       (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOCEN_Pos))

#define GPIO_RCC_CLK_GPIOD_ENABLE()		       (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIODEN_Pos))
#define GPIO_RCC_CLK_GPIOD_DISABLE()	       (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIODEN_Pos))

#define GPIO_RCC_CLK_GPIOE_ENABLE()		       (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOEEN_Pos))
#define GPIO_RCC_CLK_GPIOE_DISABLE()	       (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOEEN_Pos))

#define GPIO_RCC_CLK_GPIOF_ENABLE()		       (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOFEN_Pos))
#define GPIO_RCC_CLK_GPIOF_DISABLE()	       (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOFEN_Pos))

#define GPIO_RCC_CLK_GPIOG_ENABLE()		       (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOGEN_Pos))
#define GPIO_RCC_CLK_GPIOG_DISABLE()	       (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOGEN_Pos))

#define GPIO_RCC_CLK_GPIOH_ENABLE()		       (RCC->AHB1ENR |= (1<<RCC_AHB1ENR_GPIOHEN_Pos))
#define GPIO_RCC_CLK_GPIOH_DISABLE()	       (RCC->AHB1ENR &= ~(1<<RCC_AHB1ENR_GPIOHEN_Pos))

/* Pin type */
typedef uint32 Dio_ChannelType;

/* port type */
typedef uint32 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint32 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint32 Dio_PortLevelType;

/*******************************************************************************
 *                              Enumerations                                        *
 *******************************************************************************/

typedef enum
	{
		GPIO_INPUT_MODE, GPIO_GENERAL_PURPOSE_OP_MODE, GPIO_ALTERNATE_FN, ANALOG_MODE
	}GPIO_ConfigPinsMode;

	typedef enum
	{
		GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_OPEN_DRAIN
	}GPIO_ConfigOutputType;

	typedef enum
	{
		GPIO_LOW_SPEED, GPIO_MEDIUM_SPEED, GPIO_FAST_SPEED, GPIO_HIGH_SPEED
	}GPIO_ConfigSpeedMode;

	typedef enum
	{
		GPIO_NO_PULL_UP_DOWN, GPIO_PULL_UP,GPIO_PULL_DOWN
	}GPIO_ConfigPullUpDown;

	typedef enum
	{
		AF0,AF1,AF2,AF3,AF4,AF5,AF6,AF7,AF8,AF9,AF10,AF11,AF12,AF13,AF14,AF15
	}GPIO_AlternatFunction;

/*******************************************************************************
 *                              Structs                                        *
 *******************************************************************************/
typedef struct
{
GPIO_TypeDef * GPIOx;
Dio_ChannelType Pin;
Dio_PortType Port_Num;
}Dio_Config;
	
	

typedef struct
{
Dio_Config channel[DIO_CONFIGURED_CHANNLES];
}Dio_ConfigType;




/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for DIO read Channel API */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/* Function for DIO write Channel API */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/* Function for DIO read Port API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Function for DIO write Port API */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/* Function for DIO Initialization API */
void Dio_Init(const Dio_ConfigType * ConfigPtr);

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for DIO flip channel API */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif

/* Function for DIO Get Version Info API */
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const Dio_ConfigType Dio_Configuration;

#endif /* DIO_H */
