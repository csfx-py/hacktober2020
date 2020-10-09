from envs import env
import psycopg2
import sys

try:
    query1 = """select * from users"""

    connection= psycopg2.connect(database="your_db_name", user = "your_user", password = "your_password", host = "db_address", port = "db_port")
    print ("Connection to DB is successful..")
    cursor = connection.cursor()
    print ("Executing query...")
    outputquery = "COPY ({0}) TO STDOUT WITH CSV HEADER".format(query1)
    print ("Query execution success.")
    print("Creating CSV file...")
    with open('users.csv', 'w') as f:
     cursor.copy_expert(outputquery, f)
     print("CSV file created successful.")



except (Exception, psycopg2.Error) as error :
    print ("Error while fetching data from PostgreSQL", error)

finally:
    #closing database connection.
    if(connection):
        print("Closing Database Connection...")
        cursor.close()
        connection.close()
        print("Database Connection is closed.")
