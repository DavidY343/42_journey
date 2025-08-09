#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <sys/socket.h>

class Client
{
    public:
        Client(int fd, const std::string &hostname);
        Client();
        ~Client();

        int getFd() const;
        const std::string& getNickname() const;
        const std::string& getUsername() const;
        const std::string& getRealname() const;
        const std::string& getHostname() const;
        const std::string& getInputBuffer() const;

        void setNickname(const std::string& nickname);
        void setUsername(const std::string& username);
        void setRealname(const std::string& realname);
        void setHostname(const std::string& hostname);
        void appendToBuffer(const std::string& data);
        void clearBuffer();

        bool isRegistered() const;
        void setRegistered(bool value);

        bool isAuthenticated() const;
        void setAuthenticated(bool value);

        std::string getPrefix();
        void Welcome();
        void sendMessage(const std::string& msg);

    private:
        int _fd;
        std::string _nickname;
        std::string _username;
        std::string _hostname;
        std::string _inputBuffer;
        bool _registered;
        bool _authenticated;
};

#endif
