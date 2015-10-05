/*
* Configuration of module: CanIf (CanIf_Cfg.c)
*
* Created by:              
* Copyright:               
*
* Configured for (MCU):    HCS12
*
* Module vendor:           ArcCore
* Generator version:       2.0.6
*
* Generated by Arctic Studio (http://arccore.com) 
*/


 
#include "CanIf.h"
#if defined(USE_CANTP)
#include "CanTp.h"
#include "CanTp_Cbk.h"
#endif
#if defined(USE_J1939TP)
#include "J1939Tp.h"
#include "J1939Tp_Cbk.h"
#endif
#if defined(USE_PDUR)
#include "PduR.h"
#endif
#if defined(USE_CANNM)
#include "CanNm_Cbk.h"
#endif
#include <stdlib.h>


// Imported structs from Can_Lcfg.c
extern const Can_ControllerConfigType CanControllerConfigData[];
extern const Can_ConfigSetType CanConfigSetData;




// Contains the mapping from CanIf-specific Channels to Can Controllers
const CanControllerIdType CanIf_Arc_ChannelToControllerMap[CANIF_CHANNEL_CNT] = {
	CAN_CTRL_0, // Channel0
};

const uint8 CanIf_Arc_ChannelDefaultConfIndex[CANIF_CHANNEL_CNT] = {
	CANIF_Channel0_CONFIG_0,
};

// Container that gets slamed into CanIf_InitController()
// Inits ALL controllers
// Multiplicity 1..*
const CanIf_ControllerConfigType CanIfControllerConfig[] = {
	// This is the ConfigurationIndex in CanIf_InitController()
	
	
	{ 
		.WakeupSupport = CANIF_WAKEUP_SUPPORT_NO_WAKEUP,
		.CanIfControllerIdRef = CANIF_Channel0,
		.CanIfDriverNameRef = "FLEXCAN",  // Not used
		.CanIfInitControllerRef = &CanControllerConfigData[0],
	},
	
};

// Function callbacks for higher layers
const CanIf_DispatchConfigType CanIfDispatchConfig =
{
  .CanIfBusOffNotification = NULL,
  .CanIfWakeUpNotification = NULL,        // Not used
  .CanIfWakeupValidNotification = NULL,   // Not used
  .CanIfErrorNotificaton = NULL,
};


// Data for init configuration CanIfInitConfiguration

		

const CanIf_HthConfigType CanIfHthConfigData_HardwareObject[] =
{
		
  { 
    .CanIfHthType = CAN_ARC_HANDLE_TYPE_BASIC,
    .CanIfCanControllerIdRef = CANIF_Channel0,
    .CanIfHthIdSymRef = TxBox,
    .CanIf_Arc_EOL = 1,
  },
};

const CanIf_HrhConfigType CanIfHrhConfigData_HardwareObject[] =
{
		
  {
    .CanIfHrhType = CAN_ARC_HANDLE_TYPE_BASIC,
    .CanIfSoftwareFilterHrh = TRUE,
    .CanIfCanControllerHrhIdRef = CANIF_Channel0,
    .CanIfHrhIdSymRef = RxBox,
    .CanIf_Arc_EOL = 1,
  },
};


const CanIf_InitHohConfigType CanIfHohConfigData[] = { 
		
	{
		.CanConfigSet = &CanConfigSetData,
		.CanIfHrhConfig = CanIfHrhConfigData_HardwareObject,
	    .CanIfHthConfig = CanIfHthConfigData_HardwareObject,
    	.CanIf_Arc_EOL = 1,
	},
};
	  
const CanIf_TxPduConfigType CanIfTxPduConfigData[] = {	
  {
    .CanIfTxPduId = PDUR_REVERSE_PDU_ID_FreqInd,
    .CanIfCanTxPduIdCanId = 258,
    .CanIfCanTxPduIdDlc = 8,
    .CanIfCanTxPduType = CANIF_PDU_TYPE_STATIC,
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
    .CanIfReadTxPduNotifyStatus = false, 
#endif
    .CanIfTxPduIdCanIdType = CANIF_CAN_ID_TYPE_11,
    .CanIfUserTxConfirmation = PduR_CanIfTxConfirmation,
    .CanIfCanTxPduHthRef = &CanIfHthConfigData_HardwareObject[0],
    .PduIdRef = NULL,
  },  
};

const CanIf_RxPduConfigType CanIfRxPduConfigData[] = {		
  {
    .CanIfCanRxPduId = PDUR_PDU_ID_FreqReq,
    .CanIfCanRxPduCanId = 256,
    .CanIfCanRxPduDlc = 8,
#if ( CANIF_CANPDUID_READDATA_API == STD_ON )    
    .CanIfReadRxPduData = false,
#endif    
#if ( CANIF_READTXPDU_NOTIFY_STATUS_API == STD_ON )
    .CanIfReadRxPduNotifyStatus = false, 
#endif
	.CanIfRxUserType = CANIF_USER_TYPE_CAN_PDUR,
    .CanIfCanRxPduHrhRef = &CanIfHrhConfigData_HardwareObject[0],
    .CanIfRxPduIdCanIdType = CANIF_CAN_ID_TYPE_11,
    .CanIfUserRxIndication = NULL,
    .CanIfSoftwareFilterType = CANIF_SOFTFILTER_TYPE_MASK,
    .CanIfCanRxPduCanIdMask = 0xFFF,
    .PduIdRef = NULL,
  },  
};

// This container contains the init parameters of the CAN
// Multiplicity 1..*
const CanIf_InitConfigType CanIfInitConfig =
{
  .CanIfConfigSet = 0, // Not used  
  .CanIfNumberOfCanRxPduIds = 1,
  .CanIfNumberOfCanTXPduIds = 1,
  .CanIfNumberOfDynamicCanTXPduIds = 0, // Not used

  // Containers
  .CanIfHohConfigPtr = CanIfHohConfigData,
  .CanIfRxPduConfigPtr = CanIfRxPduConfigData,
  .CanIfTxPduConfigPtr = CanIfTxPduConfigData,
};

	// This container includes all necessary configuration sub-containers
// according the CAN Interface configuration structure.
CanIf_ConfigType CanIf_Config =
{
  .ControllerConfig = CanIfControllerConfig,
  .DispatchConfig = &CanIfDispatchConfig,
  .InitConfig = &CanIfInitConfig,
  .TransceiverConfig = NULL, // Not used
  .Arc_ChannelToControllerMap = CanIf_Arc_ChannelToControllerMap,  
  .Arc_ChannelDefaultConfIndex = CanIf_Arc_ChannelDefaultConfIndex,
};

