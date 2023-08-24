one: 
	gcc -c raw_packets.cpp -std=c++11 -o one.out
	./one.out
	
two:
	g++ -std=c++11 -o ./hey ./hello.cpp
	./hey

three:
	g++ -std=c++11 -o ./hey ./raw_packets.cpp
	./hey

four:
	g++ -std=c++11 -o ./hey -v ./payroll.cpp
	./hey

five:
	g++ -std=c++11 -o ./hey -/Library/Developer/CommandLineTools/usr/lib/clang/14.0.3/include ./payroll.cpp
	./hey

six:
	g++ -std=c++11 -o ./hey -v ./bookshop.cpp
	./hey

boost:
	g++ -std=c++11 -o ./hey -v ./boost.cpp
	./hey

mongo:
	g++ --std=c++11 mongo.cpp $(pkg-config --cflags --libs libmongocxx)

mongo2:
	g++ --std=c++11 mongo.cpp -I/usr/local/include/bsoncxx/v_noabi

mongo3:
	g++ --std=c++11 -o ./mongo mongo.cpp -I/usr/local/include/mongocxx/v_noabi -I/usr/local/include/bsoncxx/v_noabi
	./mongo

mongo4:
	g++ --std=c++11 mongo.cpp -I/usr/local/include

mongo5:
	g++ --std=c++11 -o ./output/mongo mongo.cpp -I/usr/local/include/mongocxx/v_noabi \
	-I/usr/local/include/bsoncxx/v_noabi \
	-L/usr/local/lib -lmongocxx -lbsoncxx
	./output/mongo