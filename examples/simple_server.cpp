/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file is part of zmqpp.
 * Copyright (c) 2011-2015 Contributors as noted in the AUTHORS file.
 */

/* Compile
 sudo make
*/

#include <cassert>
#include <iostream>
#include <thread>
#include <string>
#include <zmqpp/zmqpp.hpp>

// assign ipc to /tmp/ipc_test
const std::string IPC_ENDPOINT = "ipc://test.pipe";

namespace
{
  void overTCPSend(uint64_t numMessages, std::string const& data)
  {
    const std::string endpoint = "tcp://localhost:4242";

    // initialize the 0MQ context
    zmqpp::context context;

    // generate a push socket
    zmqpp::socket_type type = zmqpp::socket_type::push;
    zmqpp::socket socket (context, type);

    // open the connection
    std::cout << "Opening connection to " << endpoint << "..." << std::endl;
    socket.connect(endpoint);

    // send a message
    std::cout << "Sending messages: " << std::to_string(numMessages) << std::endl;

    auto start = std::chrono::system_clock::now();
    for (auto i = 0u; i < numMessages; i++)
    {
      zmqpp::message message;
      message << data;
      // vs 
      // packet.add_raw(data.data(), data.size());
      // compose a message from a string and a number
      // message << "Test" << i;
      socket.send(message);
    }
    auto end = std::chrono::system_clock::now();
    std::cout << "Time to send: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << "(ms)\n";  
    std::cout << "Finished." << std::endl;
  }

  void overInproc(uint64_t numMessages, std::string const& data)
  {
    std::cout << "Building inproc test..." << std::endl;
    // initialize the 0MQ context
    zmqpp::context context;

    std::string inprocAddress1("inproc://endpoint_1");

    // isDoneFut.wait();
    auto send = [&rCtx = context, inprocAddress1, numMessages, &data](){
      zmqpp::socket socket(rCtx, zmqpp::socket_type::push);
      auto rc = zmq_connect(socket, inprocAddress1.c_str());
      assert(rc == 0);
      // send data
      std::cout << "Sending messages: " << std::to_string(numMessages) << std::endl;

      auto start = std::chrono::system_clock::now();
      for (auto i = 0u; i < numMessages; i++)
      {
        zmqpp::message message;
        message << data;
        // vs 
        // packet.add_raw(data.data(), data.size());

        // compose a message from a string and a number
        // message << "Test" << i;
        socket.send(message);
      }
      auto end = std::chrono::system_clock::now();
      std::cout << "Time to send: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << "(ms)\n";
    };

    std::thread sendThread(send);

    // generate a recieve socket
    zmqpp::socket socket(context, zmqpp::socket_type::pull);
    socket.bind(inprocAddress1);
    // recieve data
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
    std::cout << "Time to receive: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << "(ms)\n";

    sendThread.join();
  }

  void overIPCServer(uint64_t numMessages)
  {
     //  Prepare our context and socket
    zmqpp::context context;
    zmqpp::socket socket (context, zmqpp::socket_type::push);
    // zmqpp::socket socket (context, zmqpp::socket_type::rep);
    //socket.bind ("tcp://*:5555");
    socket.bind(IPC_ENDPOINT);

    // while (true) // rep only
    for (auto i = 0u; i < numMessages; i++)
    {
      // zmqpp::message request;

      // std::cout << "waiting to recieve" << std::endl;
      //  Wait for next request from client
      // socket.receive(request);
      // std::string data;
      // request >> data;
      // std::cout << "Received: " << data << std::endl;

      //  Do some 'work'
      // std::this_thread::sleep_for(std::chrono::seconds(1));

      // std::cout << "sending reply msg" << std::endl;
      //  Send reply signal back to client
      zmqpp::message msg;
      msg << "confirm";
      socket.send(msg);
    }
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

  // if there is any other flag or argument run of inproc
  if (input1 == "-ipc")
  {
    overIPCServer(numMessages);
  }
  else if (input1 == "-inproc")
  {
    overInproc(numMessages, data);
  }
  else if (input1 == "-tcp")
  {
    overTCPSend(numMessages, data);
  }
  else 
  {
    std::cout << "No protocol select please select a type(-tcp, -ipc, -inproc) \n";
  }

  return 0;
}
