/*===========================================================================
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

#include "jni_ReadGroupIteratorItf.h"
#include "jni_ErrorMsg.hpp"

#include <ngs/itf/ReadGroupItf.hpp>

using namespace ngs;

static
ReadGroupItf * Self ( size_t jself )
{
    if ( jself == 0 )
        throw ErrorMsg ( "NULL self parameter" );

    return ( ReadGroupItf* ) jself;
}

/*
 * Class:     ngs_itf_ReadGroupIteratorItf
 * Method:    NextReadGroup
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_ngs_itf_ReadGroupIteratorItf_NextReadGroup
    ( JNIEnv * jenv, jobject jthis, jlong jself )
{
    try
    {
        return ( jboolean ) Self ( jself ) -> nextReadGroup ();
    }
    catch ( ErrorMsg & x )
    {
        ErrorMsgThrow ( jenv, xt_error_msg, x . what () );
    }
    catch ( std :: exception & x )
    {
        ErrorMsgThrow ( jenv, xt_runtime, x . what () );
    }
    catch ( ... )
    {
        JNI_INTERNAL_ERROR ( jenv, "%s", __func__ );
    }

    return false;
}
