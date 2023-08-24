from pymongo import MongoClient

try:
	myclient = MongoClient("mongodb://localhost:27017/")
	print("Connected successfully!!!")
except:
	print("Could not connect to MongoDB")

db = myclient["mydatabase"]

mycollection = db["students2"]

cursor = mycollection.find()
for record in cursor:
	print(record)
	
