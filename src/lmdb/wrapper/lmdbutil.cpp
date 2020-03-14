#include "lmdb/wrapper/lmdbutil.h"
#include "dbwrapper.h"
#include "util.h"

#include "lmdb/liblmdb/lmdb.h"

#include <sstream>

namespace lmdb {

void HandleError(const int status, const char* call, const char *file,
        const int line, const char* func)
{
    if (status == MDB_SUCCESS)
        return;

    std::stringstream err;
    err << mdb_strerror(status) << " (code: " << status << ")."
        << " Call: '" << call
        << "' in function '" << func << "'"
        << " file " << file << ":" << line;
    LogPrintf("lmdb error: %s\n", err.str());
    throw dbwrapper_error(err.str());
}

} // ns lmdb
