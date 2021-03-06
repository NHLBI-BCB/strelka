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

#pragma once

#include "SequenceErrorCountsOptions.hh"
#include "starling_common/starling_base_option_parser.hh"


po::options_description
getSequenceErrorCountsOptionsParser(SequenceErrorCountsOptions& opt);


// validate options and process any required quick consistency
// adjustments
//
void
finalizeSequenceErrorCountsOptions(
    const prog_info& pinfo,
    const po::variables_map& vm,
    SequenceErrorCountsOptions& opt);

