#ifndef BITCOIN_LMDBWRAPPER_H
#define BITCOIN_LMDBWRAPPER_H

#include "config/pacglobal-config.h"

#include "dbwrapper.h"
#include "lmdb/wrapper/lmdbwrapper.h"
#include "lmdb/liblmdb/lmdb.h"

#include <memory>
#include <cstddef>
#include <stdexcept>

class LMDBWrapper;
namespace boost { namespace filesystem { class path; } }

namespace lmdb {

//  std::unique_ptr<CDBWrapper> CreateLMDB(
//          const boost::filesystem::path& path,
//          bool fMemory = false, bool fWipe = false, bool fSafeMode = true);

} // ns lmdb

#endif
