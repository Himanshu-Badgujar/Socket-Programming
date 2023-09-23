#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main()
{
    // Step 1: Create a socket for the client
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
    {
        cout << "Socket setup failed." << endl;
        return 1;
    }
    else
    {
        cout << "Socket setup successful!" << endl;
    }

    // Step 2: Set up server information (IP address and port) to connect to
    sockaddr_in clientService{};
    clientService.sin_family = AF_INET;
    clientService.sin_port = htons(55555);
    inet_pton(AF_INET, "127.0.0.1", &(clientService.sin_addr));

    // Step 3: Attempt to establish a connection to the server
    if (connect(clientSocket, (struct sockaddr*)&clientService, sizeof(clientService)) == -1)
    {
        cout << "Connecting process failed." << endl;
        close(clientSocket);
        return 1;
    }
    else
    {
        cout << "Connection established successfully!" << endl;
    }

    // Step 4: Close the client socket after the connection is established
    close(clientSocket);

    return 0;
}
