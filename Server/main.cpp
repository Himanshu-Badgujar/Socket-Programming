#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

int main()
{
    // Step 1 - Create a socket for the server
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        perror("Socket setup failed");
        return 1;
    }
    else
    {
        cout << "Socket setup successful!" << endl;
    }

    // Step 2 - Configure the server address
    sockaddr_in serverService{};
    serverService.sin_family = AF_INET;
    serverService.sin_port = htons(55555);
    serverService.sin_addr.s_addr = INADDR_ANY; // Use INADDR_ANY for any available interface

    // Step 3 - Bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr *)&serverService, sizeof(serverService)) == -1)
    {
        perror("Binding process failed");
        close(serverSocket);
        return 1;
    }
    else
    {
        cout << "Binding process successful!" << endl;
    }

    // Step 4 - Listen for incoming connections
    if (listen(serverSocket, 1) == -1)
    {
        perror("Listening process failed");
        close(serverSocket);
        return 1;
    }
    else
    {
        cout << "Waiting for connections..." << endl;
    }

    // Step 5 - Accept a connection from a client
    int acceptSocket = accept(serverSocket, nullptr, nullptr);
    if (acceptSocket == -1)
    {
        perror("Failed to accept connection");
        close(serverSocket);
        return 1;
    }
    else
    {
        cout << "Connection accepted successfully!" << endl;

        // Close the accepted socket and the server socket when done
        close(acceptSocket);
        close(serverSocket);
    }

    return 0;
}
