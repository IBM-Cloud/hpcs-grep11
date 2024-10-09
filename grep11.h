/*
Copyright IBM Corp. All Rights Reserved.
SPDX-License-Identifier: Apache-2.0
*/

#ifndef _GREP11_H_
#define _GREP11_H_ 1

#if !defined(CKR_VENDOR_DEFINED)
#error "We need CKR_VENDOR_DEFINED type from <pkcs11.h>, please include before this file."
#endif

#define CKR_VENDOR_DEFINED_GREP11        CKR_VENDOR_DEFINED + 0x40000
#define CKR_IBM_GREP11_NOT_AUTHENTICATED CKR_VENDOR_DEFINED_GREP11 + 0x01
#define CKR_IBM_GREP11_CANNOT_UNMARSHAL  CKR_VENDOR_DEFINED_GREP11 + 0x02
#define CKR_IBM_GREP11_CANNOT_MARSHAL    CKR_VENDOR_DEFINED_GREP11 + 0x03
#define CKR_IBM_GREP11_CONFLICT          CKR_VENDOR_DEFINED_GREP11 + 0x04
#define CKR_IBM_GREP11_DBINTERNAL        CKR_VENDOR_DEFINED_GREP11 + 0x05
#define CKR_IBM_GREP11_MISSING           CKR_VENDOR_DEFINED_GREP11 + 0x06
#define CKR_IBM_GREP11_REPLAY            CKR_VENDOR_DEFINED_GREP11 + 0x07

#define CKA_VENDOR_DEFINED_GREP11        CKA_VENDOR_DEFINED + 0x40000
#define CKA_GREP11_TOKEN_LABEL           CKA_VENDOR_DEFINED_GREP11 + 0x01
#define CKA_GREP11_WKID                  CKA_VENDOR_DEFINED_GREP11 + 0x02
#define CKA_GREP11_KEYSTORE_PASSWORD     CKA_VENDOR_DEFINED_GREP11 + 0x03
#define CKA_GREP11_KEYBLOB_HAS_ROTATION  CKA_VENDOR_DEFINED_GREP11 + 0x04
#define CKA_GREP11_NEXTWKID              CKA_VENDOR_DEFINED_GREP11 + 0x05
#endif
