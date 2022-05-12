/*  $Id: hash_map.hpp 556955 2018-02-07 14:11:31Z ivanov $
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
 * Author: Aleksey Grichenko
 *
 * File Description:
 *   Wrapper for STLport hash_map
 *
 */

#ifndef HASH_MAP__HPP
#define HASH_MAP__HPP

#include <ncbiconf.h>

#if !defined(NCBI_OS_LINUX)
#  error "HASH_SET/MAP are deprecated. Please try using UNORDERED_SET/MAP instead!"
#endif

#include <corelib/hash_impl/stlp_defs.hpp>
#include <corelib/hash_impl/_hash_map.h>

#endif /* HASH_MAP__HPP */
