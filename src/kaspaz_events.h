/******************************************************************************
 * Copyright © 2014-2019 The SuperNET Developers.                             *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * SuperNET software, including this file may be copied, modified, propagated *
 * or distributed except according to the terms contained in the LICENSE file *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/
#pragma once
#include "kaspaz_defs.h"
#include "kaspaz_structs.h"

void kaspaz_eventadd_notarized(kaspaz_state *sp, const char *symbol,int32_t height, kaspaz::event_notarized& ntz);

void kaspaz_eventadd_pubkeys(kaspaz_state *sp, const char *symbol,int32_t height, kaspaz::event_pubkeys& pk);

void kaspaz_eventadd_pricefeed(kaspaz_state *sp, const char *symbol,int32_t height, kaspaz::event_pricefeed& pf);

void kaspaz_eventadd_opreturn(kaspaz_state *sp, const char *symbol,int32_t height, kaspaz::event_opreturn& opret);

void kaspaz_eventadd_kmdheight(kaspaz_state *sp, const char *symbol,int32_t height, kaspaz::event_kmdheight& kmd_ht);

void kaspaz_event_rewind(kaspaz_state *sp, const char *symbol,int32_t height);

void kaspaz_setkmdheight(kaspaz_state *sp,int32_t kmdheight,uint32_t timestamp);
