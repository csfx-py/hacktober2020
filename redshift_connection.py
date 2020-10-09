import psycopg2

try:
    # connect to the database
    print("Connecting to Redshift..")
    conn = psycopg2.connect(host="db_address", port="db_port", dbname="your_database_name", user="your_username", password="your_password")
    print("Connection to Redshift success.")

    # cursor object is used to interact with the database
    cur = conn.cursor()

    # open the csv file using python standard file I/O
    csv_file_name = 'your_file_name.csv'
    sql = """COPY schema_name.table_name FROM 's3://your_bucket_address/your_file_name.csv' credentials 
    'aws_iam_role=arn:aws:iam::your_12-digit_account_id:role/your-role-name' delimiter ',' IGNOREHEADER 1 """
    print("Running Query : " + sql)
    cur.copy_expert(sql, open(csv_file_name, "r"))
    print("Query successfully executed..")
except (Exception, psycopg2.Error) as error:
    print("Error while fetching data from Redshift ", error)
    exit()

finally:
    # closing database connection.
    if (conn):
        # Commit Changes
        conn.commit()
        cur.close()
        conn.close()
        print("Redshift connection is closed")
