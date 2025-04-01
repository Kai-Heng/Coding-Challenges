#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

class Message {
private:
    string msg;
    int order;
    static int curr_order;
public: 
    Message():msg(""), order(0){}
    Message(const string &text):msg(text), order(++curr_order){}
    
    const string& get_text() {
        return msg;
    }
    
    bool operator<(const Message& other) const {
        return order < other.order;
    }

};

int Message::curr_order = 0;  // Initialize static counter

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        return Message(text);
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        std::random_device rd;
        std::mt19937 g(rd());
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        shuffle(messages.begin(), messages.end(),g);         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
