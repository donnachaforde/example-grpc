# README - example-grpc

A minimalist gRPC/C++ example on Windows, based off of the [official gRPC examples](https://github.com/grpc/grpc/tree/master/examples)

## Motivation
This is a _bare-bones_ implementation of the basic client/server "Hello World!" C++ example, which is published in the [gRPC C++ examples](https://github.com/grpc/grpc/tree/master/examples/cpp/helloworld) section on GitHub. It's a minimalist version, stripped down to its most basic constructs with minor changes to naming conventions .It also cleanly compiles in both `Debug` and `Release` configurations in the Visual Studio IDE. 


## Requirements
* gRPC for Windows
* Visual Studio 2022

## Build Instructions

### Install gRPC for C++

Currently, there is no installer for gRPC on Windows for C++ and you are required to build from source. Take a read of their [build instructions on GitHub](https://github.com/grpc/grpc/blob/master/BUILDING.md). It's also worth reading the [Quick Start Guide](https://grpc.io/docs/languages/cpp/quickstart/) on the official https://grpc.io website, though IMHO the guide is primarily aimed at macOS & Linux users. 

I'd advise you to study these guides as the build for Windows is not so straightforward. There is support for `vcpkg` though I opted to build from scratch. I had to fiddle around with the release and debug installs to get the full complement of libs needed to cleanly build for both configurations. 

### Prepare your build environment

* Ensure you have declared a `%GRPC_HOME%` environment variable pointing at the location of your gRPC install. 
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