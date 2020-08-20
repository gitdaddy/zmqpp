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

using namespace std;

int main(int argc, char *argv[]) {
  const string endpoint = "tcp://localhost:4242";

  // initialize the 0MQ context
  zmqpp::context context;

  // generate a push socket
  zmqpp::socket_type type = zmqpp::socket_type::push;
  zmqpp::socket socket (context, type);

  // open the connection
  cout << "Opening connection to " << endpoint << "..." << endl;
  socket.connect(endpoint);

  // send a message
  cout << "Sending messages..." << endl;
  auto start = std::chrono::system_clock::now();
  for (auto i = 0u; i < 10000; i++)
  {
    zmqpp::message message;
    // compose a message from a string and a number
    message << "Test" << i;
    socket.send(message);
  }
  auto end = std::chrono::system_clock::now();
  std::cout << "Time to send: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
          << "(ms)\n";  
  cout << "Finished." << endl;
}
