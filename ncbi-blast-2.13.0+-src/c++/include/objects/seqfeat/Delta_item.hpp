/* $Id: Delta_item.hpp 492313 2016-02-16 18:52:15Z foleyjp $
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 */

/// @file Delta_item.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'seqfeat.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Delta_item_.hpp


#ifndef OBJECTS_SEQFEAT_DELTA_ITEM_HPP
#define OBJECTS_SEQFEAT_DELTA_ITEM_HPP


#include <objects/seq/IUPACna.hpp>

// generated includes
#include <objects/seqfeat/Delta_item_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_SEQFEAT_EXPORT CDelta_item : public CDelta_item_Base
{
    typedef CDelta_item_Base Tparent;
public:
    // constructor
    CDelta_item(void);
    // destructor
    ~CDelta_item(void);

    void SetDeletion(void);
    void SetDuplication(void);
    void SetInsertion(const CIUPACna& sequence,
                      TSeqPos seq_length=0); 

private:
    // Prohibit copy constructor and assignment operator
    CDelta_item(const CDelta_item& value);
    CDelta_item& operator=(const CDelta_item& value);

};

/////////////////// CDelta_item inline methods

// constructor
inline
CDelta_item::CDelta_item(void)
{
}


/////////////////// end of CDelta_item inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQFEAT_DELTA_ITEM_HPP
/* Original file checksum: lines: 86, chars: 2435, CRC32: be4d21ba */
