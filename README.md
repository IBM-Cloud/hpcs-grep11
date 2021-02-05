# Overview

This repository contains files that collectively form the basis of the Enterprise PKCS #11 over gRPC (GREP11) API and allow for communication with server intances created with the **IBM Cloud Hyper Protect Crypto Services**  offering. For more information regarding this service please review the [IBM Cloud Hyper Protect Services documentation](https://cloud.ibm.com/docs/services/hs-crypto?topic=hs-crypto-get-started).

In addition, links are provided to repositories that contain GREP11 code examples for various languages.  Currently, respositories exist for Go and JavaScript.  Other language example repositories will be added in the future.


# GREP11 API

GREP11 is derived from Enterprise PKCS #11 (EP11) over gRPC and is based on the PKCS #11 specification. Links to the hierarchy of specifications that comprise the GREP11 API are provided below.

## Specification Links
* [PKCS #11 Base Specification](http://docs.oasis-open.org/pkcs11/pkcs11-base/v2.40/pkcs11-base-v2.40.html)
* [PKCS #11 Current Mechanisms Specification](http://docs.oasis-open.org/pkcs11/pkcs11-curr/v2.40/pkcs11-curr-v2.40.html)
* [Enterprise PKCS #11 Specification](http://public.dhe.ibm.com/security/cryptocards/pciecc4/EP11/docs/ep11-structure.pdf)
* [GREP11 API](https://cloud.ibm.com/docs/hs-crypto?topic=hs-crypto-grep11-api-ref)

## gRPC Protobuf Details
The `server.proto` file contains protobuf source code that defines a gRPC service called Crypto. The Crypto service is a set of gRPC methods that constitute the GREP11 API.  Each of the gRPC methods defined in the Crypto service is associated with an input (request) protobuf message and an output (response) protobuf message.

As an example, the following statements show the GenerateKey GREP11 API method and its associated request and response message structures:

```
// GenerateKey Crypto service gRPC method
rpc GenerateKey(GenerateKeyRequest) returns (GenerateKeyResponse) {}

// GenerateKey request message
message GenerateKeyRequest {
	Mechanism Mech = 1;
	map<uint64,AttributeValue> Template = 6;
}

// GenerateKey response message
message GenerateKeyResponse {
	bytes KeyBytes = 4;
	bytes CheckSum = 5;
	KeyBlob Key = 7;
}

```

## C Header Files
The C header files in this repository contain PKCS #11 functions, data types, and functions defined in the PKCS #11 specification. A sample header file, `sample.h`, is provided and serves as the top level header file. Within `sample.h`, both the `grep11.h` and `ep11.h` header files are included which provide IBM extensions to PKCS #11. 

Since the GREP11 API is based on the PKCS #11 specification, the contents of the header files were used in conjunction with the `server.proto` file to create language specific files that can be used by GREP11 clients. With the files contained in this repository, it is possible to generate GREP11 API files for your favorite language.

## Code Examples
The following repositories contain language specific code examples that you can use to create your own GREP11 API applications:

* [Go examples](https://github.com/IBM-Cloud/hpcs-grep11-go)
* [JavaScript examples](https://github.com/ibm-developer/ibm-cloud-hyperprotectcrypto/tree/master/js)
