#include <iostream>
#include <winsock2.h> // Pa compilar desde la consola se usa cd C:\Users\jdecr\Desktop\TheFuture\Attempt1> g++ Server.cpp -o Server -lws2_32

int main() {

    // 1. wake up winsock
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 2. create the socket
    SOCKET server = socket(AF_INET, SOCK_STREAM, 0);

    // 3. give it a port number
    sockaddr_in addr;
    addr.sin_family      = AF_INET;
    addr.sin_port        = htons(9000);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(server, (sockaddr*)&addr, sizeof(addr));

    // 4. wait for someone to connect
    listen(server, 1);
    std::cout << "listening on port 9000...\n";
    SOCKET client = accept(server, nullptr, nullptr);
    std::cout << "someone connected!\n"<<endl;
    

    // 5. hang up
    closesocket(client);
    closesocket(server);
    WSACleanup();
	std::cin.get(); // Enter to close
    return 0;
}