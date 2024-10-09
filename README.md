# Overview

This repository contains files that collectively form the basis of the Enterprise PKCS #11 over gRPC (GREP11) API and allow for communication with server intances created with the **IBM Cloud Hyper Protect Crypto Services**  offering. For more information regarding this service please review the [IBM Cloud Hyper Protect Services documentation](https://cloud.ibm.com/docs/services/hs-crypto?topic=hs-crypto-get-started).

In addition, links are provided to repositories that contain GREP11 code examples for various languages. Currently, respositories exist for Golang and JavaScript.

# GREP11 API

GREP11 is derived from Enterprise PKCS #11 (EP11) over gRPC and is based on the PKCS #11 specification. Links to the hierarchy of specifications that comprise the GREP11 API are provided below.

## Specification Links
* [PKCS #11 Base Specification](http://docs.oasis-open.org/pkcs11/pkcs11-base/v2.40/pkcs11-base-v2.40.html)
* [PKCS #11 Current Mechanisms Specification](http://docs.oasis-open.org/pkcs11/pkcs11-curr/v2.40/pkcs11-curr-v2.40.html)
* [Enterprise PKCS #11 Principles of Operation](#ep11-principles-of-operation)
* [GREP11 API](https://cloud.ibm.com/docs/hs-crypto?topic=hs-crypto-grep11-api-ref)

## gRPC Protobuf Details
The `server.proto` and `errors.proto` files contain protobuf source code that defines a gRPC service called Crypto. The Crypto service is a set of gRPC methods that constitute the GREP11 API. Each of the gRPC methods defined in the Crypto service is associated with an input (request) protobuf message and an output (response) protobuf message.

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

* [Golang examples](https://github.com/IBM-Cloud/hpcs-grep11-go)
* [JavaScript examples](https://github.com/IBM-Cloud/hpcs-grep11-js)

## EP11 Principles of Operation

For those that would like to have a low-level understanding of EP11, the EP11 Principles of Operation are provided
in the "Enterprise PKCS#11 (EP11) Library structure" pdf document.

The following steps outline how to obtain a copy of this document:
1. Go to https://www.ibm.com/resources/mrs/assets?source=ibm-zesp&lang=en_US. Use your IBMid and password to login.
2. Click the "I agree" checkbox and then click "I Confirm".
3. Click the "Download" link to the right of "IBM Z EP11 Support Program files".
4. Select the directory where you would like the zip file to be downloaded and save.
5. Unzip the support program zip file.
6. "cd" to the the unzipped directory.
7. Open the "ep11-structure.pdf" document to view the EP11 Principles of Operation

There is a supplemental document called "ep11-wire.txt" that contains additional information on EP11.