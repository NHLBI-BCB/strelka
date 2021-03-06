// -*- mode: c++; indent-tabs-mode: nil; -*-
//
// Strelka - Small Variant Caller
// Copyright (c) 2009-2016 Illumina, Inc.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//

///
/// \author Chris Saunders
///

#include "pedicure_shared.hh"
#include "blt_util/blt_exception.hh"
#include "blt_util/chrom_depth_map.hh"

#include <cassert>

#include <sstream>


pedicure_deriv_options::
pedicure_deriv_options(const pedicure_options& opt)
    : base_t(opt)
{
    if (opt.dfilter.is_depth_filter())
    {
        parse_chrom_depth(opt.dfilter.chrom_depth_file, dfilter.chrom_depth);
    }
}

/// dtor required to be in the cpp so that unique ptr can access complete data type
pedicure_deriv_options::
~pedicure_deriv_options() {}
