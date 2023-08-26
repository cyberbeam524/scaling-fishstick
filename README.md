# scaling-fishstick

Step 1: 
Start wireshark and select "Loopback lo" for network interface. This means only network packets that are sent to the machine itself (localhost) is detected.

Step 2:
Add the script mongodb_lua.py to lua scripts folder.

![alt text](https://github.com/cyberbeam524/scaling-fishstick/blob/main/images/Xnip2023-08-22_20-40-02.jpg)


```
python mongo.py
```

### Decoding message with custom lua script

mongodb copy.lua - Sample lua script for decoding Mongodb message packets sniffed from port 27017.

How custom descoding works: 

![alt text](https://github.com/cyberbeam524/scaling-fishstick/blob/main/images/Xnip2023-08-22_21-05-09.jpg)

The packets are decoded using the buffer spacing. For instance, on line 18, from index 0 to 4 lies i32 number for the message length of the packet. Similarly, from index 4 to 8 lies i32 number for the request id of the packet.



Ways of detecting attacks:



Useful resources:
https://engrsalmanshaikh.wordpress.com/2014/12/09/network-packet-sniffer-c/
http://tonylukasavage.com/blog/2010/11/17/packet-capture-with-c----amp--linux/
https://github.com/mongodb/mongo-cxx-driver/blob/master/examples/mongocxx/tutorial.cpp