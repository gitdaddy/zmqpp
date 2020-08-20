/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file is part of zmqpp.
 * Copyright (c) 2011-2015 Contributors as noted in the AUTHORS file.
 */

#include <cassert>
#include <iostream>
#include <thread>
#include <string>
#include <zmqpp/zmqpp.hpp>

const uint64_t NUM_MESSAGES = 10000;

namespace 
{
  void overTCP()
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
    std::cout << "Receiving messages..." << std::endl;
    auto start = std::chrono::system_clock::now();
    bool firstLoop = true;
    for (auto i = 0u; i < NUM_MESSAGES; i++)
    {
      zmqpp::message message;
      // decompose the message 
      socket.receive(message);

      if (firstLoop)
      {
        firstLoop = false;
        start = std::chrono::system_clock::now();
      }

      std::string text;
      int number;
      message >> text >> number;
      // std::cout << "Received text:\"" << text << "\" and a number: " << number;
    }
    auto end = std::chrono::system_clock::now();
    std::cout << "Time to recieve: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << "(ms)\n";  
  }

  void overInproc()
  {
    std::cout << "Building inproc test..." << std::endl;
    // initialize the 0MQ context
    zmqpp::context context;

    std::string inprocAddress1("inproc://endpoint_1");
    
    // isDoneFut.wait();
    auto send = [&rCtx = context, inprocAddress1](){
      zmqpp::socket socket(rCtx, zmqpp::socket_type::push);
      auto rc = zmq_connect(socket, inprocAddress1.c_str());
      assert(rc == 0);
      // send data
      std::cout << "Sending messages..." << std::endl;
      auto start = std::chrono::system_clock::now();
      for (auto i = 0u; i < NUM_MESSAGES; i++)
      {
        zmqpp::message message;
        // compose a message from a string and a number
        message << "Test" << i;
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
    std::cout << "Receiving messages..." << std::endl;
    auto start = std::chrono::system_clock::now();
    bool firstLoop = true;
    for (auto i = 0u; i < NUM_MESSAGES; i++)
    {
      zmqpp::message message;
      // decompose the message 
      socket.receive(message);

      if (firstLoop)
      {
        firstLoop = false;
        start = std::chrono::system_clock::now();
      }

      std::string text;
      int number;
      message >> text >> number;
      // std::cout << "Received text:\"" << text << "\" and a number: " << number;
    }
    auto end = std::chrono::system_clock::now();
    std::cout << "Time to recieve: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << "(ms)\n";  

    sendThread.join();
  }
}

int main(int argc, char */*argv[]*/) {

  // if there is any other flag or argument run of inproc
  if (argc > 1)
  {
    overInproc();
  }
  else 
  {
    overTCP();
  }
  return 0;
}
