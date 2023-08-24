import socket  
import sys
# define the test message types
MESSAGE1 = "0101" # "Is the service up?"
MESSAGE2 = "0102" # "Other question?"
MESSAGE3 = "0201" # "Yes, the service is up"
MESSAGE4 = "0202" # "No, the service is down"
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("Socket has successfully created")
except socket.error as err:
    print("socket creation has failed with error %s" % (err))

port = 12345
try:
    # host_ip = socket.gethostbyname('192.168.1.5') # server ip address or host name
    # host_ip = socket.gethostbyname('0.0.0.0') # server ip address or host name
    host_ip = socket.gethostbyname('10.124.11.242') # server ip address or host name
    print("tried getting host_ip")
except socket.gaierror:
    # it fails to resolve the host name
    print("there has been an error resolving the host")
    sys.exit()
s.connect((host_ip, port))
print("s.connect((host_ip, port))")
s.send(bytes.fromhex(MESSAGE1)) # it will test MESSAGE1
print("s.send(bytes.fromhex(MESSAGE1)) ")
s.close()
print("s.close()")