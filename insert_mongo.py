from pymongo import MongoClient

try:
	myclient = MongoClient("mongodb://localhost:27017/")
	print("Connected successfully!!!")
except:
	print("Could not connect to MongoDB")
db = myclient["mydatabase"]
mycollection = db["students2"]
student_rec1 = {
		"name":"John Smith",
		"rollno":34,
		"address":"47 North Street Delhi"
		}
student_rec2 = {
		"name":"Max Earl",
		"rollno":56,
		"address":"23 Park Street Delhi"
		}

student_id1 = mycollection.insert_one(student_rec1)
student_id2 = mycollection.insert_one(student_rec2)

print("Data inserted with student ids",student_id1," ",student_id2)
cursor = mycollection.find()
for record in cursor:
	print(record)
	
