# scaling-fishstick

A simple learning project to better understand how Wireshark works and how it can be customised to detect specific protocol packets such as MongoDB Wire Protocol packets. This can come in handy when detect suspicious network activity such as DDoS Attacks. 

For example, in DDOS Attacks, a massive number of packets with the filter "tcp.flags.syn == 1 and tcp.flags.ack == 0" can be seen on the wireshark GUI. This indicates a high number of requests sent to server with no replies/acknowledgements(tcp.flags.ack) from the server.

## Running project locally

### 1. Start wireshark
Start wireshark and select "Loopback lo" for network interface. This means only network packets that are sent to the machine itself (localhost) is detected.

### 2. Adding Lua Script
Select "Wireshark" -> "About Wireshark" -> "Folders" -> "Personal Lua Plugins". This states the correct folder to place lua custom script. Place the lua custom script "mongodb.lua" in the folder stated.  
![alt text](https://github.com/cyberbeam524/scaling-fishstick/blob/main/images/lua_scripts_folder.jpg)

### 3. Reloading Lua Plugin
Reload the lua plugin by clicking
![alt text](https://github.com/cyberbeam524/scaling-fishstick/blob/main/images/reload_plugin.jpg)

### 4. Viewing New Protocol Dissector
By selecting "Analyse" -> "Enable Protocols", you should be able to search for the newly loaded protocol "MONGODB" with description "MongoDB Protocol2". 
![alt text](https://github.com/cyberbeam524/scaling-fishstick/blob/main/images/enable_protocols.jpg)

### 5. Viewing Filtered Packets
Similarly, in the main GUI, you should be able to search for the MONGODB packets from port 27017 detected by the custom lua script.
![alt text](https://github.com/cyberbeam524/scaling-fishstick/blob/main/images/mongodb_packets.jpg)

To trigger some mongodb packets to be sent, enter this command in terminal:
```
python insert_mongo.py
```

### 6. Viewing Packet's Decoded Buffer
Double click on a row and you should be able to see the details of that packet as described by the custom lua script.
![alt text](https://github.com/cyberbeam524/scaling-fishstick/blob/main/images/detailed_packets.jpg)


## Decoding message with custom lua script

mongodb.lua - Sample lua script for decoding Mongodb message packets sniffed from port 27017.

### How custom decoding of packets work: 

The lua script decodes the packet by checking the buffer slice and converting it to a signed integer (int32) data type. For instance, on line 18, from index 0 to 4 lies i32 number for the message length of the packet. Similarly, from index 4 to 8 lies i32 number for the request id of the packet.

![alt text](https://github.com/cyberbeam524/scaling-fishstick/blob/main/images/buffer_reading.jpg)


### Useful resources:
https://engrsalmanshaikh.wordpress.com/2014/12/09/network-packet-sniffer-c/
http://tonylukasavage.com/blog/2010/11/17/packet-capture-with-c----amp--linux/
https://github.com/mongodb/mongo-cxx-driver/blob/master/examples/mongocxx/tutorial.cpp
https://www.mongodb.com/docs/manual/reference/mongodb-wire-protocol/
https://hevodata.com/learn/mongodb-python-insertion/
