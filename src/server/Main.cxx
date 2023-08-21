/*
 * main.cxx - gRPC server
 *
 * A simplified implementation of the gRPC C++ example - Hello World.
 *
 * See original https://github.com/grpc/grpc/tree/master/examples/cpp/helloworld for credits, etc.
 *
 *
 */


// std C++
#include <string>
#include <iostream>

using namespace std; 


// grpc
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

using namespace grpc;

// generated stubs
#include "../generated/helloworld.grpc.pb.h"
using namespace helloworld;



/*
 * The implementation of the service, defined in IDL/Proto
 * 
 */
class GreeterServiceImpl final : public Greeter::Service 
{
    Status execute(ServerContext* context, const HelloRequest* request, HelloResponse* reply) override 
    {
        cout << "Request received from name=" << request->name() << endl;

        // extract the name provided in the request and set it in the response
        reply->set_message("Hello " + request->name());
        
        return Status::OK;
    }
};




int main(int argc, char* argv[], char* envp[])
{
    cout << "Initializing gRPC server..." << endl; 

    // boiler-plate gRPC initialization - see function comments for details
    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();

    // we use the server builder to specify the listening port
    ServerBuilder serverBuilder;
    string strServerEndpoint = "localhost:500052";
    serverBuilder.AddListeningPort(strServerEndpoint, grpc::InsecureServerCredentials());

    // then, we use it to register our implementation of the service
    GreeterServiceImpl greeterService;
    serverBuilder.RegisterService(&greeterService);

    // initialize and create the server, then wait for calls
    std::unique_ptr<Server> server = serverBuilder.BuildAndStart();

    cout << "Listening..." << endl;
    server->Wait();
	
	return 0;
}


