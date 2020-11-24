/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file is part of zmqpp.
 * Copyright (c) 2011-2015 Contributors as noted in the AUTHORS file.
 */

#include <zmqpp/zmqpp.hpp>
#include <string>
#include <iostream>
#include <chrono>

// assign ipc to /tmp/ipc_test1
const std::string IPC_ENDPOINT = "ipc:///tmp/ipc_test1";

namespace
{
  void overTCPReceive(uint64_t numMessages)
  {
    const std::string endpoint = "tcp://*:4242";

    // initialize the 0MQ context
    zmqpp::context context;

    // generate a pull socket
    zmqpp::socket socket (context, zmqpp::socket_type::pull);

    // bind to the socket
    std::cout << "Binding tcp endpoint to " << endpoint << "..." << std::endl;
    socket.bind(endpoint);

    // receive the message
    std::cout << "Receiving messages: " << std::to_string(numMessages) << std::endl;
    auto start = std::chrono::system_clock::now();
    bool firstLoop = true;
    for (auto i = 0u; i < numMessages; i++)
    {
      zmqpp::message message;
      // decompose the message
      socket.receive(message);

      if (firstLoop)
      {
        firstLoop = false;
        start = std::chrono::system_clock::now();
      }

      // std::string text;
      // int number;
      // message >> text >> number;
      // std::cout << "Received text:\"" << text << "\" and a number: " << number;
    }
    auto end = std::chrono::system_clock::now();
    std::cout << "Time to recieve: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << "(ms)\n";
  }

  void overIPCClient(uint64_t numMessages, std::string const& data)
{
    zmqpp::context context;
    zmqpp::socket socket (context, zmqpp::socket_type::req);
    //socket.bind ("tcp://*:5555");
    socket.connect(IPC_ENDPOINT);

    auto start = std::chrono::system_clock::now();
    bool firstLoop = true;

    for (auto i = 0u; i < numMessages; i++)
    {
      zmqpp::message packet;
      packet << data;
      // vs 
      // packet.add_raw(data.data(), data.size());
      
      // printf ("Sending packet %d…\n", i);
      socket.send(packet); // options?

      if (firstLoop)
      {
        firstLoop = false;
        start = std::chrono::system_clock::now();
      }

      std::cout << " " << i;

      //  receive reply back to server
      zmqpp::message reply;
      // std::cout << "waiting for reply\n";
      socket.receive(reply);
      std::string data;
      reply >> data;
      // std::cout << "Reply data: " << data << std::endl;
    }
    socket.close();

    auto end = std::chrono::system_clock::now();
    std::cout << "Time to recieve: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << "(ms)\n";
  }
}

int main(int argc, char *argv[]) {
  // .out type numMessages packetSizeBytes
  if (argc != 4)
  {
    std::cout << "usage: a.out protocolType numMessages packetSizeBytes\n";
    return 0;
  }

  std::string input1, input2, input3;
  input1 = std::string(argv[1]);
  input2 = std::string(argv[2]);
  input3 = std::string(argv[3]);

  std::cout << "inputs:" << input1 << " " << input2 << " " << input3 << std::endl;

  uint64_t numMessages = std::stoi(input2);
  uint64_t packetSize = std::stoi(input3);

  // std::string data(std::stoi(input3), "*");
  std::string data;
  for (auto i = 0u; i < packetSize; i++)
    data += "*";

  if (input1 == "-tcp")
  {
    overTCPReceive(numMessages);
  }
  else if (input1 == "-ipc")
  {
    overIPCClient(numMessages, data);
  }
  else 
  {
    std::cout << "No protocol select please select a type(-tcp, -ipc) \n";
  }


  return 0;
}
