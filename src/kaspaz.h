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
#include "uint256.h"
#include "chain.h"
#include "kaspaz_structs.h"
#include "kaspaz_utils.h"
#include "kaspaz_curve25519.h"

//#include "kaspaz_cJSON.h"
//#include "kaspaz_bitcoind.h"
//#include "kaspaz_interest.h"

// Todo:
// verify: reorgs


//#include "kaspaz_kv.h"
//#include "kaspaz_gateway.h"
//#include "kaspaz_events.h"
//#include "kaspaz_ccdata.h"
#include <cstdint>

const char KOMODO_STATE_FILENAME[] = "kaspazevents";

int32_t kaspaz_parsestatefile(struct kaspaz_state *sp,FILE *fp,char *symbol, const char *dest);

void kaspaz_currentheight_set(int32_t height);

int32_t kaspaz_currentheight();

int32_t kaspaz_parsestatefiledata(struct kaspaz_state *sp,uint8_t *filedata,long *fposp,long datalen,const char *symbol, const char *dest);

void kaspaz_stateupdate(int32_t height,uint8_t notarypubs[][33],uint8_t numnotaries,uint8_t notaryid,
        uint256 txhash,uint32_t *pvals,uint8_t numpvals,int32_t KMDheight,uint32_t KMDtimestamp,
        uint64_t opretvalue,uint8_t *opretbuf,uint16_t opretlen,uint16_t vout,uint256 MoM,int32_t MoMdepth);

int32_t kaspaz_voutupdate(bool fJustCheck,int32_t *isratificationp,int32_t notaryid,
        uint8_t *scriptbuf,int32_t scriptlen,int32_t height,uint256 txhash,int32_t i,
        int32_t j,uint64_t *voutmaskp,int32_t *specialtxp,int32_t *notarizedheightp,
        uint64_t value,int32_t notarized,uint64_t signedmask,uint32_t timestamp);

int32_t kaspaz_connectblock(bool fJustCheck, CBlockIndex *pindex,CBlock& block);
