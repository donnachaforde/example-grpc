/*
 * main.cxx - gRPC client
 * 
 * A simplified implementation of the gRPC C++ example - Hello World. 
 * 
 * See original https://github.com/grpc/grpc/tree/master/examples/cpp/helloworld for credits, etc. 
 * 
 * 
 */
 

// std C++
#include <string>


// grpc
#pragma warning( disable : 4251 ) // Ignore dll-interface warnings
#include <grpcpp/grpcpp.h>

// generated stubs
#include "../generated/helloworld.grpc.pb.h"
using namespace helloworld;

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
//using namespace grpc;



int main(int argc, char* argv[], char* env[])
{
	// initialize a connection
	std::string strTargetEndpoint = "localhost:500052";
	std::shared_ptr<Channel> channel = grpc::CreateChannel(strTargetEndpoint, grpc::InsecureChannelCredentials());
	std::unique_ptr<Greeter::Stub> stub_ = Greeter::NewStub(channel);

	// create a request, response and a context
	HelloRequest request; 
	request.set_name("Fred");

	HelloResponse response;

	ClientContext clientContext;

	// invoke the RPC
	Status status = stub_->execute(&clientContext, request, &response);

	if (status.ok())
	{
		std::cout << "Response:" << response.message() << std::endl;
	}
	else
	{
		std::cerr << "ERROR!" << std::endl;
	}
	

	return 0;
}