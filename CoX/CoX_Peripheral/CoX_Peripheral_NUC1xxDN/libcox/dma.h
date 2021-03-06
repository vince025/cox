#ifndef _NUC1XX_DMA_H_
#define _NUC1XX_DMA_H_

//*****************************************************************************
//
//! \addtogroup NUC1xx_PDMA
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup NUC1xx_PDMA_Channel_IDs NUC1xx PDMA Channel IDs
//! \brief Defines for the NUC1xx PDMA Channel IDs
//! @{
//
//*****************************************************************************

#define DMA_CHANNEL_COUNT       9
#define DMA_CHANNEL_NOT_EXIST   0xFFFFFFFF

#define DMA_CHANNEL_0           0
#define DMA_CHANNEL_1           1
#define DMA_CHANNEL_2           2
#define DMA_CHANNEL_3           3
#define DMA_CHANNEL_4           4
#define DMA_CHANNEL_5           5
#define DMA_CHANNEL_6           6
#define DMA_CHANNEL_7           7
#define DMA_CHANNEL_8           8

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup NUC1xx_PDMA_Event_Flags  NUC1xx PDMA Event Flags
//! \brief Defines for the NUC1xx PDMA Event Flags
//! @{
//
//*****************************************************************************

//
//! Transfer complete.
//
#define DMA_EVENT_TC            0x00000002

//
//! Error occurs when DMA channel transfer.
//
#define DMA_EVENT_ERROR         0x00000001

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup NUC1xx_PDMA_Channel_Control_Config NUC1xx PDMA Channel Control
//! Configure
//! \brief Defines for the NUC1xx PDMA Channel Control Configure
//! @{
//
//*****************************************************************************

#define DMA_DST_DIR_INC         0x00000000
#define DMA_DST_DIR_FIXED       0x00000080

#define DMA_SRC_DIR_INC         0x00000000
#define DMA_SRC_DIR_FIXED       0x00000020

#define DMA_WIDTH_8BIT          0x00000000
#define DMA_WIDTH_16BIT         0x00080000
#define DMA_WIDTH_32BIT         0x00100000

#define DMA_MODE_MTOM           0x00000000
#define DMA_MODE_MTOP           0x00000008
#define DMA_MODE_PTOM           0x00000004

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup NUC1xx_PDMA_Request_Connections NUC1xx PDMA Request Connections
//! \brief Defines for the NUC1xx PDMA Request Connections
//! @{
//
//*****************************************************************************

#define DMA_REQUEST_NOT_EXIST   0x00000000
#define DMA_REQUEST_MEM         0x00000001

#define DMA_REQUEST_UART0_RX    0x1000000F
#define DMA_REQUEST_UART0_TX    0x1004010F

#define DMA_REQUEST_UART1_RX    0x1008000F
#define DMA_REQUEST_UART1_TX    0x100C010F

#define DMA_REQUEST_SPI0_RX     0x0000000F
#define DMA_REQUEST_SPI0_TX     0x0004010F

#define DMA_REQUEST_SPI1_RX     0x0008000F
#define DMA_REQUEST_SPI1_TX     0x000C010F

#define DMA_REQUEST_SPI2_RX     0x0010000F
#define DMA_REQUEST_SPI2_TX     0x0014010F

#define DMA_REQUEST_SPI3_RX     0x0018000F
#define DMA_REQUEST_SPI3_TX     0x001C010F

#define DMA_REQUEST_IIS0_RX     0x2000000F
#define DMA_REQUEST_IIS0_TX     0x2004010F

#define DMA_REQUEST_ADC_RX      0x1018000F

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup NUC1xx_PDMA_Exported_APIs NUC1xx PDMA APIs
//! \brief NUC1xx PDMA API Reference.
//! @{
//
//*****************************************************************************

extern void PDMAEnable(unsigned long ulChannelID);
extern void PDMADisable(unsigned long ulChannelID);
extern void PDMAChannelSoftwareReset(unsigned long ulChannelID);
extern xtBoolean PDMAChannelIsBusy(unsigned long ulChannelID);
extern void PDMAChannelIntDisable(unsigned long ulChannelID,
                                 unsigned long ulIntFlags);
extern void PDMAChannelIntEnable(unsigned long ulChannelID,
                                unsigned long ulIntFlags);
extern unsigned long PDMAChannelDynamicAssign(unsigned long ulDMASrcRequest,
                                            unsigned long ulDMADestRequest);
extern xtBoolean PDMAChannelAssignmentGet(unsigned long ulChannelID);
extern void PDMAChannelDeAssign(unsigned long ulChannelID);

extern void PDMAChannelAttributeSet(unsigned long ulChannelID,
                                unsigned long ulAttr);
extern unsigned long PDMAChannelAttributeGet(unsigned long ulChannelID);

extern void PDMAChannelControlSet(unsigned long ulChannelID,
                                unsigned long ulControl);

extern void PDMAChannelTransferSet(unsigned long ulChannelID,
                                   void *pvSrcAddr,
                                   void *pvDstAddr,
                                   unsigned long ulTransferSize);

extern void PDMAChannelIntCallbackInit(unsigned long ulChannelID,
                                xtEventCallback pfnCallback);
extern xtEventCallback PDMAChannelIntCallbackGet(unsigned long ulChannelID);

extern xtBoolean PDMAChannelIntFlagGet(unsigned long ulChannelID,
                                       unsigned long ulIntFlags);
extern void PDMAChannelIntFlagClear(unsigned long ulChannelID,
                                    unsigned long ulIntFlags);

extern unsigned long PDMACurrentSourceAddrGet(unsigned long ulChannelID);
extern unsigned long PDMACurrentDestAddrGet(unsigned long ulChannelID);
extern unsigned long PDMARemainTransferCountGet(unsigned long ulChannelID);
extern unsigned long PDMASharedBufferDataGet(unsigned long ulChannelID);
extern unsigned long PDMAInternalBufPointerGet(unsigned long ulChannelID);

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

#endif
