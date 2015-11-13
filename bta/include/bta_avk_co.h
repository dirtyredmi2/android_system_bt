/******************************************************************************
 *
 *  Copyright (C) 2003-2012 Broadcom Corporation
 *  Copyright (c) 2015, The Linux Foundation. All rights reserved.
 *  Not a Contribution
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

/******************************************************************************
 *
 *  Interface files for Callout functions for A2DP Sink.
 *
 ******************************************************************************/
#ifndef BTA_AVK_CO_H
#define BTA_AVK_CO_H

#include "l2c_api.h"
#include "bta_av_api.h"

/*****************************************************************************
**  Constants and data types
*****************************************************************************/

/* TRUE to use SCMS-T content protection */
#ifndef BTA_AVK_CO_CP_SCMS_T
#define BTA_AVK_CO_CP_SCMS_T     FALSE
#endif

/* the content protection IDs assigned by BT SIG */
#define BTA_AVK_CP_SCMS_T_ID     0x0002
#define BTA_AVK_CP_DTCP_ID       0x0001

#define BTA_AVK_CP_LOSC                  2
#define BTA_AVK_CP_INFO_LEN              3

#define BTA_AVK_CP_SCMS_COPY_MASK        3
#define BTA_AVK_CP_SCMS_COPY_FREE        2
#define BTA_AVK_CP_SCMS_COPY_ONCE        1
#define BTA_AVK_CP_SCMS_COPY_NEVER       0

#define BTA_AVK_CO_DEFAULT_AUDIO_OFFSET      AVDT_MEDIA_OFFSET


/*******************************************************************************
**
** Function         bta_avk_co_audio_init
**
** Description      This callout function is executed by AV when it is
**                  started by calling BTA_AvEnable().  This function can be
**                  used by the phone to initialize audio paths or for other
**                  initialization purposes.
**
**
** Returns          Stream codec and content protection capabilities info.
**
*******************************************************************************/
extern BOOLEAN bta_avk_co_audio_init(UINT8 *p_codec_type, UINT8 *p_codec_info,
                                   UINT8 *p_num_protect, UINT8 *p_protect_info, UINT8 index);

/*******************************************************************************
**
** Function         bta_avk_co_audio_disc_res
**
** Description      This callout function is executed by AV to report the
**                  number of stream end points (SEP) were found during the
**                  AVDT stream discovery process.
**
**
** Returns          void.
**
*******************************************************************************/
extern void bta_avk_co_audio_disc_res(tBTA_AV_HNDL hndl, UINT8 num_seps,
                    UINT8 num_snk, UINT8 num_src, BD_ADDR addr, UINT16 uuid_local);

/*******************************************************************************
**
** Function         bta_av_co_audio_getconfig
**
** Description      This callout function is executed by AV to retrieve the
**                  desired codec and content protection configuration for the
**                  audio stream.
**
**
** Returns          Stream codec and content protection configuration info.
**
*******************************************************************************/
extern UINT8 bta_avk_co_audio_getconfig(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type,
                                         UINT8 *p_codec_info, UINT8 *p_sep_info_idx, UINT8 seid,
                                         UINT8 *p_num_protect, UINT8 *p_protect_info);

/*******************************************************************************
**
** Function         bta_av_co_audio_setconfig
**
** Description      This callout function is executed by AV to set the
**                  codec and content protection configuration of the audio stream.
**
**
** Returns          void
**
*******************************************************************************/
extern void bta_avk_co_audio_setconfig(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type,
                                        UINT8 *p_codec_info, UINT8 seid, BD_ADDR addr,
                                        UINT8 num_protect, UINT8 *p_protect_info,UINT8 t_local_sep, UINT8 avdt_handle);


/*******************************************************************************
**
** Function         bta_avk_co_audio_open
**
** Description      This function is called by AV when the audio stream connection
**                  is opened.
**                  BTA-AV maintains the MTU of A2DP streams.
**                  If this is the 2nd audio stream, mtu is the smaller of the 2
**                  streams.
**
** Returns          void
**
*******************************************************************************/
extern void bta_avk_co_audio_open(tBTA_AV_HNDL hndl,
                                         tBTA_AV_CODEC codec_type, UINT8 *p_codec_info,
                                         UINT16 mtu);

/*******************************************************************************
**
** Function         bta_avk_co_audio_close
**
** Description      This function is called by AV when the audio stream connection
**                  is closed.
**                  BTA-AV maintains the MTU of A2DP streams.
**                  When one stream is closed and no other audio stream is open,
**                  mtu is reported as 0.
**                  Otherwise, the MTU remains open is reported.
**
** Returns          void
**
*******************************************************************************/
extern void bta_avk_co_audio_close(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type,
                                          UINT16 mtu);

/*******************************************************************************
**
** Function         bta_avk_co_audio_start
**
** Description      This function is called by AV when the audio streaming data
**                  transfer is started.
**
**
** Returns          void
**
*******************************************************************************/
extern void bta_avk_co_audio_start(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type,
        UINT8 *p_codec_info, BOOLEAN *p_no_rtp_hdr);

/*******************************************************************************
**
** Function         bta_avk_co_audio_stop
**
** Description      This function is called by AV when the audio streaming data
**                  transfer is stopped.
**
**
** Returns          void
**
*******************************************************************************/
extern void bta_avk_co_audio_stop(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type);

/*******************************************************************************
 **
 ** Function         bta_avk_co_audio_sink_data_path
 **
 ** Description      Dummy Function, Required just because of co fuctions structure definition
 **
 ** Returns          NULL
 **
 *******************************************************************************/
extern void * bta_avk_co_audio_sink_data_path(tBTA_AV_CODEC codec_type,
                                                    UINT32 *p_len, UINT32 *p_timestamp);

/*******************************************************************************
**
** Function         bta_avk_co_audio_delay
**
** Description      Dummy Function, Required just because of co-fuctions structure definition
**
**
** Returns          void
**
*******************************************************************************/
extern void bta_avk_co_audio_delay(tBTA_AV_HNDL hndl, UINT16 delay);

#endif /* BTA_AVK_CO_H */

