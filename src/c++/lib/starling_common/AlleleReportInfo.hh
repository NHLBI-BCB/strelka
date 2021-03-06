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

#include "blt_common/MapqTracker.hh"
#include "blt_util/fastRanksum.hh"
#include "starling_common/IndelKey.hh"

#include <iosfwd>
#include <string>


namespace SimplifiedIndelReportType
{

/// some components of the indel reporting need to reduce all alternate alleles to the following
/// simplified states:
enum index_t
{
    INSERT,
    DELETE,
    SWAP,
    BREAKPOINT,
    OTHER
};

inline
index_t
getRateType(
    const IndelKey& indelKey)
{
    if     (indelKey.isPrimitiveDeletionAllele())
    {
        return DELETE;
    }
    else if (indelKey.isPrimitiveInsertionAllele())
    {
        return INSERT;
    }
    else if (indelKey.type == INDEL::INDEL)
    {
        return SWAP;
    }
    else if (indelKey.is_breakpoint())
    {
        return BREAKPOINT;
    }
    else
    {
        return OTHER;
    }
}
}


/// allele summary information which is shared between all samples:
///
struct AlleleReportInfo
{
    AlleleReportInfo() {}

    bool
    is_repeat_unit() const
    {
        return (! repeat_unit.empty());
    }

    void dump(std::ostream& os) const;

    std::string repeat_unit;
    unsigned repeat_unit_length = 0;
    unsigned ref_repeat_count = 0;
    unsigned indel_repeat_count = 0;
    unsigned ihpol = 0; ///< interrupted homopolymer length

    // not directly reported, but handy to have pre-calculated:
    SimplifiedIndelReportType::index_t it = SimplifiedIndelReportType::OTHER;
};

std::ostream& operator<<(std::ostream& os, const AlleleReportInfo& obj);


/// allele summary information which is specific to each sample:
///
struct AlleleSampleReportInfo
{
    /// TODO STREL-125 sample_report_info is still designed for only one alt allele

    AlleleSampleReportInfo() {}

    unsigned n_confident_ref_reads = 0;
    unsigned n_confident_indel_reads = 0;
    unsigned n_confident_alt_reads = 0;

    // number of lower-quality reads
    unsigned n_other_reads = 0;

    // the depth of the pileup preceding the indel
    unsigned tier1Depth = 0;

    // same as above, but by strand
    unsigned n_confident_ref_reads_fwd = 0;
    unsigned n_confident_indel_reads_fwd = 0;
    unsigned n_confident_alt_reads_fwd = 0;
    unsigned n_other_reads_fwd = 0;
    unsigned n_confident_ref_reads_rev = 0;
    unsigned n_confident_indel_reads_rev = 0;
    unsigned n_confident_alt_reads_rev = 0;
    unsigned n_other_reads_rev = 0;

    MapqTracker mapqTracker;

    fastRanksum readpos_ranksum;

    unsigned total_confident_reads() const
    {
        return n_confident_alt_reads + n_confident_indel_reads + n_confident_ref_reads;
    }

    void dump(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const AlleleSampleReportInfo& obj);
