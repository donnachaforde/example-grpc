# README - example-grpc

A minimalist gRPC/C++ example on Windows, based off of the [official gRPC examples](https://github.com/grpc/grpc/tree/master/examples/cpp/helloworld).

## Requirements
* gRPC for Windows
* Visual Studio 2022

## Build Instructions

### Prepare your build environment

* Ensure you have declared a `GRPC_HOME` environment variable pointing at the location of your gRPC install. 
    * The stub code generation uses this env-var to find the `protoc` code generator.
    * Both the client and server projects reference the gRPC headers and libs needed to build the project from this path.

**Note:** The project cleanly builds both `Debug` and `Release` configurations (for x64 only) and requires that the `%GPRC_HOME%` location contain both versions of these libs. Specifically, it expects the `Debug` version of the gRPC libs to be located under `%GRPC_HOME%\debug`. Depending on how you've installed gRPC, you may need to take steps to modify your install (or change the project settings accordingly).

### gRPC Debug/Release Libraries
For the most part, the gRPC libraries (and their dependents) for `Debug` and `Release` share the same name (differing by location), except for the following, which use the naming convention of adding a 'd' to the library to indicate the 'debug' version:

* libprotobuf.lib -v- libprotobufd.lib
* libprotobuf-lite.lib -v- libprotobuf-lited.lib
* libprotoc.lib -v- libprotocd.lib

Further, two dependent libs use the same naming convention:

* zlib.lib -v- zlibd.lib
* zlibstatic.lib -v- zlibstaticd.lib

### Build & Test Steps

1. Open the `example-grpc.sln` Visual Studio solution file. 
2. Build all elements. (The solution will manage the order).
3. Launch a separate command-line terminal to run the server. 
4. Launch another, separate command-line terminal to execute the client. 
5. Observe the client/server communication. 