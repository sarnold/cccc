// cccc_tpl.cc

// all explicit template instantiations for the project are collected here

// the assumption is that this file will be stable, so the expensive
// recompilation of the templates will be infrequent

#include "cccc_itm.h"
#include "cccc_tbl.h"
#include "cccc_db.h"
#include "cccc_htm.h"

template class std::map<string,Source_Anchor>;
