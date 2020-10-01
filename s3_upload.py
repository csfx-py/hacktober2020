from envs import env
import boto3
import os

#this script will keep your dir and sub-dir hierarchy on s3 same as local. 

def upload_files(path):
    session = boto3.Session(
        aws_access_key_id= env('aws_access_key_id'), #pass this varibale in your .bashrc file.
        aws_secret_access_key= env('aws_secret_access_key'), #pass this varibale in your .bashrc file.
        region_name= 'your_region_name' #ex:-ap-south-1
    )
    s3 = session.resource('s3')
    bucket = s3.Bucket('your_bucket_name')
 
    for subdir, dirs, files in os.walk(path):
        for file in files:
            full_path = os.path.join(subdir, file)
            with open(full_path, 'rb') as data: # rb will empty your s3 bucket folder before upload check aws documentation.
                bucket.put_object(Key=full_path[len(path)+1:], Body=data)
 
if __name__ == "__main__":
    upload_files('/home/user/some_dir')
