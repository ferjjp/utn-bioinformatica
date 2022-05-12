/* $Id: Seq_table.cpp 457991 2015-01-29 19:26:03Z vasilche $
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
 * Author:  .......
 *
 * File Description:
 *   .......
 *
 * Remark:
 *   This code was originally generated by application DATATOOL
 *   using the following specifications:
 *   'seqtable.asn'.
 */

// standard includes
#include <ncbi_pch.hpp>

// generated includes
#include <objects/seqtable/Seq_table.hpp>
#include <objects/seqtable/SeqTable_column.hpp>
#include <objects/seqtable/SeqTable_column_info.hpp>
#include <objects/seqtable/seq_table_exception.hpp>
#include <serial/enumvalues.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

// destructor
CSeq_table::~CSeq_table(void)
{
}


string CSeq_table::GetIdName(TColumnId column_id)
{
    return CSeqTable_column_info::ENUM_METHOD_NAME(EField_id)()->FindName(column_id, true);
}


const CSeqTable_column& CSeq_table::GetColumn(CTempString column_name) const
{
    ITERATE ( TColumns, it, GetColumns() ) {
        const CSeqTable_column& column = **it;
        const CSeqTable_column_info& info = column.GetHeader();
        if ( info.IsSetField_name() && column_name == info.GetField_name() ) {
            return column;
        }
    }
    NCBI_THROW(CSeqTableException, eColumnNotFound,
               "Column not found: "+string(column_name));
}


const CSeqTable_column& CSeq_table::GetColumn(TColumnId column_id) const
{
    ITERATE ( TColumns, it, GetColumns() ) {
        const CSeqTable_column& column = **it;
        const CSeqTable_column_info& info = column.GetHeader();
        if ( info.IsSetField_id() && column_id == info.GetField_id() ) {
            return column;
        }
    }
    NCBI_THROW(CSeqTableException, eColumnNotFound,
               "Column not found: "+GetIdName(column_id));
}


const CSeqTable_column& CSeq_table::GetColumn(TColumnId column_id,
                                              CTempString column_name) const
{
    ITERATE ( TColumns, it, GetColumns() ) {
        const CSeqTable_column& column = **it;
        const CSeqTable_column_info& info = column.GetHeader();
        if ( info.IsSetField_id() && column_id == info.GetField_id() ) {
            return column;
        }
        if ( info.IsSetField_name() && column_name == info.GetField_name() ) {
            return column;
        }
    }
    NCBI_THROW(CSeqTableException, eColumnNotFound,
               "Column not found: "+string(column_name)+"/"+GetIdName(column_id));
}


const char* CSeqTableException::GetErrCodeString(void) const
{
    switch ( GetErrCode() ) {
    case eColumnNotFound:       return "eColumnNotFound";
    case eRowNotFound:          return "eRowNotFound";
    case eIncompatibleValueType:return "eIncompatibleValueType";
    case eOtherError:           return "eOtherError";
    default:                    return CException::GetErrCodeString();
    }
}

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
