import pymongo

myclient = pymongo.MongoClient('mongodb://localhost:27017/')

mydb = myclient['mydatabase']

collist = mydb.list_collection_names()
if "customers" in collist:
  print("The collection exists.")
