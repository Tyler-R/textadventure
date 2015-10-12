#include "Session.h"

Session::Session(tcp::socket socket) : socket(std::move(socket)) {

}

Session::~Session() {
}

void Session::listenForCommands() {
    auto self(shared_from_this());
    Command *command = new Command();

    socket.async_read_some(boost::asio::buffer(command->buffer, MAX_COMMAND_LENGTH),
        [this, self, command](boost::system::error_code errorCode, std::size_t length) {
            if(!errorCode) {
                // handle command
                command->length = length;
                addCommandToQueue(*command);
            } else {
                //handle client disconnecting
                std::cout << "client disconnected" << std::endl;
                return;
            }

            listenForCommands();
        }
    );
}

void Session::addCommandToQueue(Command command) {
    commandBacklog.push(command);
}

std::string Session::getNextCommand() {
    if(commandBacklog.size() > 0) {
        auto command = commandBacklog.front();
        commandBacklog.pop();

        std::string data = command.buffer;
        data = "---" + data.substr(0, command.length);

        return data;
    } else {
        return "";
    }
}

void Session::sendMessage(std::string message) {

    boost::system::error_code error;
    size_t bitesWritten = boost::asio::write(socket, boost::asio::buffer(message), boost::asio::transfer_all(), error);

    if(error) {
        isAlive = false;
        throw boost::system::system_error(error);
    }
}