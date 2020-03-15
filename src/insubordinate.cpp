// Copyright (c) 2020 barrystyle / pacglobal
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "masternode/activemasternode.h"
#include "masternode/masternode-meta.h"
#include "masternode/masternode-sync.h"
#include "masternode/masternode-utils.h"
#include "util.h"
#include "timedata.h"
#include "validation.h"

int mnCacheTime = 0;
std::map<COutPoint, int> mnCache;

void populateDmnCache()
{
    int nCurrentTime = GetAdjustedTime();
    if (!IsInitialBlockDownload()) return;
    if (nCurrentTime - mnCacheTime < 150) return;

    mnCache.clear();
    int nMnCount = 0;
    auto mnList = deterministicMNManager->GetListAtChainTip();
    mnList.ForEachMN(false, [&](const CDeterministicMNCPtr& dmn) {
        auto mnOutpoint = dmn->collateralOutpoint;
        auto registeredHeight = dmn->pdmnState->nRegisteredHeight;
        mnCache.insert(std::make_pair(mnOutpoint,registeredHeight));
        nMnCount++;
    });

    mnCacheTime = nCurrentTime;
    LogPrintf("%s - Populated mnCacheRegister with %d dmn entries\n", __func__, nMnCount);
}
