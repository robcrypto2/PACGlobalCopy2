#ifndef BITCOIN_LMDB_LMDBUTIL
#define BITCOIN_LMDB_LMDBUTIL
#include "config/pacglobal-config.h"

namespace lmdb {
void HandleError(const int status, const char* call, const char *file,
        const int line, const char* func);
} // ns lmdb

#define LMDB_RC_CHECK(x) lmdb::HandleError(x, #x, __FILE__, __LINE__, __func__)

#endif // BITCOIN_LMDB_LMDBUTIL
