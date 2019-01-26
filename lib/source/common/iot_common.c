/*
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* Build using a config header, if provided. */
#ifdef IOT_CONFIG_FILE
    #include IOT_CONFIG_FILE
#endif

/* Common include. */
#include "iot_common.h"

/* Static memory include (if dynamic memory allocation is disabled). */
#if IOT_STATIC_MEMORY_ONLY == 1
    #include "private/iot_static_memory.h"
#endif

/* Configure logs for the functions in this file. */
#ifdef AWS_IOT_LOG_LEVEL_GLOBAL
    #define _LIBRARY_LOG_LEVEL    AWS_IOT_LOG_LEVEL_GLOBAL
#else
    #define _LIBRARY_LOG_LEVEL    AWS_IOT_LOG_NONE
#endif

#define _LIBRARY_LOG_NAME         ( "COMMON" )
#include "aws_iot_logging_setup.h"

/*-----------------------------------------------------------*/

bool IotCommon_Init( void )
{
    bool status = true;

    /* Initialize static memory if dynamic memory allocation is disabled. */
    #if IOT_STATIC_MEMORY_ONLY == 1
        status = IotStaticMemory_Init();

        if( status == false )
        {
            AwsIotLogError( "Failed to initialize static memory." );
        }
    #endif

    if( status == true )
    {
        AwsIotLogInfo( "Common libraries successfully initialized." );
    }

    return status;
}

/*-----------------------------------------------------------*/

void IotCommon_Cleanup( void )
{
    /* Cleanup static memory if dynamic memory allocation is disabled. */
    #if IOT_STATIC_MEMORY_ONLY == 1
        IotStaticMemory_Cleanup();
    #endif

    AwsIotLogInfo( "Common libraries cleanup done." );
}

/*-----------------------------------------------------------*/
