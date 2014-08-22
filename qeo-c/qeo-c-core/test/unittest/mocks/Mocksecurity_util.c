/*
 * Copyright (c) 2014 - Qeo LLC
 *
 * The source code form of this Qeo Open Source Project component is subject
 * to the terms of the Clear BSD license.
 *
 * You can redistribute it and/or modify it under the terms of the Clear BSD
 * License (http://directory.fsf.org/wiki/License:ClearBSD). See LICENSE file
 * for more details.
 *
 * The Qeo Open Source Project also includes third party Open Source Software.
 * See LICENSE file for more details.
 */

/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#define NO_TEST_ASSERT_EQUAL_MEMORY_MESSAGE
#include "unity.h"
#include "cmock.h"
#include "Mocksecurity_util.h"

typedef struct _CMOCK_security_util_configure_ssl_ctx_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  SSL_CTX* Expected_ssl_ctx;

} CMOCK_security_util_configure_ssl_ctx_CALL_INSTANCE;

typedef struct _CMOCK_dump_openssl_error_stack_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char* Expected_msg;

} CMOCK_dump_openssl_error_stack_CALL_INSTANCE;

static struct Mocksecurity_utilInstance
{
  int security_util_configure_ssl_ctx_IgnoreBool;
  CMOCK_security_util_configure_ssl_ctx_CALLBACK security_util_configure_ssl_ctx_CallbackFunctionPointer;
  int security_util_configure_ssl_ctx_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE security_util_configure_ssl_ctx_CallInstance;
  int dump_openssl_error_stack_IgnoreBool;
  CMOCK_dump_openssl_error_stack_CALLBACK dump_openssl_error_stack_CallbackFunctionPointer;
  int dump_openssl_error_stack_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE dump_openssl_error_stack_CallInstance;
} Mock;

extern jmp_buf AbortFrame;

void Mocksecurity_util_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.security_util_configure_ssl_ctx_IgnoreBool)
    Mock.security_util_configure_ssl_ctx_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.security_util_configure_ssl_ctx_CallInstance, cmock_line, "Function 'security_util_configure_ssl_ctx' called less times than expected.");
  if (Mock.security_util_configure_ssl_ctx_CallbackFunctionPointer != NULL)
    Mock.security_util_configure_ssl_ctx_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.dump_openssl_error_stack_IgnoreBool)
    Mock.dump_openssl_error_stack_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.dump_openssl_error_stack_CallInstance, cmock_line, "Function 'dump_openssl_error_stack' called less times than expected.");
  if (Mock.dump_openssl_error_stack_CallbackFunctionPointer != NULL)
    Mock.dump_openssl_error_stack_CallInstance = CMOCK_GUTS_NONE;
}

void Mocksecurity_util_Init(void)
{
  Mocksecurity_util_Destroy();
}

void Mocksecurity_util_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.security_util_configure_ssl_ctx_CallbackFunctionPointer = NULL;
  Mock.security_util_configure_ssl_ctx_CallbackCalls = 0;
  Mock.dump_openssl_error_stack_CallbackFunctionPointer = NULL;
  Mock.dump_openssl_error_stack_CallbackCalls = 0;
}

void security_util_configure_ssl_ctx(SSL_CTX* ssl_ctx)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_security_util_configure_ssl_ctx_CALL_INSTANCE* cmock_call_instance = (CMOCK_security_util_configure_ssl_ctx_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.security_util_configure_ssl_ctx_CallInstance);
  Mock.security_util_configure_ssl_ctx_CallInstance = CMock_Guts_MemNext(Mock.security_util_configure_ssl_ctx_CallInstance);
  if (Mock.security_util_configure_ssl_ctx_IgnoreBool)
  {
    return;
  }
  if (Mock.security_util_configure_ssl_ctx_CallbackFunctionPointer != NULL)
  {
    Mock.security_util_configure_ssl_ctx_CallbackFunctionPointer(ssl_ctx, Mock.security_util_configure_ssl_ctx_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'security_util_configure_ssl_ctx' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_ssl_ctx), (void*)(ssl_ctx), sizeof(SSL_CTX), cmock_line, "Function 'security_util_configure_ssl_ctx' called with unexpected value for argument 'ssl_ctx'.");
}

void CMockExpectParameters_security_util_configure_ssl_ctx(CMOCK_security_util_configure_ssl_ctx_CALL_INSTANCE* cmock_call_instance, SSL_CTX* ssl_ctx)
{
  cmock_call_instance->Expected_ssl_ctx = ssl_ctx;
}

void security_util_configure_ssl_ctx_CMockIgnore(UNITY_LINE_TYPE cmock_line)
{
  Mock.security_util_configure_ssl_ctx_IgnoreBool = (int)1;
}

void security_util_configure_ssl_ctx_CMockExpect(UNITY_LINE_TYPE cmock_line, SSL_CTX* ssl_ctx)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_security_util_configure_ssl_ctx_CALL_INSTANCE));
  CMOCK_security_util_configure_ssl_ctx_CALL_INSTANCE* cmock_call_instance = (CMOCK_security_util_configure_ssl_ctx_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.security_util_configure_ssl_ctx_CallInstance = CMock_Guts_MemChain(Mock.security_util_configure_ssl_ctx_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_security_util_configure_ssl_ctx(cmock_call_instance, ssl_ctx);
}

void security_util_configure_ssl_ctx_StubWithCallback(CMOCK_security_util_configure_ssl_ctx_CALLBACK Callback)
{
  Mock.security_util_configure_ssl_ctx_CallbackFunctionPointer = Callback;
}

void dump_openssl_error_stack(const char* msg)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_dump_openssl_error_stack_CALL_INSTANCE* cmock_call_instance = (CMOCK_dump_openssl_error_stack_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.dump_openssl_error_stack_CallInstance);
  Mock.dump_openssl_error_stack_CallInstance = CMock_Guts_MemNext(Mock.dump_openssl_error_stack_CallInstance);
  if (Mock.dump_openssl_error_stack_IgnoreBool)
  {
    return;
  }
  if (Mock.dump_openssl_error_stack_CallbackFunctionPointer != NULL)
  {
    Mock.dump_openssl_error_stack_CallbackFunctionPointer(msg, Mock.dump_openssl_error_stack_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'dump_openssl_error_stack' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  UNITY_TEST_ASSERT_EQUAL_STRING(cmock_call_instance->Expected_msg, msg, cmock_line, "Function 'dump_openssl_error_stack' called with unexpected value for argument 'msg'.");
}

void CMockExpectParameters_dump_openssl_error_stack(CMOCK_dump_openssl_error_stack_CALL_INSTANCE* cmock_call_instance, const char* msg)
{
  cmock_call_instance->Expected_msg = (char*)msg;
}

void dump_openssl_error_stack_CMockIgnore(UNITY_LINE_TYPE cmock_line)
{
  Mock.dump_openssl_error_stack_IgnoreBool = (int)1;
}

void dump_openssl_error_stack_CMockExpect(UNITY_LINE_TYPE cmock_line, const char* msg)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_dump_openssl_error_stack_CALL_INSTANCE));
  CMOCK_dump_openssl_error_stack_CALL_INSTANCE* cmock_call_instance = (CMOCK_dump_openssl_error_stack_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.dump_openssl_error_stack_CallInstance = CMock_Guts_MemChain(Mock.dump_openssl_error_stack_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_dump_openssl_error_stack(cmock_call_instance, msg);
}

void dump_openssl_error_stack_StubWithCallback(CMOCK_dump_openssl_error_stack_CALLBACK Callback)
{
  Mock.dump_openssl_error_stack_CallbackFunctionPointer = Callback;
}
